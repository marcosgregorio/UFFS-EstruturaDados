#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
    struct no *anterior;
}No;

void inserir_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=*lista;
        novo->anterior = NULL;
        if(*lista!=NULL)
            (*lista)->anterior=novo;
        *lista=novo;
    }
    else
        printf("ERRO AO ALOCAR MEMÓRIA!\n");
}

void inserir_no_fim(No **lista, int num){
    No *novo,*aux = malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo = NULL;
        if(*lista==NULL){
            *lista = novo;
            novo->anterior=NULL;
        }else{
            aux=*lista;
            while(aux->proximo!=NULL)
                aux=aux->proximo;
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }else
        printf("ERRO AO ALOCAR MEMÓRIA!\n");
}

void inserir_no_meio(No **lista,int num, int ant){
    No *novo,*aux = malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        if(*lista==NULL){
             novo->proximo=NULL;
             novo->anterior=NULL;
             *lista = novo;
        }else{
            aux=*lista;
            while(aux->valor != ant && aux->proximo !=NULL)
                aux= aux->proximo;
            novo->proximo=aux->proximo;
            if(aux->proximo!=NULL)
                aux->proximo->anterior=novo;
            novo->anterior=aux;
            aux->proximo=novo;
        }
    }else
        printf("ERRO AO ALOCAR MEMÓRIA!\n");
}

void inserir_ordenado(No **lista,int num){
     No *novo,*aux = malloc(sizeof(No));
     if(novo){
         novo->valor=num;
         if(*lista==NULL){
             novo->proximo=NULL;
             novo->anterior=NULL;
             *lista=novo;
         }else if(novo->valor < (*lista)->valor){
             novo->proximo=*lista;
             (*lista)->anterior=novo;
             *lista=novo;
         }else{
             aux=*lista;
             while(aux->proximo!=NULL && novo->valor > aux->proximo->valor){
                 aux=aux->proximo;
             }
             novo->proximo=aux->proximo;
             if(aux->proximo)
                aux->proximo->anterior = novo;
             novo->anterior = aux;
             aux->proximo=novo;
         }
     }
     else
         printf("ERRO AO ALOCAR MEMÓRIA!\n");
 }

No *remover(No **lista, int num){
    No *aux, *remover=NULL;
    if(*lista!=NULL){
        if((*lista)->valor==num){
            remover=*lista;
            *lista=remover->proximo;
            if(*lista)
                (*lista)->anterior=NULL;
        }else{
            aux=*lista;
            while(aux->proximo&&aux->proximo->valor!=num)
                aux = aux->proximo;
            if(aux->proximo!=NULL){
                remover=aux->proximo;
                aux->proximo=remover->proximo;
                if(aux->proximo)
                    aux->proximo->anterior=aux;
            }
        }
    }
    return remover;
}

No* buscar(No **lista,int num){
    No *aux,*no=NULL;
    aux=*lista;
    while(aux!=NULL&&aux->valor!=num)
        aux=aux->proximo;
    if(aux!=NULL)
        no = aux;
    return no;
}

void imprimir(No *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d ",no->valor);
        no=no->proximo;
    }
    printf("\n\n");
}

No* ultimo_no(No **lista){
    No *aux=*lista;
    while(aux->proximo!=NULL)
        aux=aux->proximo;
    return aux;
}

void imprimir_contrario(No *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d ",no->valor);
        no=no->anterior;
    }
    printf("\n\n");  
}

int main(){
    int opc,valor,ant;
    No *removido,*lista=NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - inserirI\n\t2 - InserirF\n\t3 - inserirM\n\t4 - InserirO\n\t5 - Remover\n\t6 - imprimir\n\t7 - Buscar\n\t8 - imprimir ao contrario\n");
        scanf("%d",&opc);
        switch(opc){
            case 1:     
                printf("Digite um valor: ");
                scanf("%d",&valor);
                inserir_inicio(&lista,valor);
                break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d",&valor);
                inserir_no_fim(&lista,valor);
                break;
            case 3:
                printf("Digite um valor: ");
                scanf("%d,%d",&valor,&ant);
                inserir_no_fim(&lista,valor);
                break;
            case 4:
                printf("Digite um valor: ");
                scanf("%d,%d",&valor,&ant);
                 inserir_ordenado(&lista,valor);
                break;
            case 5:
                printf("Digite um valor a ser removido: ");
                scanf("%d",&valor);
                removido = remover(&lista,valor);
                if(removido){
                    printf("Elemento a ser removido: %d\n",removido->valor);
                free(removido);
                }else
                    printf("Elemento inexistente!\n");
                break;
            case 6:
                imprimir(lista);
                break;
            case 7: 
                printf("Digite um valor a ser buscado: ");
                scanf("%d",&valor);
                removido = buscar(&lista,valor);
                if(removido)
                    printf("Elemento encontrado: %d\n",removido->valor);
                else
                    printf("Elemento não encontrado!\n");
                break;
            case 8:
                imprimir_contrario( ultimo_no(&lista));
                break;
            default:
                if(opc!=0)
                    printf("opc invalida\n");
        }
    }while(opc!=0);        
    return 0;
}
