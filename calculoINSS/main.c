#include <stdio.h>
#include <stdlib.h>

struct empregados
{
    int Numero;
    char Nome[50];
    char Cargo[50];
    float Salario;
};
typedef struct empregados Empregados;

Empregados DigitarEmpregado()
{
    Empregados E;
    printf("\nNumero: ");
    scanf("%d", &E.Numero);
    fflush(stdin);
    printf("\nNome: ");
    scanf("%[^\n]", E.Nome);
    fflush(stdin);
    printf("\nCargo: ");
    scanf("%s", E.Cargo);
    printf("\nSalario: RS ");
    scanf("%f", &E.Salario);
    return E;
}
int CalcularINSS(Empregados E)
{
    int INSS;
    if(E.Salario<=1800.00)INSS = E.Salario*0.08;
    else if(E.Salario<=3500.00) INSS = E.Salario*0.1;
    else INSS = E.Salario*0.11;
    return INSS;
}

int main()
{
    Empregados E[5];
    int i, j, totalINSS=0;
    for(i=0; i<5; i++) E[i]=DigitarEmpregado();
    for(j=0; j<5; j++) totalINSS+=CalcularINSS(E[j]);
    printf("O total do INSS eh: %d", totalINSS);
    return 0;
}
