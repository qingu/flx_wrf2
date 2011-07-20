C instead of continue, use a subroutine to do nothing. Purely for translation: in the C code we drop them!
      program test

      integer ii, jj, kk
      real*8  ff
      character*32 cc

      ii = 2
      jj = 3
      kk = 4
      ff = 9.0567
      cc = 'Example of a character string...'

      goto 41
41    call noop
      stop
      end

C      subroutine noop()
C      return
C      end
