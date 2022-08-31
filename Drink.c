#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Customer.h"
#include "Drink.h"

/**
 * função generica de alocação de memoria
 * e valores
 */
Drink *getMemoryD(Drink dr){
    Drink *d;
    d=(Drink*)malloc(sizeof(Drink));
    d->cod=dr.cod;
    strcpy(d->name,dr.name);
    d->ml=dr.ml;
    d->price=dr.price;
    d->stock=dr.stock;
    d->alchoolic=dr.alchoolic;
	d->prev=NULL; d->next=NULL;
    return d;
}

/**
 * Insere a bebida no 
 * inicio da lista encadeada 
 */
void registerDrink(SentinelD *st, Drink dr){
    Drink *d = getMemoryD(dr);
    if(!st->first){
        st->first=d;
        st->last=d;
    }else{
        d->next = st->first;
        st->first->prev = d;
        st->first = d;
    }
}

void printDrinks(Drink *dr, SentinelD *sr){
    printf("----------------------\n");
    Drink *aux;
    char value[2];
    for (aux=sr->first;aux;aux=aux->next){
        value[0]=aux->alchoolic?'S':'N';
        printf("Codigo:%d\n",aux->cod);
        printf("Nome: %s\n",aux->name);
        printf("ml: %2.f\n",aux->ml);
        printf("Preco: %2.f\n",aux->price);
        printf("Quantidade: %d\n",aux->stock);
        printf("Eh alcoolica: %s\n",value);
    }
    printf("----------------------\n");
}
/**
 * função para aumentar a quantidade de bebidas em estoque
 */
void buyDrinks(SentinelD *st, Drink *dr){
    Drink *aux;
    int amount= 0;
    int cod = 0;
    do{ 
        printf("Digite o codigo da bebida");
        scanf("%d",&cod);
        printf("----Quantas Bebidas deseja comprar?----\n");
        scanf("%d",&amount);
        if(amount<=0) printf("Quantidade invalida");
        for(aux=st->first;aux && aux->cod!=cod ;aux=aux->next);
        if(!aux){
            printf("Bebida não encontrada ;(\n");
        }
    }while(amount<=0&&!aux);
    aux->stock+=amount;
}

Drink *searchBooze(SentinelC *stC,int cpf,SentinelD *stD,int cod){
    Drink *aux=stD->first;
    Customer *aux2=stC->first;
    for(;aux2 && aux2->cpf!=cpf;aux2=aux2->next);
    if(!aux2){
        printf("Cliente não encontrado :(\n");
        return 0;
    }
    if(aux->cod==stD->first->cod){
        if(aux->alchoolic && !aux2->ofAge){
            printf("Está bebida é somente para maiores\n");
            return 0;
        }
        return aux;
    }
    for(;aux && aux->cod!=cod ;aux=aux->next);
    if(aux->cod==cod){
        if(aux->alchoolic && !aux2->ofAge){
            printf("Está bebida é somente para maiores\n");
            return 0;
        }
        return aux;
    }
    printf("Bebida não encontrada\n");
    return 0;    
}

void sellDrinks(SentinelD *stD, Drink *dr){
    Drink *aux;
    SentinelC *stC;
    stC->first=NULL;
    stC->last=NULL;
    int amount = 0;
    int cpf;
    int cod;
    do{
        printf("Digite um código de uma bebida: \n");
        scanf("%d",&cod);
        printf("Digite o CPF do cliente: ");
        scanf("%d",&cpf);
        aux = searchBooze(stC,cpf,stD,cod);
    }while(!aux);
    while(1){
        printf("----Quantas Bebidas deseja vender?----\n");
        scanf("%d",&amount);
        if(amount<=0){
            printf("Digite uma quantidade válida!\n");
        }else if(amount>aux->stock){
            printf("Quantidade da venda é superior a quantidade em estoque!\n");
            printf("Insira uma quantidade válida!\n");
            printf("Quantidade disponivel em estoque: %d",aux->stock);
        }else{
            aux->stock -= amount;
            printf("----Bebidas vendidadas com sucesso!----");
            return;
        }
    }
}