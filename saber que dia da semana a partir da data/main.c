#include <stdio.h>
#include <stdlib.h>
int juli(int ano, int mes, int dia) {
    int dataJuli;
    dataJuli = (1461 * (ano+4800+(mes-14)/12))/4 + (367 * (mes-2-12 * ((mes-14)/12)))/12 - (3 * ((ano+4900+(mes-14)/12)/100))/4 + dia - 32075;
    return (dataJuli);
    }


int main()
{
    int a, b, c, d;
    printf("digite o dia\n");
    scanf("%d", &a);
    printf("digite o mes\n");
    scanf("%d", &b);
    printf("digite o ano\n");
    scanf("%d", &c);

    d = juli(c, b, a);
    d = d % 7;
    printf("dia da semana  = %d", d);


    return 0;
}
