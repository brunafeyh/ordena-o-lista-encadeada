#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no * prox;
};

typedef struct { // estrutura para lista encadeada com cabe¸ca e cauda
    struct no* cabeca;
} Lista;

void limpar_lista(Lista * l){
    if(l->cabeca != NULL){
        struct no * aux = l->cabeca->prox;
        free(l->cabeca);
        l->cabeca = aux;
        limpar_lista(l);
    }
    
    l->cabeca = NULL;
}

//Função para inicialiar_lista(Lista * l), cabeca = NULL e cauda = NULL
Lista * inicializar_lista(){
    Lista * l = (Lista*) malloc(sizeof(Lista));
    
    l->cabeca = NULL;
    
    return l;
}

int vazia(Lista * l){
    return (l == NULL || l->cabeca == NULL);
}

void imprimir(struct no * aux){
    if(aux != NULL){
        printf("%d ", aux->info);
        imprimir(aux->prox);
    }
}

Lista * inserir_cabeca(Lista * l, int info){
    struct no * aux = (struct no*) malloc(sizeof(struct no));
    
    aux->info = info;
    aux->prox = l->cabeca;
    l->cabeca = aux;
    
    return l;
}

// Função que ordena uma lista encadeada sem cabeça
void ordena_lista_com_cabeca(Lista *lista) {
    struct no *atual, *anterior, *proximo, *aux;
    if (lista != NULL && lista->cabeca != NULL) { // Verifica se a lista e a cabeça não são nulas
        atual = lista->cabeca->prox; 
        anterior = lista->cabeca; 
        while (atual != NULL) {
            proximo = atual->prox; 
            aux = lista->cabeca; 
            while (aux != atual && aux->info < atual->info) { 
                aux = aux->prox;
            }
            if (aux != atual) { 
                anterior->prox = proximo; 
                atual->prox = aux; 
                if (aux == lista->cabeca) { 
                    lista->cabeca = atual; 
                } else { 
                    struct no *ant_aux = lista->cabeca; 
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




int main()
{
    Lista * l1 = inicializar_lista();
    
    printf("Lista 1 é vazia? RESPOSTA: %d\n", vazia(l1));
    
    l1 = inserir_cabeca(l1, 1);
    l1 = inserir_cabeca(l1, 2);
    l1 = inserir_cabeca(l1, 3);
    l1 = inserir_cabeca(l1, 4);
    l1 = inserir_cabeca(l1, 5);
  
    printf("Lista 1: ");
    imprimir(l1->cabeca);
    printf("\n");
    
    ordena_lista_com_cabeca(l1);
    
    printf("Lista 1: ");
    imprimir(l1->cabeca);
    printf("\n");
    
    limpar_lista(l1);
    
    l1 = NULL;

    return 0;
}


