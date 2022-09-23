#include <stdio.h>

#define     DELTA            ('a'-'A')
// Sin punto y coma.
#define     A_MAYUSC(a)      a = (a >= 'a' && a <= 'z') ? a - DELTA : a;

// Con punto y coma.
#define     A_MAYUSC(a)      (a = (a >= 'a' && a <= 'z') ? a - DELTA : a)

// Igualado a una variable
#define     A_MAYUSC(a)      ((a) >= 'a' && (a) <= 'z') ? (a) - DELTA : (a))
