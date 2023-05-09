#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Baskara(double a, double   b, double   c, double   *x1, double   *x2){
    int NumRaizes;
    double Delta;
    Delta = ((b*b) - 4*(a*c));
    if (Delta<0)
        NumRaizes = 0;
    else if (Delta > 0)
        NumRaizes = 2;
    else
        NumRaizes = 1;
    *x1 = ((-b) + sqrt(Delta))/2*a;
    *x2 = ((-b) - sqrt(Delta))/2*a;
    return NumRaizes;
}

int main() {
    printf("digite o a, b e c:\n");
    double a, b, c, x1=0, x2=0;
    scanf("%lf%lf%lf", &a, &b, &c);
    int num;
    num = Baskara(a, b, c, &x1, &x2);
    printf("o numero de raizes sao: %d\n", num);
    if (num==1) printf("a raiz eh: %.0lf\n", x1);
    if (num==2) printf("as raizes sao: %lf e %lf\n", x1, x2);
    if (num==0) printf("nao tem raizes\n");

}
