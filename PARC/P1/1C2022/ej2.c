/*
 * Elimina vocales (no vocales sueltas) y para eliminarlas deben tener al menos
 * una letra antes o una letra depsues (y que no sea vocal).
 */
#include <stdio.h>

#define DELTA           ('a'-'A')
#define TO_LOWER(x)     ((x) >= 'A' && (x) <= 'Z' ? (x) + DELTA : (x))
#define IS_VOWEL(x)     (TO_LOWER(x) == 'a' || TO_LOWER(x) == 'e' || TO_LOWER(x) == 'i' || TO_LOWER(x) == 'o' || TO_LOWER(x) == 'u')
#define IS_ALPHA(x)     (((x) >= 'A' && (x) <= 'Z') || ((x) >= 'a' && (x) <= 'z'))

void remVowels(char str[]) 
{
    
    if (!str[0]) {
       return;
    }

    /* 
     * Escribir caracter si no es vocal o el anterior 
     * no es una letra o vocal.
     */

    int j = 0;
    for (int i = 0; str[i]; i++) {  
     
        /* Caso inicial checkear unicamente en su consecutivo. */
        if (i == 0 && (!IS_VOWEL(str[i]) || IS_VOWEL(str[i+1]) || !IS_ALPHA(str[i+1]))) {
            // Solucionar esta repeticion de codigo?
            str[j++] = str[i];
        } else if (!IS_VOWEL(str[i]) || (!IS_ALPHA(str[i-1]) || IS_VOWEL(str[i-1])) && (!IS_ALPHA(str[i+1]) || IS_VOWEL(str[i+1]))) {
            str[j++] = str[i]; 
        }
    }
    str[j] = 0;
    return;

}

int main() 
{
    char s1[] = "Hola mundo";
    char s2[] = "hola a todo el mundo";
    char s3[] = "xyz";
    char s4[] = "aholoaaa";
    char s5[] = "";
    char s6[] = "aa eo iu oa uo";
    char s7[] = "pa po pi po pu";
    char s8[] = "aeiou";
    char s9[] = "a,e,i,o,u";

    remVowels(s1);
    remVowels(s2);
    remVowels(s3);
    remVowels(s4);
    remVowels(s5);
    remVowels(s6);
    remVowels(s7);
    remVowels(s8);
    remVowels(s9);

    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);
    printf("%s\n", s4);
    printf("%s\n", s5);
    printf("%s\n", s6);
    printf("%s\n", s7);
    printf("%s\n", s8);
    printf("%s\n", s9);
    return 0;
}
