#include <stdio.h>
#include "conta.h"

int main(){
    printf("Chama!!");
    Conta *c;
    add(100, 2);
    depositar(c,100);
    printf("%2.f",imprimir(c));
    printf("Chama!!");
    return 0;
}