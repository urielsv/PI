#include <stdio.h>

int main()
{
    char string[] = "Ho0la 00com0o est0as0";
    int j = 0;
    for (int i = 0; string[i]; i++) { // string[i] == Distinto de NULLC
       if ( string[i] != '0' )  
        string[j++] = string[i]; 
    }
    
    string[j] = '\0';
    printf("%s\n", string);
    return 0;
}


