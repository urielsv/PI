/*
 * Completar las condiciones de control de los siguientes ciclos:
 */

int n,c;
/* al salir del ciclo n debe ser un número par mayor que cero */
do
n = getint("");
while((n > 0) && (n % 2 == 0));
/* este ciclo debe incluir la lectura de caracteres y debe ejecutarse
* mientras no sea fin de archivo y los caracteres sean dígitos o minúsculas
*/
while (((c = getchar()) != EOF) && ((c >= '0' && c<= '9') || (c >= 'a' && c <= 'z')))
putchar(c);
