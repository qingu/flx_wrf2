switch (CaseTbl[c = *p++]) {
case 0:	/* sentinel - probably EOB */
  if (c == '\0') {
    p = TokenStart = TokenEnd = auxNUL(TokenStart, 0);
    if (*p) extcode = NORETURN;
    else {
      p = TokenStart = TokenEnd = auxEOF(TokenStart, 0);
      if (*p) extcode = NORETURN;
      else { extcode = EOFTOKEN; EndOfText(p, 0, &extcode, v); }
    }
    goto done;
  } else {
    obstack_grow(Csm_obstk, "char '", 6);
    obstack_cchgrow(Csm_obstk, c);
    message(
      ERROR,
      (char *)obstack_copy0(Csm_obstk, "' is not a token", 16),
      0,
      &curpos);
    TokenEnd = p;
    continue;
  }
  
case 1:	/* space */
  while (scanTbl[c = *p++] & 1<<0) ;
  TokenEnd = p - 1;
  continue;
case 2:	/* tab */
  do { StartLine -= TABSIZE(p - StartLine); }
  while (scanTbl[c = *p++] & 1<<1);
  TokenEnd = p - 1;
  continue;
case 4:	/* carriage return */
  if (*p == '\n') { TokenEnd = p; continue; }
case 3:	/* newline */
  do { LineNum++; } while (scanTbl[c = *p++] & 1<<2);
  StartLine = (TokenEnd = p - 1) - 1;
  continue;

case 5:	/* Entered on:  A C H J-N P-Y a h j-n p-r t w-y */
	St_22:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 6:	/* Entered on: 0-9 */
	St_16:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 6){ /*  X x */
			goto St_57;}
		else if( scanTbl[c+0] & 1<< 7){ /*  P p */
			goto St_56;}
		else if( scanTbl[c+256] & 1<< 0){ /*  H h */
			goto St_55;}
		else if( scanTbl[c+256] & 1<< 1){ /*  E e */
		extcode = 24;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfint;
			goto St_54;}
		else if( scanTbl[c+256] & 1<< 2){ /*  D d */
		extcode = 24;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfint;
			goto St_53;}
		else if(c ==46) {			goto St_51;}
		else if(c ==32) {			goto St_50;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 24;
			mkfint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 7:	/* Entered on:  D F I b d f i o z */
	St_24:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_71;}
		else if(c ==95) {			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_68;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 8:	/* Entered on:  G g */
	St_26:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_73;}
		else if(c ==95) {			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_72;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 9:	/* Entered on:  " ' */
	St_5:
			TokenEnd=p=fstr(TokenStart, p-TokenStart);
			extcode = 23;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;

case 10:	/* Entered on: v */
	St_34:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  A-Z a-d f-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==101) {			goto St_83;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 11:	/* Entered on: u */
	St_33:
		if( scanTbl[(c= *p++)+256] & 1<< 4){ /*  A-Z a-m o-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==110) {			goto St_82;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 12:	/* Entered on: s */
	St_32:
		if( scanTbl[(c= *p++)+256] & 1<< 5){ /*  A-Z a-l n-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==109) {			goto St_81;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 13:	/* Entered on: e */
	St_31:
		if( scanTbl[(c= *p++)+256] & 1<< 6){ /*  A-M O-R T-Z a-m o-r t-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_73;}
		else if( scanTbl[c+256] & 1<< 7){ /*  N S n s */
			goto St_80;}
		else if(c ==95) {			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_72;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 14:	/* Entered on: c */
	St_30:
		if( scanTbl[(c= *p++)+512] & 1<< 0){ /*  A-Z a-n p-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==111) {			goto St_79;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 15:	/* Entered on: Z */
	St_28:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_71;}
		else if(c ==95) {			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==39) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_78;}
		else if(c ==34) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_77;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_68;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 16:	/* Entered on: O */
	St_27:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_71;}
		else if(c ==95) {			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==39) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_76;}
		else if(c ==34) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_75;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_68;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 17:	/* Entered on: E */
	St_25:
		if( scanTbl[(c= *p++)+256] & 1<< 6){ /*  A-M O-R T-Z a-m o-r t-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_73;}
		else if( scanTbl[c+256] & 1<< 7){ /*  N S n s */
			goto St_74;}
		else if(c ==95) {			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_72;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 18:	/* Entered on: B */
	St_23:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_71;}
		else if(c ==95) {			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==39) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_70;}
		else if(c ==34) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_69;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_68;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 19:	/* Entered on: > */
	St_21:
		if((c= *p++) ==61) {			goto St_63;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 20;
			goto done;
			}

case 20:	/* Entered on: = */
	St_20:
		if((c= *p++) ==62) {			goto St_62;}
		else if(c ==61) {			goto St_61;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 9;
			goto done;
			}

case 21:	/* Entered on: < */
	St_19:
		if((c= *p++) ==61) {			goto St_60;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 19;
			goto done;
			}

case 22:	/* Entered on: ; */
	St_18:
		if((c= *p++) ==59) {			goto St_59;}
		else if(c ==32) {		extcode = 3;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = EndOfStmt;
			goto St_58;}
		else if(c ==10) {			goto St_4;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 3;
			EndOfStmt(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 23:	/* Entered on: / */
	St_15:
		if((c= *p++) ==61) {			goto St_49;}
		else if(c ==47) {			goto St_48;}
		else if(c ==41) {			goto St_47;}
		else if(c ==32) {		extcode = 15001;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkslsh;
			goto St_46;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 15001;
			mkslsh(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 24:	/* Entered on: . */
	St_14:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */

		TokenEnd = TokenStart; /* prepare for error fallback */
			goto St_45;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_44;}
		else if(c ==32) {
		TokenEnd = TokenStart; /* prepare for error fallback */
			goto St_43;}
		else {TokenEnd=TokenStart;--p; goto fallback; }

case 25:	/* Entered on: - */
	St_13:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
		extcode = 17;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_42;}
		else if(c ==32) {		extcode = 17;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_41;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 17;
			goto done;
			}

case 26:	/* Entered on: + */
	St_11:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
		extcode = 16;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_42;}
		else if(c ==32) {		extcode = 16;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_41;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 16;
			goto done;
			}

case 27:	/* Entered on: * */
	St_10:
		if((c= *p++) ==42) {			goto St_40;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 15;
			goto done;
			}

case 28:	/* Entered on: ) */
	St_9:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 15001;
			mkrpar(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;

case 29:	/* Entered on: ( */
	St_8:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
		extcode = 15001;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mklpar;
			goto St_39;}
		else if(c ==47) {			goto St_38;}
		else if(c ==32) {		extcode = 15001;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mklpar;
			goto St_37;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 15001;
			mklpar(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 30:	/* Entered on:  10. */
	St_4:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 3;
			EndOfStmt(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;


default: TokenEnd=p; extcode=ExtCodeTbl[c]; goto done; /*  $-% , : _ { } */
}
	St_37:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_39;}
		else if(c ==47) {			goto St_38;}
		else {--p; goto fallback; }
	St_38:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 15001;
			mklabr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_39:
		if((c= *p++) ==45) {			goto St_87;}
		else if(c ==44) {			goto St_86;}
		else if(c ==41) {			goto St_85;}
		else if(c ==32) {			goto St_84;}
		else {--p; goto fallback; }
	St_84:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if((c= *p++) ==45) {			goto St_87;}
		else if(c ==44) {			goto St_86;}
		else if(c ==41) {			goto St_85;}
		else {--p; goto fallback; }
	St_85:
		if( scanTbl[(c= *p++)+512] & 1<< 1){ /*   10. , ; */
			goto St_125;}
		else if(c ==32) {			goto St_126;}
		else {--p; goto fallback; }
	St_126:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+512] & 1<< 1){ /*   10. , ; */
			goto St_125;}
		else {--p; goto fallback; }
	St_125:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 160;
			mkimpl(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_86:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_128;}
		else if(c ==32) {			goto St_127;}
		else {--p; goto fallback; }
	St_127:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_128;}
		else {--p; goto fallback; }
	St_128:
		if((c= *p++) ==45) {			goto St_172;}
		else if(c ==44) {			goto St_86;}
		else if(c ==41) {			goto St_85;}
		else if(c ==32) {			goto St_171;}
		else {--p; goto fallback; }
	St_171:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if((c= *p++) ==45) {			goto St_172;}
		else if(c ==44) {			goto St_86;}
		else if(c ==41) {			goto St_85;}
		else {--p; goto fallback; }
	St_172:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_206;}
		else if(c ==32) {			goto St_205;}
		else {--p; goto fallback; }
	St_205:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_206;}
		else {--p; goto fallback; }
	St_206:
		if((c= *p++) ==44) {			goto St_86;}
		else if(c ==41) {			goto St_85;}
		else if(c ==32) {			goto St_225;}
		else {--p; goto fallback; }
	St_225:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if((c= *p++) ==44) {			goto St_86;}
		else if(c ==41) {			goto St_85;}
		else {--p; goto fallback; }
	St_87:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_130;}
		else if(c ==32) {			goto St_129;}
		else {--p; goto fallback; }
	St_129:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_130;}
		else {--p; goto fallback; }
	St_130:
		if((c= *p++) ==44) {			goto St_86;}
		else if(c ==41) {			goto St_85;}
		else if(c ==32) {			goto St_173;}
		else {--p; goto fallback; }
	St_173:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if((c= *p++) ==44) {			goto St_86;}
		else if(c ==41) {			goto St_85;}
		else {--p; goto fallback; }
	St_40:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 200;
			goto done;
	St_41:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_42;}
		else {--p; goto fallback; }
	St_42:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_89;}
		else if( scanTbl[c+0] & 1<< 7){ /*  P p */
			goto St_56;}
		else if(c ==32) {			goto St_88;}
		else {--p; goto fallback; }
	St_88:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_89;}
		else {--p; goto fallback; }
	St_89:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  P p */
			goto St_56;}
		else if(c ==32) {			goto St_88;}
		else {--p; goto fallback; }
	St_56:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 156;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_43:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_45;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_44;}
		else {--p; goto fallback; }
	St_44:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_91;}
		else if( scanTbl[c+256] & 1<< 1){ /*  E e */
		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_93;}
		else if( scanTbl[c+256] & 1<< 2){ /*  D d */
		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_92;}
		else if(c ==32) {		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_90;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 232;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_90:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_91;}
		else {--p; goto fallback; }
	St_91:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 1){ /*  E e */
		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_93;}
		else if( scanTbl[c+256] & 1<< 2){ /*  D d */
		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_92;}
		else if(c ==32) {		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_90;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 232;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_92:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_133;}
		else if( scanTbl[c+512] & 1<< 2){ /*  + - */
			goto St_132;}
		else if(c ==32) {			goto St_131;}
		else {--p; goto fallback; }
	St_131:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_133;}
		else if( scanTbl[c+512] & 1<< 2){ /*  + - */
			goto St_132;}
		else {--p; goto fallback; }
	St_132:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_133;}
		else if(c ==32) {			goto St_174;}
		else {--p; goto fallback; }
	St_174:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_133;}
		else {--p; goto fallback; }
	St_133:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_176;}
		else if(c ==32) {		extcode = 231;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_175;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 231;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_175:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_176;}
		else {--p; goto fallback; }
	St_176:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if((c= *p++) ==32) {		extcode = 231;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_175;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 231;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_93:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_136;}
		else if( scanTbl[c+512] & 1<< 2){ /*  + - */
			goto St_135;}
		else if(c ==32) {			goto St_134;}
		else {--p; goto fallback; }
	St_134:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_136;}
		else if( scanTbl[c+512] & 1<< 2){ /*  + - */
			goto St_135;}
		else {--p; goto fallback; }
	St_135:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_136;}
		else if(c ==32) {			goto St_177;}
		else {--p; goto fallback; }
	St_177:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_136;}
		else {--p; goto fallback; }
	St_136:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_179;}
		else if(c ==32) {		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_178;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 232;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_178:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_179;}
		else {--p; goto fallback; }
	St_179:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if((c= *p++) ==32) {		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_178;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 232;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_45:
		if( scanTbl[(c= *p++)+512] & 1<< 3){ /*    A-Z a-z */
			goto St_94;}
		else if(c ==46) {			goto St_95;}
		else {--p; goto fallback; }
	St_95:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 111;
			mkfopr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_94:
		/*    A-Z a-z*/
		while(scanTbl[(c= *p++)+512] & 1<< 3);--p;
		if((c= *p++) ==46) {			goto St_95;}
		else {--p; goto fallback; }
	St_46:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if((c= *p++) ==47) {			goto St_48;}
		else if(c ==41) {			goto St_47;}
		else {--p; goto fallback; }
	St_47:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 15001;
			mkrabr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_48:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 15001;
			mkconc(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_49:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 213;
			goto done;
	St_58:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if((c= *p++) ==59) {			goto St_59;}
		else if(c ==10) {			goto St_4;}
		else {--p; goto fallback; }
	St_59:
		/*  ;*/
		while(scanTbl[(c= *p++)+512] & 1<< 4);--p;
		if((c= *p++) ==32) {		extcode = 3;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = EndOfStmt;
			goto St_58;}
		else if(c ==10) {			goto St_4;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 3;
			EndOfStmt(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_60:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 214;
			goto done;
	St_61:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 215;
			goto done;
	St_62:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 88;
			goto done;
	St_63:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 216;
			goto done;
	St_68:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_71;}
		else if(c ==95) {			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else {--p; goto fallback; }
	St_66:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 15001;
			mkiokw(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_65:
		/*  0-9 A-Z _ a-z*/
		while(scanTbl[(c= *p++)+512] & 1<< 5);--p;
		if((c= *p++) ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_108:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else {--p; goto fallback; }
	St_71:
		if( scanTbl[(c= *p++)+512] & 1<< 6){ /*  A-Z _ a-z */
			goto St_65;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_113;}
		else if(c ==46) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_112;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_111;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_111:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+512] & 1<< 6){ /*  A-Z _ a-z */
			goto St_65;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_113;}
		else {--p; goto fallback; }
	St_113:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if( scanTbl[(c= *p++)+512] & 1<< 6){ /*  A-Z _ a-z */
			goto St_65;}
		else if(c ==46) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_112;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_111;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_112:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_154;}
		else if(c ==32) {			goto St_153;}
		else {--p; goto fallback; }
	St_153:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_154;}
		else {--p; goto fallback; }
	St_154:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_187;}
		else if(c ==32) {		extcode = 115;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkidn;
			goto St_186;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 115;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_186:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_187;}
		else {--p; goto fallback; }
	St_187:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if((c= *p++) ==32) {		extcode = 115;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkidn;
			goto St_186;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 115;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_67:
		/*  A-Z a-z*/
		while(scanTbl[(c= *p++)+0] & 1<< 3);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_64:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else {--p; goto fallback; }
	St_69:
		if( scanTbl[(c= *p++)+512] & 1<< 7){ /*  0-1 */
			goto St_109;}
		else {--p; goto fallback; }
	St_109:
		/*  0-1*/
		while(scanTbl[(c= *p++)+512] & 1<< 7);--p;
		if((c= *p++) ==34) {			goto St_152;}
		else {--p; goto fallback; }
	St_152:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 75;
			goto done;
	St_70:
		if( scanTbl[(c= *p++)+512] & 1<< 7){ /*  0-1 */
			goto St_110;}
		else {--p; goto fallback; }
	St_110:
		/*  0-1*/
		while(scanTbl[(c= *p++)+512] & 1<< 7);--p;
		if((c= *p++) ==39) {			goto St_152;}
		else {--p; goto fallback; }
	St_72:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_73;}
		else if(c ==95) {			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else {--p; goto fallback; }
	St_73:
		if( scanTbl[(c= *p++)+512] & 1<< 6){ /*  A-Z _ a-z */
			goto St_65;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_116;}
		else if(c ==46) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_115;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_114;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_114:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+512] & 1<< 6){ /*  A-Z _ a-z */
			goto St_65;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_116;}
		else {--p; goto fallback; }
	St_116:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if( scanTbl[(c= *p++)+512] & 1<< 6){ /*  A-Z _ a-z */
			goto St_65;}
		else if(c ==46) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_115;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_114;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_115:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_156;}
		else if(c ==32) {			goto St_155;}
		else {--p; goto fallback; }
	St_155:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_156;}
		else {--p; goto fallback; }
	St_156:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_189;}
		else if( scanTbl[c+256] & 1<< 1){ /*  E e */
		extcode = 115;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkidn;
			goto St_190;}
		else if(c ==32) {		extcode = 115;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkidn;
			goto St_188;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 115;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_188:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_189;}
		else if( scanTbl[c+256] & 1<< 1){ /*  E e */
			goto St_190;}
		else {--p; goto fallback; }
	St_190:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_210;}
		else if(c ==32) {			goto St_209;}
		else {--p; goto fallback; }
	St_209:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_210;}
		else {--p; goto fallback; }
	St_210:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_227;}
		else if(c ==32) {		extcode = 115;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkidn;
			goto St_226;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 115;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_226:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_227;}
		else {--p; goto fallback; }
	St_227:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if((c= *p++) ==32) {		extcode = 115;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkidn;
			goto St_226;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 115;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_189:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 1){ /*  E e */
		extcode = 115;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkidn;
			goto St_190;}
		else if(c ==32) {		extcode = 115;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkidn;
			goto St_188;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 115;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_74:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_73;}
		else if(c ==95) {			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_72;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_75:
		if( scanTbl[(c= *p++)+768] & 1<< 0){ /*  0-7 */
			goto St_117;}
		else {--p; goto fallback; }
	St_117:
		/*  0-7*/
		while(scanTbl[(c= *p++)+768] & 1<< 0);--p;
		if((c= *p++) ==34) {			goto St_157;}
		else {--p; goto fallback; }
	St_157:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 76;
			goto done;
	St_76:
		if( scanTbl[(c= *p++)+768] & 1<< 0){ /*  0-7 */
			goto St_118;}
		else {--p; goto fallback; }
	St_118:
		/*  0-7*/
		while(scanTbl[(c= *p++)+768] & 1<< 0);--p;
		if((c= *p++) ==39) {			goto St_157;}
		else {--p; goto fallback; }
	St_77:
		if( scanTbl[(c= *p++)+768] & 1<< 1){ /*  0-9 A-F a-f */
			goto St_119;}
		else {--p; goto fallback; }
	St_119:
		/*  0-9 A-F a-f*/
		while(scanTbl[(c= *p++)+768] & 1<< 1);--p;
		if((c= *p++) ==34) {			goto St_158;}
		else {--p; goto fallback; }
	St_158:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 77;
			goto done;
	St_78:
		if( scanTbl[(c= *p++)+768] & 1<< 1){ /*  0-9 A-F a-f */
			goto St_120;}
		else {--p; goto fallback; }
	St_120:
		/*  0-9 A-F a-f*/
		while(scanTbl[(c= *p++)+768] & 1<< 1);--p;
		if((c= *p++) ==39) {			goto St_158;}
		else {--p; goto fallback; }
	St_79:
		if( scanTbl[(c= *p++)+768] & 1<< 2){ /*  A-Z a-q s-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==114) {			goto St_121;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_121:
		if( scanTbl[(c= *p++)+256] & 1<< 4){ /*  A-Z a-m o-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==110) {			goto St_159;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_159:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  A-Z a-d f-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==101) {			goto St_191;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_191:
		if( scanTbl[(c= *p++)+768] & 1<< 2){ /*  A-Z a-q s-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==114) {			goto St_211;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_211:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_65;}
		else if(c ==95) {			goto St_228;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_228:
		if( scanTbl[(c= *p++)+768] & 1<< 3){ /*  0-9 A-Z _ a-c e-z */
			goto St_65;}
		else if(c ==100) {			goto St_243;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_243:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_257;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_257:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  0-9 A-Z _ a-o q-z */
			goto St_65;}
		else if(c ==112) {			goto St_274;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_274:
		if( scanTbl[(c= *p++)+768] & 1<< 6){ /*  0-9 A-Z _ a-s u-z */
			goto St_65;}
		else if(c ==116) {			goto St_291;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_291:
		if( scanTbl[(c= *p++)+768] & 1<< 7){ /*  0-9 A-Z _ a-g i-z */
			goto St_65;}
		else if(c ==104) {			goto St_309;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_309:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 36;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 36;
			goto done;
			}
	St_80:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_73;}
		else if(c ==95) {			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_72;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_81:
		if( scanTbl[(c= *p++)+1024] & 1<< 0){ /*  A-Z a-r t-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==115) {			goto St_122;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_122:
		if( scanTbl[(c= *p++)+1024] & 1<< 1){ /*  A-Z a-b e i-o q-r v-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==117) {			goto St_168;}
		else if(c ==116) {			goto St_167;}
		else if(c ==115) {			goto St_166;}
		else if(c ==112) {			goto St_165;}
		else if(c ==104) {			goto St_164;}
		else if(c ==103) {			goto St_163;}
		else if(c ==102) {			goto St_162;}
		else if(c ==100) {			goto St_161;}
		else if(c ==99) {			goto St_160;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_160:
		if( scanTbl[(c= *p++)+1024] & 1<< 2){ /*  A-Z a-g i-n p-q s-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==114) {			goto St_194;}
		else if(c ==111) {			goto St_193;}
		else if(c ==104) {			goto St_192;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_192:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  A-Z a-d f-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==101) {			goto St_212;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_212:
		if( scanTbl[(c= *p++)+1024] & 1<< 3){ /*  A-Z a-b d-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==99) {			goto St_229;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_229:
		if( scanTbl[(c= *p++)+1024] & 1<< 4){ /*  A-Z a-j l-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==107) {			goto St_244;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_244:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_65;}
		else if(c ==95) {			goto St_258;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_258:
		if( scanTbl[(c= *p++)+768] & 1<< 7){ /*  0-9 A-Z _ a-g i-z */
			goto St_65;}
		else if(c ==104) {			goto St_275;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_275:
		if( scanTbl[(c= *p++)+1024] & 1<< 5){ /*  0-9 A-Z _ b-z */
			goto St_65;}
		else if(c ==97) {			goto St_292;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_292:
		if( scanTbl[(c= *p++)+1024] & 1<< 6){ /*  0-9 A-Z _ a-k m-z */
			goto St_65;}
		else if(c ==108) {			goto St_310;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_310:
		if( scanTbl[(c= *p++)+1024] & 1<< 7){ /*  0-9 A-Z _ a-n p-z */
			goto St_65;}
		else if(c ==111) {			goto St_327;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_327:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 150;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 150;
			goto done;
			}
	St_193:
		if( scanTbl[(c= *p++)+256] & 1<< 5){ /*  A-Z a-l n-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==109) {			goto St_213;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_213:
		if( scanTbl[(c= *p++)+1280] & 1<< 0){ /*  A-Z a-o q-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==112) {			goto St_230;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_230:
		if( scanTbl[(c= *p++)+1280] & 1<< 1){ /*  A-Z b-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==97) {			goto St_245;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_245:
		if( scanTbl[(c= *p++)+768] & 1<< 2){ /*  A-Z a-q s-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==114) {			goto St_259;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_259:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  A-Z a-d f-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==101) {			goto St_276;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_276:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_65;}
		else if(c ==95) {			goto St_293;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_293:
		if( scanTbl[(c= *p++)+1280] & 1<< 2){ /*  0-9 A-Z _ a-u w-z */
			goto St_65;}
		else if(c ==118) {			goto St_311;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_311:
		if( scanTbl[(c= *p++)+1024] & 1<< 5){ /*  0-9 A-Z _ b-z */
			goto St_65;}
		else if(c ==97) {			goto St_328;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_328:
		if( scanTbl[(c= *p++)+1280] & 1<< 3){ /*  0-9 A-Z _ a-q s-z */
			goto St_65;}
		else if(c ==114) {			goto St_342;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_342:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 151;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 151;
			goto done;
			}
	St_194:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  A-Z a-d f-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==101) {			goto St_214;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_214:
		if( scanTbl[(c= *p++)+1280] & 1<< 1){ /*  A-Z b-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==97) {			goto St_231;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_231:
		if( scanTbl[(c= *p++)+1280] & 1<< 4){ /*  A-Z a-s u-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==116) {			goto St_246;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_246:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  A-Z a-d f-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==101) {			goto St_260;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_260:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_65;}
		else if(c ==95) {			goto St_277;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_277:
		if( scanTbl[(c= *p++)+1280] & 1<< 5){ /*  0-9 A-Z _ a-c e-o q-z */
			goto St_65;}
		else if(c ==112) {			goto St_295;}
		else if(c ==100) {			goto St_294;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_294:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_312;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_312:
		if( scanTbl[(c= *p++)+1280] & 1<< 6){ /*  0-9 A-Z _ a-b d-z */
			goto St_65;}
		else if(c ==99) {			goto St_329;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_329:
		if( scanTbl[(c= *p++)+1024] & 1<< 7){ /*  0-9 A-Z _ a-n p-z */
			goto St_65;}
		else if(c ==111) {			goto St_343;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_343:
		if( scanTbl[(c= *p++)+1280] & 1<< 7){ /*  0-9 A-Z _ a-l n-z */
			goto St_65;}
		else if(c ==109) {			goto St_355;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_355:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  0-9 A-Z _ a-o q-z */
			goto St_65;}
		else if(c ==112) {			goto St_365;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_365:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 104;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 104;
			goto done;
			}
	St_295:
		if( scanTbl[(c= *p++)+1024] & 1<< 5){ /*  0-9 A-Z _ b-z */
			goto St_65;}
		else if(c ==97) {			goto St_313;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_313:
		if( scanTbl[(c= *p++)+1280] & 1<< 6){ /*  0-9 A-Z _ a-b d-z */
			goto St_65;}
		else if(c ==99) {			goto St_330;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_330:
		if( scanTbl[(c= *p++)+1536] & 1<< 0){ /*  0-9 A-Z _ a-j l-z */
			goto St_65;}
		else if(c ==107) {			goto St_344;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_344:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_356;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_356:
		if( scanTbl[(c= *p++)+768] & 1<< 3){ /*  0-9 A-Z _ a-c e-z */
			goto St_65;}
		else if(c ==100) {			goto St_366;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_366:
		if( scanTbl[(c= *p++)+1536] & 1<< 1){ /*  0-9 A-Z a-z */
			goto St_65;}
		else if(c ==95) {			goto St_372;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_372:
		if( scanTbl[(c= *p++)+1536] & 1<< 2){ /*  0-9 A-Z _ a-r t-z */
			goto St_65;}
		else if(c ==115) {			goto St_378;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_378:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  0-9 A-Z _ a-o q-z */
			goto St_65;}
		else if(c ==112) {			goto St_383;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_383:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_387;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_387:
		if( scanTbl[(c= *p++)+1280] & 1<< 6){ /*  0-9 A-Z _ a-b d-z */
			goto St_65;}
		else if(c ==99) {			goto St_391;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_391:
		if( scanTbl[(c= *p++)+1536] & 1<< 1){ /*  0-9 A-Z a-z */
			goto St_65;}
		else if(c ==95) {			goto St_394;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_394:
		if( scanTbl[(c= *p++)+768] & 1<< 3){ /*  0-9 A-Z _ a-c e-z */
			goto St_65;}
		else if(c ==100) {			goto St_397;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_397:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_400;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_400:
		if( scanTbl[(c= *p++)+1280] & 1<< 6){ /*  0-9 A-Z _ a-b d-z */
			goto St_65;}
		else if(c ==99) {			goto St_403;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_403:
		if( scanTbl[(c= *p++)+1024] & 1<< 7){ /*  0-9 A-Z _ a-n p-z */
			goto St_65;}
		else if(c ==111) {			goto St_406;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_406:
		if( scanTbl[(c= *p++)+1280] & 1<< 7){ /*  0-9 A-Z _ a-l n-z */
			goto St_65;}
		else if(c ==109) {			goto St_409;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_409:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  0-9 A-Z _ a-o q-z */
			goto St_65;}
		else if(c ==112) {			goto St_412;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_412:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 105;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 105;
			goto done;
			}
	St_161:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  A-Z a-d f-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==101) {			goto St_195;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_195:
		if( scanTbl[(c= *p++)+1024] & 1<< 3){ /*  A-Z a-b d-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==99) {			goto St_215;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_215:
		if( scanTbl[(c= *p++)+1536] & 1<< 3){ /*  A-Z a-k m-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==108) {			goto St_232;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_232:
		if( scanTbl[(c= *p++)+1280] & 1<< 1){ /*  A-Z b-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==97) {			goto St_247;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_247:
		if( scanTbl[(c= *p++)+768] & 1<< 2){ /*  A-Z a-q s-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==114) {			goto St_261;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_261:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  A-Z a-d f-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==101) {			goto St_278;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_278:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_65;}
		else if(c ==95) {			goto St_296;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_296:
		if( scanTbl[(c= *p++)+1280] & 1<< 5){ /*  0-9 A-Z _ a-c e-o q-z */
			goto St_65;}
		else if(c ==112) {			goto St_315;}
		else if(c ==100) {			goto St_314;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_314:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_331;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_331:
		if( scanTbl[(c= *p++)+1280] & 1<< 6){ /*  0-9 A-Z _ a-b d-z */
			goto St_65;}
		else if(c ==99) {			goto St_345;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_345:
		if( scanTbl[(c= *p++)+1024] & 1<< 7){ /*  0-9 A-Z _ a-n p-z */
			goto St_65;}
		else if(c ==111) {			goto St_357;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_357:
		if( scanTbl[(c= *p++)+1280] & 1<< 7){ /*  0-9 A-Z _ a-l n-z */
			goto St_65;}
		else if(c ==109) {			goto St_367;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_367:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  0-9 A-Z _ a-o q-z */
			goto St_65;}
		else if(c ==112) {			goto St_373;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_373:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 109;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 109;
			goto done;
			}
	St_315:
		if( scanTbl[(c= *p++)+1024] & 1<< 5){ /*  0-9 A-Z _ b-z */
			goto St_65;}
		else if(c ==97) {			goto St_332;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_332:
		if( scanTbl[(c= *p++)+1280] & 1<< 6){ /*  0-9 A-Z _ a-b d-z */
			goto St_65;}
		else if(c ==99) {			goto St_346;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_346:
		if( scanTbl[(c= *p++)+1536] & 1<< 0){ /*  0-9 A-Z _ a-j l-z */
			goto St_65;}
		else if(c ==107) {			goto St_358;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_358:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_368;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_368:
		if( scanTbl[(c= *p++)+768] & 1<< 3){ /*  0-9 A-Z _ a-c e-z */
			goto St_65;}
		else if(c ==100) {			goto St_374;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_374:
		if( scanTbl[(c= *p++)+1536] & 1<< 1){ /*  0-9 A-Z a-z */
			goto St_65;}
		else if(c ==95) {			goto St_379;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_379:
		if( scanTbl[(c= *p++)+1536] & 1<< 2){ /*  0-9 A-Z _ a-r t-z */
			goto St_65;}
		else if(c ==115) {			goto St_384;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_384:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  0-9 A-Z _ a-o q-z */
			goto St_65;}
		else if(c ==112) {			goto St_388;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_388:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_392;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_392:
		if( scanTbl[(c= *p++)+1280] & 1<< 6){ /*  0-9 A-Z _ a-b d-z */
			goto St_65;}
		else if(c ==99) {			goto St_395;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_395:
		if( scanTbl[(c= *p++)+1536] & 1<< 1){ /*  0-9 A-Z a-z */
			goto St_65;}
		else if(c ==95) {			goto St_398;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_398:
		if( scanTbl[(c= *p++)+768] & 1<< 3){ /*  0-9 A-Z _ a-c e-z */
			goto St_65;}
		else if(c ==100) {			goto St_401;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_401:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_404;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_404:
		if( scanTbl[(c= *p++)+1280] & 1<< 6){ /*  0-9 A-Z _ a-b d-z */
			goto St_65;}
		else if(c ==99) {			goto St_407;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_407:
		if( scanTbl[(c= *p++)+1024] & 1<< 7){ /*  0-9 A-Z _ a-n p-z */
			goto St_65;}
		else if(c ==111) {			goto St_410;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_410:
		if( scanTbl[(c= *p++)+1280] & 1<< 7){ /*  0-9 A-Z _ a-l n-z */
			goto St_65;}
		else if(c ==109) {			goto St_413;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_413:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  0-9 A-Z _ a-o q-z */
			goto St_65;}
		else if(c ==112) {			goto St_415;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_415:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 110;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 110;
			goto done;
			}
	St_162:
		if( scanTbl[(c= *p++)+1536] & 1<< 3){ /*  A-Z a-k m-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==108) {			goto St_196;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_196:
		if( scanTbl[(c= *p++)+1536] & 1<< 4){ /*  A-Z a-t v-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==117) {			goto St_216;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_216:
		if( scanTbl[(c= *p++)+1024] & 1<< 0){ /*  A-Z a-r t-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==115) {			goto St_233;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_233:
		if( scanTbl[(c= *p++)+1536] & 1<< 5){ /*  A-Z a-g i-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==104) {			goto St_248;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_248:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_65;}
		else if(c ==95) {			goto St_262;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_262:
		if( scanTbl[(c= *p++)+1024] & 1<< 7){ /*  0-9 A-Z _ a-n p-z */
			goto St_65;}
		else if(c ==111) {			goto St_279;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_279:
		if( scanTbl[(c= *p++)+1536] & 1<< 6){ /*  0-9 A-Z _ a-t v-z */
			goto St_65;}
		else if(c ==117) {			goto St_297;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_297:
		if( scanTbl[(c= *p++)+768] & 1<< 6){ /*  0-9 A-Z _ a-s u-z */
			goto St_65;}
		else if(c ==116) {			goto St_316;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_316:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  0-9 A-Z _ a-o q-z */
			goto St_65;}
		else if(c ==112) {			goto St_333;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_333:
		if( scanTbl[(c= *p++)+1536] & 1<< 6){ /*  0-9 A-Z _ a-t v-z */
			goto St_65;}
		else if(c ==117) {			goto St_347;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_347:
		if( scanTbl[(c= *p++)+768] & 1<< 6){ /*  0-9 A-Z _ a-s u-z */
			goto St_65;}
		else if(c ==116) {			goto St_359;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_359:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 28;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 28;
			goto done;
			}
	St_163:
		if( scanTbl[(c= *p++)+1536] & 1<< 3){ /*  A-Z a-k m-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==108) {			goto St_197;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_197:
		if( scanTbl[(c= *p++)+512] & 1<< 0){ /*  A-Z a-n p-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==111) {			goto St_217;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_217:
		if( scanTbl[(c= *p++)+1536] & 1<< 7){ /*  A-Z a c-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==98) {			goto St_234;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_234:
		if( scanTbl[(c= *p++)+1280] & 1<< 1){ /*  A-Z b-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==97) {			goto St_249;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_249:
		if( scanTbl[(c= *p++)+1536] & 1<< 3){ /*  A-Z a-k m-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==108) {			goto St_263;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_263:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_65;}
		else if(c ==95) {			goto St_280;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_280:
		if( scanTbl[(c= *p++)+1792] & 1<< 0){ /*  0-9 A-Z _ a-h j-z */
			goto St_65;}
		else if(c ==105) {			goto St_298;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_298:
		if( scanTbl[(c= *p++)+1792] & 1<< 1){ /*  0-9 A-Z _ a-m o-z */
			goto St_65;}
		else if(c ==110) {			goto St_317;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_317:
		if( scanTbl[(c= *p++)+768] & 1<< 3){ /*  0-9 A-Z _ a-c e-z */
			goto St_65;}
		else if(c ==100) {			goto St_334;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_334:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_348;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_348:
		if( scanTbl[(c= *p++)+1792] & 1<< 2){ /*  0-9 A-Z _ a-w y-z */
			goto St_65;}
		else if(c ==120) {			goto St_360;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_360:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 154;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 154;
			goto done;
			}
	St_164:
		if( scanTbl[(c= *p++)+1280] & 1<< 1){ /*  A-Z b-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==97) {			goto St_198;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_198:
		if( scanTbl[(c= *p++)+1536] & 1<< 3){ /*  A-Z a-k m-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==108) {			goto St_218;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_218:
		if( scanTbl[(c= *p++)+512] & 1<< 0){ /*  A-Z a-n p-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==111) {			goto St_235;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_235:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_65;}
		else if(c ==95) {			goto St_250;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_250:
		if( scanTbl[(c= *p++)+1792] & 1<< 3){ /*  0-9 A-Z _ a-b d-f h-r t v-z */
			goto St_65;}
		else if(c ==117) {			goto St_267;}
		else if(c ==115) {			goto St_266;}
		else if(c ==103) {			goto St_265;}
		else if(c ==99) {			goto St_264;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_264:
		if( scanTbl[(c= *p++)+1024] & 1<< 7){ /*  0-9 A-Z _ a-n p-z */
			goto St_65;}
		else if(c ==111) {			goto St_281;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_281:
		if( scanTbl[(c= *p++)+1280] & 1<< 7){ /*  0-9 A-Z _ a-l n-z */
			goto St_65;}
		else if(c ==109) {			goto St_299;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_299:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  0-9 A-Z _ a-o q-z */
			goto St_65;}
		else if(c ==112) {			goto St_318;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_318:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 114;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 114;
			goto done;
			}
	St_265:
		if( scanTbl[(c= *p++)+1024] & 1<< 5){ /*  0-9 A-Z _ b-z */
			goto St_65;}
		else if(c ==97) {			goto St_282;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_282:
		if( scanTbl[(c= *p++)+768] & 1<< 6){ /*  0-9 A-Z _ a-s u-z */
			goto St_65;}
		else if(c ==116) {			goto St_300;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_300:
		if( scanTbl[(c= *p++)+768] & 1<< 7){ /*  0-9 A-Z _ a-g i-z */
			goto St_65;}
		else if(c ==104) {			goto St_319;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_319:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_335;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_335:
		if( scanTbl[(c= *p++)+1280] & 1<< 3){ /*  0-9 A-Z _ a-q s-z */
			goto St_65;}
		else if(c ==114) {			goto St_349;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_349:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 34;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 34;
			goto done;
			}
	St_266:
		if( scanTbl[(c= *p++)+1280] & 1<< 6){ /*  0-9 A-Z _ a-b d-z */
			goto St_65;}
		else if(c ==99) {			goto St_283;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_283:
		if( scanTbl[(c= *p++)+1024] & 1<< 5){ /*  0-9 A-Z _ b-z */
			goto St_65;}
		else if(c ==97) {			goto St_301;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_301:
		if( scanTbl[(c= *p++)+768] & 1<< 6){ /*  0-9 A-Z _ a-s u-z */
			goto St_65;}
		else if(c ==116) {			goto St_320;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_320:
		if( scanTbl[(c= *p++)+768] & 1<< 6){ /*  0-9 A-Z _ a-s u-z */
			goto St_65;}
		else if(c ==116) {			goto St_336;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_336:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_350;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_350:
		if( scanTbl[(c= *p++)+1280] & 1<< 3){ /*  0-9 A-Z _ a-q s-z */
			goto St_65;}
		else if(c ==114) {			goto St_361;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_361:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 152;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 152;
			goto done;
			}
	St_267:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  0-9 A-Z _ a-o q-z */
			goto St_65;}
		else if(c ==112) {			goto St_284;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_284:
		if( scanTbl[(c= *p++)+768] & 1<< 3){ /*  0-9 A-Z _ a-c e-z */
			goto St_65;}
		else if(c ==100) {			goto St_302;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_302:
		if( scanTbl[(c= *p++)+1024] & 1<< 5){ /*  0-9 A-Z _ b-z */
			goto St_65;}
		else if(c ==97) {			goto St_321;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_321:
		if( scanTbl[(c= *p++)+768] & 1<< 6){ /*  0-9 A-Z _ a-s u-z */
			goto St_65;}
		else if(c ==116) {			goto St_337;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_337:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_351;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_351:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 35;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 35;
			goto done;
			}
	St_165:
		if( scanTbl[(c= *p++)+768] & 1<< 2){ /*  A-Z a-q s-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==114) {			goto St_199;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_199:
		if( scanTbl[(c= *p++)+1792] & 1<< 4){ /*  A-Z a-h j-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==105) {			goto St_219;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_219:
		if( scanTbl[(c= *p++)+256] & 1<< 4){ /*  A-Z a-m o-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==110) {			goto St_236;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_236:
		if( scanTbl[(c= *p++)+1280] & 1<< 4){ /*  A-Z a-s u-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==116) {			goto St_251;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_251:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_65;}
		else if(c ==95) {			goto St_268;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_268:
		if( scanTbl[(c= *p++)+1280] & 1<< 7){ /*  0-9 A-Z _ a-l n-z */
			goto St_65;}
		else if(c ==109) {			goto St_285;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_285:
		if( scanTbl[(c= *p++)+1024] & 1<< 7){ /*  0-9 A-Z _ a-n p-z */
			goto St_65;}
		else if(c ==111) {			goto St_303;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_303:
		if( scanTbl[(c= *p++)+768] & 1<< 3){ /*  0-9 A-Z _ a-c e-z */
			goto St_65;}
		else if(c ==100) {			goto St_322;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_322:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_338;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_338:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 198;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 198;
			goto done;
			}
	St_166:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  A-Z a-d f-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==101) {			goto St_200;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_200:
		if( scanTbl[(c= *p++)+1280] & 1<< 4){ /*  A-Z a-s u-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==116) {			goto St_220;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_220:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_65;}
		else if(c ==95) {			goto St_237;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_237:
		if( scanTbl[(c= *p++)+1792] & 1<< 5){ /*  0-9 A-Z _ a-m o-s u-z */
			goto St_65;}
		else if(c ==116) {			goto St_253;}
		else if(c ==110) {			goto St_252;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_252:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_269;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_269:
		if( scanTbl[(c= *p++)+1536] & 1<< 2){ /*  0-9 A-Z _ a-r t-z */
			goto St_65;}
		else if(c ==115) {			goto St_286;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_286:
		if( scanTbl[(c= *p++)+768] & 1<< 6){ /*  0-9 A-Z _ a-s u-z */
			goto St_65;}
		else if(c ==116) {			goto St_304;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_304:
		if( scanTbl[(c= *p++)+1536] & 1<< 1){ /*  0-9 A-Z a-z */
			goto St_65;}
		else if(c ==95) {			goto St_323;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_323:
		if( scanTbl[(c= *p++)+1024] & 1<< 6){ /*  0-9 A-Z _ a-k m-z */
			goto St_65;}
		else if(c ==108) {			goto St_339;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_339:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_352;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_352:
		if( scanTbl[(c= *p++)+1280] & 1<< 2){ /*  0-9 A-Z _ a-u w-z */
			goto St_65;}
		else if(c ==118) {			goto St_362;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_362:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_369;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_369:
		if( scanTbl[(c= *p++)+1024] & 1<< 6){ /*  0-9 A-Z _ a-k m-z */
			goto St_65;}
		else if(c ==108) {			goto St_375;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_375:
		if( scanTbl[(c= *p++)+1536] & 1<< 2){ /*  0-9 A-Z _ a-r t-z */
			goto St_65;}
		else if(c ==115) {			goto St_380;}
		else if(c ==32) {		extcode = 46;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 46;
			goto done;
			}
	St_380:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 47;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 47;
			goto done;
			}
	St_253:
		if( scanTbl[(c= *p++)+1280] & 1<< 3){ /*  0-9 A-Z _ a-q s-z */
			goto St_65;}
		else if(c ==114) {			goto St_270;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_270:
		if( scanTbl[(c= *p++)+1024] & 1<< 5){ /*  0-9 A-Z _ b-z */
			goto St_65;}
		else if(c ==97) {			goto St_287;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_287:
		if( scanTbl[(c= *p++)+1792] & 1<< 1){ /*  0-9 A-Z _ a-m o-z */
			goto St_65;}
		else if(c ==110) {			goto St_305;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_305:
		if( scanTbl[(c= *p++)+1536] & 1<< 2){ /*  0-9 A-Z _ a-r t-z */
			goto St_65;}
		else if(c ==115) {			goto St_324;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_324:
		if( scanTbl[(c= *p++)+1792] & 1<< 6){ /*  0-9 A-Z _ a-e g-z */
			goto St_65;}
		else if(c ==102) {			goto St_340;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_340:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_353;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_353:
		if( scanTbl[(c= *p++)+1280] & 1<< 3){ /*  0-9 A-Z _ a-q s-z */
			goto St_65;}
		else if(c ==114) {			goto St_363;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_363:
		if( scanTbl[(c= *p++)+1536] & 1<< 1){ /*  0-9 A-Z a-z */
			goto St_65;}
		else if(c ==95) {			goto St_370;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_370:
		if( scanTbl[(c= *p++)+1792] & 1<< 0){ /*  0-9 A-Z _ a-h j-z */
			goto St_65;}
		else if(c ==105) {			goto St_376;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_376:
		if( scanTbl[(c= *p++)+1792] & 1<< 1){ /*  0-9 A-Z _ a-m o-z */
			goto St_65;}
		else if(c ==110) {			goto St_381;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_381:
		if( scanTbl[(c= *p++)+768] & 1<< 6){ /*  0-9 A-Z _ a-s u-z */
			goto St_65;}
		else if(c ==116) {			goto St_385;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_385:
		if( scanTbl[(c= *p++)+768] & 1<< 4){ /*  0-9 A-Z _ a-d f-z */
			goto St_65;}
		else if(c ==101) {			goto St_389;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_389:
		if( scanTbl[(c= *p++)+1280] & 1<< 3){ /*  0-9 A-Z _ a-q s-z */
			goto St_65;}
		else if(c ==114) {			goto St_393;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_393:
		if( scanTbl[(c= *p++)+768] & 1<< 5){ /*  0-9 A-Z _ a-o q-z */
			goto St_65;}
		else if(c ==112) {			goto St_396;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_396:
		if( scanTbl[(c= *p++)+1024] & 1<< 7){ /*  0-9 A-Z _ a-n p-z */
			goto St_65;}
		else if(c ==111) {			goto St_399;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_399:
		if( scanTbl[(c= *p++)+1024] & 1<< 6){ /*  0-9 A-Z _ a-k m-z */
			goto St_65;}
		else if(c ==108) {			goto St_402;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_402:
		if( scanTbl[(c= *p++)+1024] & 1<< 5){ /*  0-9 A-Z _ b-z */
			goto St_65;}
		else if(c ==97) {			goto St_405;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_405:
		if( scanTbl[(c= *p++)+768] & 1<< 6){ /*  0-9 A-Z _ a-s u-z */
			goto St_65;}
		else if(c ==116) {			goto St_408;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_408:
		if( scanTbl[(c= *p++)+1792] & 1<< 0){ /*  0-9 A-Z _ a-h j-z */
			goto St_65;}
		else if(c ==105) {			goto St_411;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_411:
		if( scanTbl[(c= *p++)+1024] & 1<< 7){ /*  0-9 A-Z _ a-n p-z */
			goto St_65;}
		else if(c ==111) {			goto St_414;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_414:
		if( scanTbl[(c= *p++)+1792] & 1<< 1){ /*  0-9 A-Z _ a-m o-z */
			goto St_65;}
		else if(c ==110) {			goto St_416;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_416:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 48;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 48;
			goto done;
			}
	St_167:
		if( scanTbl[(c= *p++)+512] & 1<< 0){ /*  A-Z a-n p-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==111) {			goto St_201;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_201:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_65;}
		else if(c ==95) {			goto St_221;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_221:
		if( scanTbl[(c= *p++)+1792] & 1<< 7){ /*  0-9 A-Z _ a-f h-k m-z */
			goto St_65;}
		else if(c ==108) {			goto St_239;}
		else if(c ==103) {			goto St_238;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_238:
		if( scanTbl[(c= *p++)+1024] & 1<< 6){ /*  0-9 A-Z _ a-k m-z */
			goto St_65;}
		else if(c ==108) {			goto St_254;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_254:
		if( scanTbl[(c= *p++)+1024] & 1<< 7){ /*  0-9 A-Z _ a-n p-z */
			goto St_65;}
		else if(c ==111) {			goto St_271;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_271:
		if( scanTbl[(c= *p++)+2048] & 1<< 0){ /*  0-9 A-Z _ a c-z */
			goto St_65;}
		else if(c ==98) {			goto St_288;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_288:
		if( scanTbl[(c= *p++)+1024] & 1<< 5){ /*  0-9 A-Z _ b-z */
			goto St_65;}
		else if(c ==97) {			goto St_306;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_306:
		if( scanTbl[(c= *p++)+1024] & 1<< 6){ /*  0-9 A-Z _ a-k m-z */
			goto St_65;}
		else if(c ==108) {			goto St_325;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_325:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 29;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 29;
			goto done;
			}
	St_239:
		if( scanTbl[(c= *p++)+1024] & 1<< 7){ /*  0-9 A-Z _ a-n p-z */
			goto St_65;}
		else if(c ==111) {			goto St_255;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_255:
		if( scanTbl[(c= *p++)+1280] & 1<< 6){ /*  0-9 A-Z _ a-b d-z */
			goto St_65;}
		else if(c ==99) {			goto St_272;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_272:
		if( scanTbl[(c= *p++)+1024] & 1<< 5){ /*  0-9 A-Z _ b-z */
			goto St_65;}
		else if(c ==97) {			goto St_289;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_289:
		if( scanTbl[(c= *p++)+1024] & 1<< 6){ /*  0-9 A-Z _ a-k m-z */
			goto St_65;}
		else if(c ==108) {			goto St_307;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_307:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 40;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 40;
			goto done;
			}
	St_168:
		if( scanTbl[(c= *p++)+256] & 1<< 4){ /*  A-Z a-m o-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==110) {			goto St_202;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_202:
		if( scanTbl[(c= *p++)+1024] & 1<< 0){ /*  A-Z a-r t-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==115) {			goto St_222;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_222:
		if( scanTbl[(c= *p++)+1280] & 1<< 4){ /*  A-Z a-s u-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==116) {			goto St_240;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_240:
		if( scanTbl[(c= *p++)+768] & 1<< 2){ /*  A-Z a-q s-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==114) {			goto St_256;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_256:
		if( scanTbl[(c= *p++)+1536] & 1<< 4){ /*  A-Z a-t v-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==117) {			goto St_273;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_273:
		if( scanTbl[(c= *p++)+1024] & 1<< 3){ /*  A-Z a-b d-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==99) {			goto St_290;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_290:
		if( scanTbl[(c= *p++)+1280] & 1<< 4){ /*  A-Z a-s u-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==116) {			goto St_308;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_308:
		if( scanTbl[(c= *p++)+1536] & 1<< 4){ /*  A-Z a-t v-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==117) {			goto St_326;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_326:
		if( scanTbl[(c= *p++)+768] & 1<< 2){ /*  A-Z a-q s-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==114) {			goto St_341;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_341:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  A-Z a-d f-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==101) {			goto St_354;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_354:
		if( scanTbl[(c= *p++)+2048] & 1<< 1){ /*  A-Z a-c e-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==100) {			goto St_364;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_364:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_65;}
		else if(c ==95) {			goto St_371;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_371:
		if( scanTbl[(c= *p++)+2048] & 1<< 2){ /*  0-9 A-Z _ a-f h-z */
			goto St_65;}
		else if(c ==103) {			goto St_377;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_377:
		if( scanTbl[(c= *p++)+1280] & 1<< 3){ /*  0-9 A-Z _ a-q s-z */
			goto St_65;}
		else if(c ==114) {			goto St_382;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_382:
		if( scanTbl[(c= *p++)+1792] & 1<< 0){ /*  0-9 A-Z _ a-h j-z */
			goto St_65;}
		else if(c ==105) {			goto St_386;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_386:
		if( scanTbl[(c= *p++)+768] & 1<< 3){ /*  0-9 A-Z _ a-c e-z */
			goto St_65;}
		else if(c ==100) {			goto St_390;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_390:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-z */
			goto St_65;}
		else if(c ==32) {		extcode = 233;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_108;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 233;
			goto done;
			}
	St_82:
		if( scanTbl[(c= *p++)+768] & 1<< 2){ /*  A-Z a-q s-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==114) {			goto St_123;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_123:
		if( scanTbl[(c= *p++)+512] & 1<< 0){ /*  A-Z a-n p-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==111) {			goto St_169;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_169:
		if( scanTbl[(c= *p++)+1536] & 1<< 3){ /*  A-Z a-k m-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==108) {			goto St_203;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_203:
		if( scanTbl[(c= *p++)+1536] & 1<< 3){ /*  A-Z a-k m-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==108) {			goto St_223;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_223:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {			goto St_241;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_241:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 237;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 237;
			goto done;
			}
	St_83:
		if( scanTbl[(c= *p++)+1024] & 1<< 3){ /*  A-Z a-b d-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==99) {			goto St_124;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_124:
		if( scanTbl[(c= *p++)+1280] & 1<< 4){ /*  A-Z a-s u-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==116) {			goto St_170;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_170:
		if( scanTbl[(c= *p++)+512] & 1<< 0){ /*  A-Z a-n p-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==111) {			goto St_204;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_204:
		if( scanTbl[(c= *p++)+768] & 1<< 2){ /*  A-Z a-q s-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==114) {			goto St_224;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 25;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = keycheck;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_224:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {			goto St_242;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 25;
			keycheck(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_242:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_67;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 _ */
			goto St_65;}
		else if(c ==61) {			goto St_66;}
		else if(c ==32) {		extcode = 238;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = NULL;
			goto St_64;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 238;
			goto done;
			}
	St_50:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_52;}
		else if( scanTbl[c+256] & 1<< 1){ /*  E e */
		extcode = 24;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfint;
			goto St_96;}
		else if(c ==46) {			goto St_51;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 24;
			mkfint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_51:
		if( scanTbl[(c= *p++)+2048] & 1<< 3){ /*  A-C F-Z a-c f-z */
		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_99;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_98;}
		else if( scanTbl[c+256] & 1<< 1){ /*  E e */
		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_101;}
		else if( scanTbl[c+256] & 1<< 2){ /*  D d */
		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_100;}
		else if(c ==32) {		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_97;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 232;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_97:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_99;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_98;}
		else {--p; goto fallback; }
	St_98:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 1){ /*  E e */
		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_93;}
		else if( scanTbl[c+256] & 1<< 2){ /*  D d */
		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_92;}
		else if(c ==32) {		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_139;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 232;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_139:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_98;}
		else {--p; goto fallback; }
	St_99:
		if( scanTbl[(c= *p++)+512] & 1<< 3){ /*    A-Z a-z */
			goto St_140;}
		else if(c ==46) {			goto St_141;}
		else {--p; goto fallback; }
	St_141:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 24;
			mkfint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_140:
		/*    A-Z a-z*/
		while(scanTbl[(c= *p++)+512] & 1<< 3);--p;
		if((c= *p++) ==46) {			goto St_141;}
		else {--p; goto fallback; }
	St_100:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_140;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_133;}
		else if( scanTbl[c+512] & 1<< 2){ /*  + - */
			goto St_132;}
		else if(c ==46) {			goto St_141;}
		else if(c ==32) {			goto St_142;}
		else {--p; goto fallback; }
	St_142:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_140;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_133;}
		else if( scanTbl[c+512] & 1<< 2){ /*  + - */
			goto St_132;}
		else if(c ==46) {			goto St_141;}
		else {--p; goto fallback; }
	St_101:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_140;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_136;}
		else if( scanTbl[c+512] & 1<< 2){ /*  + - */
			goto St_135;}
		else if(c ==46) {			goto St_141;}
		else if(c ==32) {			goto St_143;}
		else {--p; goto fallback; }
	St_143:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  A-Z a-z */
			goto St_140;}
		else if( scanTbl[c+0] & 1<< 5){ /*  0-9 */
			goto St_136;}
		else if( scanTbl[c+512] & 1<< 2){ /*  + - */
			goto St_135;}
		else if(c ==46) {			goto St_141;}
		else {--p; goto fallback; }
	St_96:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_138;}
		else if(c ==32) {			goto St_137;}
		else {--p; goto fallback; }
	St_137:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_138;}
		else {--p; goto fallback; }
	St_138:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_181;}
		else if(c ==46) {			goto St_150;}
		else if(c ==32) {			goto St_180;}
		else {--p; goto fallback; }
	St_180:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_181;}
		else if(c ==46) {			goto St_150;}
		else {--p; goto fallback; }
	St_150:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_185;}
		else if(c ==32) {			goto St_184;}
		else {--p; goto fallback; }
	St_184:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_185;}
		else {--p; goto fallback; }
	St_185:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_208;}
		else if(c ==32) {		extcode = 24;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfint;
			goto St_207;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 24;
			mkfint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_207:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_208;}
		else {--p; goto fallback; }
	St_208:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if((c= *p++) ==32) {		extcode = 24;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfint;
			goto St_207;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 24;
			mkfint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_181:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if((c= *p++) ==46) {			goto St_150;}
		else if(c ==32) {			goto St_180;}
		else {--p; goto fallback; }
	St_52:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 6){ /*  X x */
			goto St_57;}
		else if( scanTbl[c+0] & 1<< 7){ /*  P p */
			goto St_56;}
		else if( scanTbl[c+256] & 1<< 0){ /*  H h */
			goto St_55;}
		else if( scanTbl[c+256] & 1<< 1){ /*  E e */
		extcode = 24;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfint;
			goto St_54;}
		else if( scanTbl[c+256] & 1<< 2){ /*  D d */
		extcode = 24;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfint;
			goto St_53;}
		else if(c ==46) {			goto St_51;}
		else if(c ==32) {			goto St_50;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 24;
			mkfint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_53:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_104;}
		else if( scanTbl[c+512] & 1<< 2){ /*  + - */
			goto St_103;}
		else if(c ==32) {			goto St_102;}
		else {--p; goto fallback; }
	St_102:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_104;}
		else if( scanTbl[c+512] & 1<< 2){ /*  + - */
			goto St_103;}
		else {--p; goto fallback; }
	St_103:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_104;}
		else if(c ==32) {			goto St_144;}
		else {--p; goto fallback; }
	St_144:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_104;}
		else {--p; goto fallback; }
	St_104:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_146;}
		else if(c ==32) {		extcode = 231;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_145;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 231;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_145:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_146;}
		else {--p; goto fallback; }
	St_146:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if((c= *p++) ==32) {		extcode = 231;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_145;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 231;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_54:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_107;}
		else if( scanTbl[c+512] & 1<< 2){ /*  + - */
			goto St_106;}
		else if(c ==32) {			goto St_105;}
		else {--p; goto fallback; }
	St_105:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_107;}
		else if( scanTbl[c+512] & 1<< 2){ /*  + - */
			goto St_106;}
		else {--p; goto fallback; }
	St_106:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_148;}
		else if(c ==32) {			goto St_147;}
		else {--p; goto fallback; }
	St_147:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_148;}
		else {--p; goto fallback; }
	St_148:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_183;}
		else if(c ==32) {		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_182;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 232;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_182:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_183;}
		else {--p; goto fallback; }
	St_183:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if((c= *p++) ==32) {		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_182;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 232;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_107:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_151;}
		else if(c ==46) {		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_150;}
		else if(c ==32) {		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_149;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 232;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_149:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 */
			goto St_151;}
		else if(c ==46) {			goto St_150;}
		else {--p; goto fallback; }
	St_151:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 5);--p;
		if((c= *p++) ==46) {		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_150;}
		else if(c ==32) {		extcode = 232;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkfloat;
			goto St_149;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 232;
			mkfloat(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_55:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 100;
			mkholl(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_57:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 157;
			mkfmti(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
