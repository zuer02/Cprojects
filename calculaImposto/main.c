#include <stdio.h>
#include <stdlib.h>

double imposto(double salario){
    double imp=0;
    if (salario > 2000 && salario <= 3000){
        imp = (salario - 2000) * 0.08;}
    if (salario> 3000 && salario <4500){
        imp = 80.00 + (salario - 3000) * 0.18;}
    if (salario > 4500){
        imp = 80.00 + 1500*0.18 + (salario - 4500) * 0.28; }
    return imp;
    }

int main()
{
    double salari, valor;
    scanf("%lf", &salari);
    valor = imposto(salari);
    if (salari<= 2000){
        printf ("Isento\n");}
    else printf("R$ %.2lf\n", valor);
}
