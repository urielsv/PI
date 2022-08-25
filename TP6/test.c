#include <stdio.h>


void a(int []);

int main()
{
    int arr[8];  
    a(arr); 
    return 0;
}


void a(int arr[])
{
    const unsigned int arrSize = (sizeof(arr)/sizeof(arr[0])); 
    printf("Size: %d\n", arrSize);

}
