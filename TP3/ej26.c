/*
 * Modificar los siguientes fragmentos de código por un fragmento equivalente 
 * pero mejorándolo. Este ejercicio se podría titular "No hagan esto en sus 
 * casas, o al menos en los parciales y TPE". si bien funcionan no son de buen 
 * estilo, y un mal estilo suele ir acompañado de errores o código más difícil 
 * de mantener (ver documento sobre Estilo).
 */

A) FROM:
    int a = getint("Ingrese un número entero:");
    if ( a > 0 )
    printf("Es mayor que cero\n");
    if ( a < 0 )
    printf("Es menor que cero\n");
    if ( a == 0)
    printf("Es igual a cero\n");

A) TO:

    int a = getint("Ingrese un numero positivo:");
    if ( a > 0 ) {
        printf("Es mayor..");
    } else if ( a < 0 ) {
        printf("Es menor..");
    } else {
        printf("Es igual a 0.");
    }

B) FROM:
    int a = ( b > 0 ) ? 0 : 1;
    
B) TO:
    int a;
    if ( b > 0 ) {
        a = 0;
    } else
        a = 1; 

C) FROM:
    int a = 0;
    while(1) {
    f(a); // f es una función
    a = a + 1;
    if ( a >= 10 )
    break;
    }

C) TO:
    int a = 0;
    while ( a <= 10 ) {
        f(a);
        a++;
    }

D) FROM:
    if ( b > 0 )
    a = 1;
    else
    a = 0;

D) PREGUNTAR

PAJA
