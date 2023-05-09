#include <stdio.h>
#include <stdlib.h>

int bissexto(int ano){
    if ((ano%4 ==0 && ano%100 != 0) || ano%400==0) return 1;
    else return 0;
}
int main ()
{
    int a;
    scanf("%d", &a);
    if (bissexto(a)) printf("eh bissexto");
    else printf("nao eh bissexto");

return 0;
}
