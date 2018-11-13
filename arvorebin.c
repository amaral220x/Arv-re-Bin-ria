#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>

struct arvore{
  char valor;
  struct arvore *esq, *dir;
};

int no[999];

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

int contnoh(struct arvore *arv, int nos, int a){
  if(arv!=(struct arvore *)NULL){
    nos++;
    a=1;
    contnoh(arv->esq, nos, a);
    contnoh(arv->dir, nos, a);
  }
  else
    if (a)
      return nos+1;
    else
      return nos;
}

int altura(struct arvore *arv, int nivel, int alt){
    if(arv!=(struct arvore *)NULL){
        if(alt < nivel+1){
            alt = nivel+1;
        }
        altura(arv->esq, nivel+1, alt);
        altura(arv->dir, nivel+1, alt);
    }
    else
      return alt;
}

int nos_folhas(struct arvore *arv){
    int nos = 0;
    void nos_count(struct arvore *arv){
        if(arv!=(struct arvore *)NULL) {
            if((arv->dir==(struct arvore *)NULL)&&(arv->esq==(struct arvore *)NULL))
	            nos++;
                nos_count(arv->esq);
                nos_count(arv->dir);
        }
    }
    nos_count(arv);
    return nos;
}

void nosPorNivel(struct arvore *arv, int nivel){
    if(arv!=(struct arvore*)NULL){
        no[nivel]++;
        nosPorNivel(arv->esq, nivel+1);
        nosPorNivel(arv->dir, nivel+1);
    }
}


int main(void){
  int nf, alt;
  setlocale(LC_ALL,"Portuguese");
  struct arvore *arv;
  constroi(&arv);
  printf("Arvore construida\n");
  prefix(arv);
  printf("\nAltura da árvore: %d",altura(arv,0,0));
  printf("\nNumero de nós: %d", contnoh(arv,0,0));
  printf("\nNumero de nós folhas: %d", nos_folhas(arv));
  alt=altura(arv,0,0);
  for(int i=0; i<alt; i++){
    no[i]=0;
  }
  nosPorNivel(arv, 0);
  printf("\nNós por nível: \n");
  for(int i = 0; i<alt; i++){
    printf("%d = %d\n", i, no[i]);
  }
}
