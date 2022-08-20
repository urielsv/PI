int a, b, c;

a = getchar();

b = getchar();

c = getchar();

//MAL APLICADO DE MORGAN UWUN'T 
if ((a!='A' || a!='E' || a!='I' || a!='O' || a!='U') && (a>='A' && a<='Z'))
    printf("El caracter %c es una consonante mayúscula \n", a);
else 

if (!(a=='a' || a=='e' || a=='i' || a=='o' || a=='i') && (a>='a' && a<='z'))
        printf("El caracter %c es una consonante minúscula \n", a);
else 
         if ((a=='a' || a=='e' || a=='i' || a=='o' || a=='i') || (a=='A' || a=='E' || a=='I' || a=='O' || a=='U'))
            printf("El caracter %c es una vocal \n", a);
        else
            printf("El caracter %c no es una letra \n", a); 

if ( (b>='0' && b<='9') && ((b-'0') % 2 == 0) )
printf("El valor ASCII de %c es par \n", b); 

if ( b=='0' || b=='2' || b=='4' || b=='6' || b=='8' )
printf("El caracter %c representa un dígito par \n", b); 

if ( (c=='a' || c=='e' || c=='i' || c=='o' || c=='i') || (c>='A' && c<='Z') )
printf("El caracter %c es una vocal o es mayúscula \n", c);

if (!(c=='a' || c=='e' || c=='i' || c=='o' || c=='i' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') && ((c>='a' && c<='z') || (c>='A' && c<='Z')))
printf("El caracter %c no es una vocal pero es letra \n", c)
