#include <stdio.h>
#include <stdlib.h>

typedef int TipoItem;

typedef struct no{
    TipoItem info;
    struct no *prox;
} Lista;

void limpar_lista(Lista * l){
    struct no *atual = l->cabeca;
    while (atual != NULL) {
        struct no *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    l->cabeca = NULL;
}


int vazia(Lista *l){
    if(l == NULL)
        return 1;
    return 0;
}


 Lista* inserirNoFinal(Lista* l, TipoItem info){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = info;
    novo -> prox = NULL;
    
    if(l == NULL){
        return novo;
    }
    else{
        Lista *aux = l;
        while(aux->prox != NULL){
            aux = aux -> prox;
        }
        aux->prox = novo;
    }
    return l;
}

void imprimir(Lista* l){
    Lista *p = l;
    while(p != NULL){
        printf("%d ", p->info);
        p = p -> prox;
    }
    printf("\n");
}


// Função que ordena uma lista encadeada sem cabeça
void ordena_lista_sem_cabeca(Lista *lista) {
    Lista *atual, *anterior, *proximo, *aux;
    if (lista != NULL || lista->prox != NULL){  // lista vazia ou com um elemento
    atual = lista->prox; 
    anterior = lista; 
    while (atual != NULL) {
        proximo = atual->prox; 
        aux = lista; 
        while (aux != atual && aux->info < atual->info) { 
            aux = aux->prox;
        }
        if (aux != atual) { 
            anterior->prox = proximo; 
            atual->prox = aux; 
            if (aux == lista) { 
                lista = atual; 
            } else { 
                Lista *ant_aux = lista; 
                while (ant_aux->prox != aux) {
                    ant_aux = ant_aux->prox;
                }
                ant_aux->prox = atual;
            }
        } else { 
            anterior = atual; 
        }
        atual = proximo;
        }
    }
}





int main(){
    Lista *l1 = NULL;
    
    int n;
    
    if(vazia(l1)) printf("Lista vazia\n");
    while(scanf("%d", &n) && n != -1){
        l1 = inserirNoFinal(l1, n);
        printf("Elemento %d inserido com sucesso!\n", n);
    }
    printf("\n");
    
    printf("Lista completa (L1): ");
    
    imprimir(l1);
    
    ordena_lista_sem_cabeca(l1);
    
    printf("Lista completa (L1) ordenada: ");
    
    imprimir(l1);
    
    liberarLista(l1);
    
    l1 = NULL;

    return 0;
}



