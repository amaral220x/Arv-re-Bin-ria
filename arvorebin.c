#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>

struct arvore{
  char valor;
  struct arvore *esq, *dir;
};

int nos=0, aux=0, nosf=0, altura=0, aux2=0, aux3;

void constroi(struct arvore **arv){
  char valor;
  fflush(stdin);
  printf("Entre com um valor:");
  scanf("%c",&valor);
  if(valor!='.'){
    fflush(stdin);
    *arv=(struct arvore *)malloc(sizeof(struct arvore));
    (*arv)->valor=valor;
    constroi(&(*arv)->esq);
    constroi(&(*arv)->dir);
  }
  else
    *arv=(struct arvore *)NULL;
}

void prefix(struct arvore *arv){
  if(arv!=(struct arvore *)NULL){
    printf("%c",arv->valor);
    prefix(arv->esq);
    prefix(arv->dir);
  }
}

void contnoh(struct arvore *arv){
  if(arv!=(struct arvore *)NULL){
    nos++;
    aux=0;
    aux2++;
    contnoh(arv->esq);
    contnoh(arv->dir);
    if(aux2%2==0)
      altura++;
  }
  else{
    aux++;
    if(aux==2){
    nosf++;
    }
  }
}


int main(void){
  setlocale(LC_ALL,"Portuguese");
  struct arvore *arv;
  constroi(&arv);
  printf("Arvore construida\n");
  prefix(arv);
  contnoh(arv);
  printf("\nNumero de nós: %d", nos);
  printf("\nNumero de nós folhas: %d", nosf);
  printf("\nAltura da árvore: %d", altura+1);

}
