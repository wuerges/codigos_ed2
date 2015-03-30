#include <stdio.h>

int main(int nargs, char** argv) 
{
    int a = 3;
    float b = 0.3;
    char c1 = 'á'; 
    char c2 = 'ç'; 
    char c3 = '\n'; 
    char c32 = 10;


    char c4 = '\a'; 
    double d = 0.345;


    printf("Olá mundo\n");

    if (c3 == c32) {
        printf("Barra N igual\n");
        printf("Inteiro %d\n", 'a');
        printf("HEXADECIMAL %x\n", 97);
        printf("HEXADECIMAL %x\n", 'á');
        printf("HEXADECIMAL %x\n", 'ç');
    }
    return 0;
}
