#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clp.h"
#include "clpintf.h"
#include "pdl_gen.h"
#include "csm.h"
#include "eliproto.h"

#define TYPE_MASK      0x001F
#define BOOL           0x0001
#define INTVAL         0x0002
#define STRVAL         0x0004
#define USAGE          0x0008
#define TERM           0x0010

#define JOINED         0x0100
#define SPACED         0x0200
#define PLURAL         0x0400

typedef struct opt opt;
struct opt {
    CONST char *str;
    int flags;
    int *count;
    DefTableKey *key;
    DefTableKeyList *list;
};

DefTableKey CLP_InputFile = NoKey;
DefTableKey FileName = NoKey;
DefTableKey Fmodule = NoKey;
static int Fmodule_count = 0;
DefTableKey Generate = NoKey;
static int Generate_count = 0;
DefTableKey Header = NoKey;
static int Header_count = 0;
DefTableKey Include = NoKey;
static int Include_count = 0;
DefTableKeyList IncludeDirs = NULLDefTableKeyList;
DefTableKeyList IncludeFiles = NULLDefTableKeyList;
DefTableKey Integer8 = NoKey;
static int Integer8_count = 0;
DefTableKey Kernel = NoKey;
static int Kernel_count = 0;
DefTableKey ModuleFile = NoKey;
static int ModuleFile_count = 0;
DefTableKey ModuleUse = NoKey;
static int ModuleUse_count = 0;
DefTableKey Original = NoKey;
static int Original_count = 0;
DefTableKey Real8 = NoKey;
static int Real8_count = 0;
DefTableKey ScanLength = NoKey;
static int ScanLength_count = 0;
DefTableKey TransFile = NoKey;
static int TransFile_count = 0;
DefTableKey WarnLevel = NoKey;
static int WarnLevel_count = 0;
int FixedFormat = 0;
static int error_count = 0;

#define NUMOPTS 16

static opt opts[] = {
    { "-mF", STRVAL | JOINED, &Fmodule_count, &Fmodule, NULL },
    { "-generate", INTVAL | JOINED, &Generate_count, &Generate, NULL },
    { "-h", INTVAL | JOINED, &Header_count, &Header, NULL },
    { "-cF", STRVAL | JOINED, &Include_count, &Include, NULL },
    { "-I", STRVAL | PLURAL | JOINED, NULL, NULL, &IncludeDirs },
    { "-iF", STRVAL | PLURAL | JOINED, NULL, NULL, &IncludeFiles },
    { "-i8", INTVAL | JOINED, &Integer8_count, &Integer8, NULL },
    { "-kernel", INTVAL | JOINED, &Kernel_count, &Kernel, NULL },
    { "-module", INTVAL | JOINED, &ModuleFile_count, &ModuleFile, NULL },
    { "-use", INTVAL | JOINED, &ModuleUse_count, &ModuleUse, NULL },
    { "-o", STRVAL | JOINED, &Original_count, &Original, NULL },
    { "-r8", INTVAL | JOINED, &Real8_count, &Real8, NULL },
    { "-SL", INTVAL | JOINED, &ScanLength_count, &ScanLength, NULL },
    { "-lF", STRVAL | JOINED, &TransFile_count, &TransFile, NULL },
    { "-V", INTVAL | JOINED, &WarnLevel_count, &WarnLevel, NULL },
    { "-fixed", BOOL , &FixedFormat, NULL, NULL },
    { "dummy", 0, NULL, NULL, NULL }
};

static void
#ifdef PROTO_OK
clp_error (const char *str, const char *msg)
#else
clp_error (str, msg)
char *str, *msg;
#endif
{
  if (str == (char *) NULL)
    fprintf (stderr, "%s\n", msg);
  else
    fprintf (stderr, "%s %s\n", str, msg);
  error_count++;
}

static int
#ifdef PROTO_OK
clp_atos (char *str)
#else
clp_atos (str)
char *str;
#endif
{
  return stostr (str, strlen(str));
}

void
#ifdef PROTO_OK
clp_usage (char *prog)
#else
clp_usage (prog)
  char *prog;
#endif
{
  fprintf (stderr, "Usage: %s [options] parameters\n", prog);
  fprintf (stderr, "  Items marked with * may be repeated.\n");
  fprintf (stderr, "  Options:\n");
  fprintf (stderr, "    -mFstring    SMS module file name\n");
  fprintf (stderr, "    -generateint Output Language:  [0=ANSI-C, 1=CUDA]\n");
  fprintf (stderr, "    -hint        [0=FALSE, 1=TRUE] file type is an include file\n");
  fprintf (stderr, "    -cFstring    SMS include file name\n");
  fprintf (stderr, "    -Istring     Directories to search for included files*\n");
  fprintf (stderr, "    -iFstring    Included file(s) that are processed by PPP*\n");
  fprintf (stderr, "    -i8int       0=FALSE, 1=TRUE] treat integer declarations as integer*8\n");
  fprintf (stderr, "    -kernelint   [0=FALSE, 1=TRUE] generated file is a Kernel routine\n");
  fprintf (stderr, "    -moduleint   [0=FALSE, 1=TRUE] file is module\n");
  fprintf (stderr, "    -useint      [0=INCLUDE, 1=EXTERN] Strategy for handling module references\n");
  fprintf (stderr, "    -ostring     Original path and filename of input file\n");
  fprintf (stderr, "    -r8int       0=FALSE, 1=TRUE] promote real and complex variables to 8 bytes\n");
  fprintf (stderr, "    -SLint       Length Options: 72, 80\n");
  fprintf (stderr, "    -lFstring    Module file lookup table\n");
  fprintf (stderr, "    -Vint        Message Level [0=ERRORS, 1=ERRORS+WARNINGS (default), 2=ALL]\n");
  fprintf (stderr, "    -fixed       Select fixed input format\n");
  fprintf (stderr, "  Parameters:\n");
  fprintf (stderr, "    FileName     \n");
    exit (1);
}

void
#ifdef PROTO_OK
clp_init (int argc, char *argv[])
#else
clp_init (argc, argv)
int argc;
char *argv[];
#endif
{
  int i, j, p, t;
  DefTableKey k;
  opt *o;
  char *s;

  SetFileErr ("%p: cannot open %f for reading", 0);
  for (i = 1; i < argc; i++) {
    for (j = 0, o = opts; j < NUMOPTS; j++, o++)
      if (strncmp (o->str, argv[i], strlen (o->str)) == 0)
        break;
    if (j == NUMOPTS)
      break;
    s = argv[i] + strlen (o->str);
    if (o->flags & USAGE) {
      if (*s != '\0')
        clp_error (o->str, "must not have a value");
      clp_usage (argv[0]);
    } else if (o->flags & TERM) {
      if (*s != '\0')
        clp_error (o->str, "must not have a value");
      i++;
      break;
    } else {
      if (o->count != (int *) NULL)
        (*o->count)++;
      p = o->flags & PLURAL;
      if ((!p) && (*o->count > 1))
        clp_error (o->str, "can only be given once");
      t = o->flags & TYPE_MASK;
      switch (t) {
        case BOOL:
          if (*s != '\0')
            clp_error (o->str, "must not have a value");
          break;
        case INTVAL:
        case STRVAL: {
          if (o->flags & JOINED) {
            if (*s == '\0') {
              if (o->flags & SPACED) {
                if (i == argc - 1) {
                  clp_error (o->str, "must have a value");
                  continue;
                } else {
                  i++;
                  s = argv[i];
                }
              } else {
                clp_error (o->str, "must have a joined value");
                continue;
              }
            }
          } else if (o->flags & SPACED) {
            if (*s != '\0') {
              clp_error (o->str, "must not have a joined value");
              continue;
            }
            if (i == argc - 1) {
              clp_error (o->str, "must have a value");
              continue;
            } else {
              i++;
              s = argv[i];
            }
          }
          if (p) {
            DefTableKey k = NewKey ();
            switch (t) {
              case INTVAL:
                SetClpValue (k, atoi (s), 0);
                break;
              case STRVAL:
                SetClpValue (k, clp_atos (s), 0);
                break;
            }
            *o->list = AppElDefTableKeyList (*o->list, k);
          } else {
            *o->key = NewKey ();
            switch (t) {
              case INTVAL:
                SetClpValue (*o->key, atoi (s), 0);
                break;
              case STRVAL:
                SetClpValue (*o->key, clp_atos (s), 0);
                break;
            }
          }
        }
      }
    }
  }
  if (i < argc) {
    FileName = NewKey ();
    SetClpValue (FileName, clp_string (argv[i++]), 0);
    CLP_InputFile = FileName;
  }
  if ((i < argc) || (error_count > 0))
    clp_usage (argv[0]);
}
