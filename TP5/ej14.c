/*
 * Un número IP identifica en una red TCP/IP a un host particular (puede ser una computadora,
 * impresora, router, cámara de seguridad, etc.). Todo número IP está compuesto de 32 bits, 
 * donde parte de ese número (una cantidad arbitraria de bits a la izquierda del número) 
 * identifica la red a la que pertenece y el resto de los bits identifican al host. 
 * Si bien el número se almacena como un entero sin signo de 4 bytes, se lo presenta al
 * usuario en 4 grupos de números decimales.
 *
 * Escribir una función que reciba:
 * ip: unsigned long con el número IP de un host
 * bitsNet: unsigned char que indica cuántos bits se utilizan para identificar a la red
 *
 * La función debe imprimir en salida estándar el número de red y el número de host 
 * correspondientes al parámetro ip.
 *
 * bits:  8       16       24       32
 * 11000000 10101000 00000000 01100100
 * 192      168      0        100
 */

#include <stdio.h>

void ipInfo(unsigned long, unsigned char);
unsigned long bitMask(unsigned char);

int main()
{
    printf("MASK: %x\n", bitMask(23));
    ipInfo(0x10FF1112, 23); 
    return 0;
}

#define     IP_LEN      32
#define     BYTE        8
#define     MASK        0xFF
void ipInfo(unsigned long ip, unsigned char bitsNet)
{
    unsigned long net, host, p1, p2, p3, p4;
    unsigned long net1, net2, net3, net4;
    unsigned long host1, host2, host3, host4;
    net = ip & bitMask(bitsNet);
    host = ip & ~bitMask(bitsNet);
    
    net1 = (net >> (IP_LEN-BYTE)) & MASK;
    net2 = (net >> (IP_LEN-BYTE*2)) & MASK; 
    net3 = (net >> (IP_LEN-BYTE*3)) & MASK; 
    net4 = net & MASK; 
    printf("Net: %d.%d.%d.%d\n\n", net1, net2, net3, net4);
    
    host1 = (host >> (IP_LEN-BYTE)) & MASK;
    host2 = (host >> (IP_LEN-BYTE*2)) & MASK; 
    host3 = (host >> (IP_LEN-BYTE*3)) & MASK; 
    host4 = host & MASK; 
    printf("Host: %d.%d.%d.%d\n\n", host1, host2, host3, host4);

    p1 = (ip >> (IP_LEN-BYTE)) & MASK; 
    p2 = (ip >> (IP_LEN-BYTE*2)) & MASK; 
    p3 = (ip >> (IP_LEN-BYTE*3)) & MASK; 
    p4 = ip & MASK;  
    printf("IP: %d.%d.%d.%d\n", p1, p2, p3, p4);    
}

unsigned long bitMask(unsigned char bitNum)
{
    unsigned long mask = 0; 
    for( int i = 1; i <= IP_LEN-bitNum; i++) {
        mask = ~((mask << 1) | 1);
    }
    return mask; 
}
#undef      IP_LEN
#undef      BYTE
#undef      MASK
