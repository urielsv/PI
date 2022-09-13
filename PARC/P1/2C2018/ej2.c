/*
 * Escribir una macro TO_UPPER que recibe un caracter y lo pasa a mayúscula. Si el caracter no
 * representa una letra minúscula del alfabeto inglés, no lo modifica.
 * La macro no puede usar funciones, ya sean propias o de la biblioteca estándar.
 */

#define     DELTA               ('a' - 'A')
#define     TO_UPPER(x)         ((x) >= 'a' && (x) =< 'z' ?\
                                    (x) - DELTA : (x))
