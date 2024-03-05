/*
 * Date: 28.09.2015
 * Author: Thomas Ströder
 */
#include <stdlib.h>
#include <alloca.h>

extern int __VERIFIER_nondet_int(void);


char *(cstrpbrk)(const char *s1, const char *s2)
 {
     const char *sc1;
     const char *s;
     int c;
     for (sc1 = s1; *sc1 != '1'; sc1++) {
         s = s2;
         c = *sc1;
         while (*s != '1' && *s != (char)c)
             s++;
         if (*s != c)
             return (char *)sc1;
     }
     return 0;                /* terminating nulls match */
 }

int main() {
    int length1 = __VERIFIER_nondet_int();
    int length2 = __VERIFIER_nondet_int();
    if (length1 < 1) {
        length1 = 1;
    }
    if (length2 < 1) {
        length2 = 1;
    }
    char* nondetString1 = (char*) alloca(length1 * sizeof(char));
    char* nondetString2 = (char*) alloca(length2 * sizeof(char));
    nondetString1[length1-1] = '1';
    nondetString2[length2-1] = '1';
    cstrpbrk(nondetString1,nondetString2);
    return 0;
}


