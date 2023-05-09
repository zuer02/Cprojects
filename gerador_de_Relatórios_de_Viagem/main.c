#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char Destino[51];
    char Data[11];
    int Dias;
    double Valor;
}Viagem;

FILE *fpViagem, *fpRelatorio;

Viagem DigitarViagem(){
    Viagem V;
    printf("Digite o Destino: ");
    scanf(" %50[^\n]", &V.Destino);
    printf("Data: ");
    scanf(" %10[^\n]", V.Data);
    printf("Dias: ");
    scanf(" %d", &V.Dias);
    printf("Valor: ");
    scanf("%lf", &V.Valor);
    return V;
}

void MostrarViagem(Viagem V){
    printf("Destino da Viagem: %s\n", V.Destino);
    printf("Data: %s\n", V.Data);
    printf("Dias de estadia: %d\n", V.Dias);
    printf("Valor da passagem: %.2lf", V.Valor);
}

void GravaViagem(Viagem V){
    fseek(fpViagem, 0, SEEK_SET);
    fwrite(&V, sizeof(Viagem), 1, fpViagem);
}

int PesquisarViagem(char Destino[51]){
    Viagem V;
    fseek(fpViagem, 0, SEEK_SET);
    while(fread(&V, sizeof(Viagem), 1, fpViagem)){
        if(strcmp(V.Destino, Destino) == 0){
            MostrarViagem(V);
            return 1;
        }
    }
    printf("\nNao encontrado!");
    return 0;
}

void ImprimirViagens(){
    Viagem V;
    int cont = 0;
    double Total = 0;
    fseek(fpRelatorio, 0, SEEK_SET);
    fpRelatorio = fopen("RelatorioViagens.txt", "w+");
    fprintf(fpRelatorio, "Relatorio das viagens \n\nDestino                                            Data      Dias  Valor\n");
    fclose(fpRelatorio);
    fpRelatorio = fopen("RelatorioViagens.txt", "a+");
    while(fread(&V, sizeof(Viagem), 1, fpViagem)){
        fprintf(fpRelatorio, "%-50s %-10s %-5d %-10.2lf\n", V.Destino, V.Data, V.Dias, V.Valor);
        Total += V.Valor;
        cont++;
    }
    fprintf(fpRelatorio, "\n %d Viagens                      Custo total: %.2lf\n", cont, Total);
    printf("\n As Viagens estao todas no arquivo de texto.\n");
}

int main()
{
    fpViagem = fopen("Viagens.txt", "rb+");
    if(fpViagem == NULL){
        fpViagem = fopen("Viagens.txt", "wb+");
    }
    int Opcao;
    char Destino[51];
    Viagem V;
    do{
        printf("1 - Cadastrar     2- Pesquisar      3- Relatorio            0- Sair ");
        printf("Escolha uma opcao: ");
        scanf("%d", &Opcao);
        switch(Opcao){
        case 1:
            V = DigitarViagem();
            GravaViagem(V);
            break;
        case 2:
            printf("Digite um destino: ");
            scanf(" %[^\n]", Destino);
            PesquisarViagem(Destino);
            break;
        case 3:
            ImprimirViagens();
            break;
        }
        system("pause");
    }while(Opcao != 0);
    fclose(fpViagem);
return 0;
}

