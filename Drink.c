#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Customer.h"
#include "Drink.h"

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
    char alc;
    for (aux=sr->first;aux;aux=aux->next){
        alc=alc?"S":"N";
        printf("Codigo:%d\n",aux->cod);
        printf("Nome:%s\n",aux->cod);
        printf("ml:%2.f\n",aux->cod);
        printf("Preco:%d\n",aux->cod);
        printf("Quantidade:%d\n",aux->cod);
        printf("Eh alcoolica:%c",alc);
    }
    printf("----------------------\n");
}

void buyDrinks(SentinelD *st, Drink *dr, int cod){
    Drink *aux;
    int amount;
    printf("----Quantas Bebidas deseja comprar?----\n");
    scanf("%d",&amount);
    for(aux=st->first;aux || aux->cod!=cod ;aux=aux->next);
        if(aux->cod==cod){
            //achou :)
            dr->stock+=amount;
        }
        else;
            //bebida não encontrada;
}

void sellDrinks(SentinelD *st, Drink *dr, Customer cli, int cod){
    Drink *aux;
    int amount;
    while (1){
        printf("----Quantas Bebidas deseja vender?----\n");
        scanf("%d",&amount);
        for(aux=st->first;aux || aux->cod!=cod ;aux=aux->next);
            if(aux->cod==cod){
                //achou :)
                if(amount>dr->stock){
                    printf("Quantidade da venda é superior a quantidade em estoque!\n");
                    printf("Insira uma quantidade válida!\n");
                    printf("Quantidade disponivel em estoque: %d",dr->stock);
                }else{
                    dr->stock -= amount;
                    printf("----Bebidas Vneidas com sucesso!----");
                    return;
                }
            }else{
                printf("Bebida não encontrada, insira um código válido\n");
            }
    }
    
}