/* +++Date last modified: 05-Jul-1997 */

/*************************************************************************

    CHKREG.C - Validates a key created by REGIT.C

   Donated to the Public Domain by Craig Morrison 12 May 1994, use,
   abuse, fold, spindle or mutilate anyway you see fit.

*************************************************************************/

#include "regkey.h"

/*************************************************************************

    CHKREG accepts two arguments on its command line; The key value in
    hexadecimal generated by REGIT and a string. You should end up with
    XOR_PRIME after the XOR manipulations, if not, then the given key
    was invalid.

*************************************************************************/

int main(int argc, char *argv[])
{
      long keyval;
      long key;
      char *p;
      char buf[128];

      if (argc>2)
      {
            strcpy(buf, argv[1]);
            strupr(buf);
            sscanf(buf, "%8lX", &keyval);
            keyval ^= XOR_POST_CRYPT;

            strcpy(buf, argv[2]);
            p = strrev(buf);
            while(*p)
            {
                  if (*p=='_')
                        *p = ' ';

                  key = (long) toupper(*p);
                  key ^= (long)XOR_CRYPT;
                  keyval ^= key;
                  p++;
            }
            printf("Key value = %08lX hex.\n", keyval);
      }
      return 0;
}
