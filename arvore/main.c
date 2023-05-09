#include <stdio.h>
#include <stdlib.h>

struct arv{
    int Info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;

Arv* ArvCriar(){
    return NULL;
}

Arv* ArvNovoNo(int Info, Arv* esq, Arv* dir){
    Arv *Novo = (Arv*) malloc(sizeof(Arv));
    Novo->Info = Info;
    Novo->esq = esq;
    Novo->dir = dir;
    return Novo;
}

void abb_imprime(Arv* a){
    if (a != NULL) {
        printf("%d\n", a->Info);
        abb_imprime(a->esq);
        abb_imprime(a->dir);
    }
}

int abb_SomaFolhas(Arv *a){
    if (a != NULL) {
        if(a->dir == NULL && a->esq == NULL) return a->Info;
        return abb_SomaFolhas(a->esq) + abb_SomaFolhas(a->dir);
    }

}

int abb_SomarMaiores(Arv *a, int n){
    if (a != NULL) {
        if(a->Info > n) return a->Info + abb_SomarMaiores(a->esq, n) + abb_SomarMaiores(a->dir, n);
        return abb_SomarMaiores(a->dir, n);
    }
    return 0;
}

int main(){

    Arv *a7, *a6, *a5, *a4, *a3, *a2, *a1;
    int somar;

    a4 = ArvNovoNo(1, NULL, NULL);
    a5 = ArvNovoNo(3, NULL, NULL);
    a6 = ArvNovoNo(5, NULL, NULL);
    a7 = ArvNovoNo(7, NULL, NULL);
    a3 = ArvNovoNo(6, a6, a7);
    a2 = ArvNovoNo(2, a4, a5);
    a1 = ArvNovoNo(4, a2, a3);

    somar = abb_SomarMaiores(a1, 0);
    printf("%d", somar);

    return 0;
}
