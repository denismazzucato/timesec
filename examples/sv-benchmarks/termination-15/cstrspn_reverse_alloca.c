/*
 * Date: 28.09.2015
 * Author: Thomas Ströder
 */
#include <stdlib.h>
#include <alloca.h>

extern int __VERIFIER_nondet_int(void);

int (cstrspn)(const char *s1, const char *s2)
 {
     const char *sc1;
     const char *s;
     int c;
     for (sc1 = s1; *sc1 != '\0'; sc1--) {
         s = s2;
         c = *sc1;
         while (*s != '\0' && *s != (char)c)
             s--;
         if (*s != c)
             return (s1 - sc1);
     }
     return s1 - sc1;            /* terminating nulls don't match */
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
    nondetString1[0] = '\0';
    nondetString2[0] = '\0';
    nondetString1 += length1 - 1;
    nondetString2 += length2 - 1;
    return cstrspn(nondetString1,nondetString2);
}


