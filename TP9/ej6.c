#include <stdio.h>
#include <string.h>
#include <assert.h>

static int recPalim(char * str, unsigned int dim);
int isPalim(char * str);

int main() 
{

    char * str1 = "hola";
    char * str2 = "hooh";

    assert(isPalim(str1) == 0);
    assert(isPalim(str2) == 1);
    puts("uwu!");
    return 0;
}
static int recPalim(char * str, unsigned int dim)
{
    if (dim <= 1)
        return 1;

    /* Check si el primer y ultimo char son ig
     * uales y elimino esos dos y avanzo
     * un char para la siguiente recursion. 
     **/

    return (*str == *(str+dim-1)) && recPalim(str+1, dim-2); 
}
/* Creo una funcion auxiliar para no hacer siempre el 
 * llamado de strlen en larecursion. 
 **/

int isPalim(char * str)
{
    return recPalim(str, strlen(str));
}


