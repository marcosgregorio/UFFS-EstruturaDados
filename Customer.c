#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Drink.h"
#include "Customer.h"

Customer *getMemoryC(Customer cli){
    Customer *c;
    c=(Customer*)malloc(sizeof(Customer));
    c->cod=cli.cod;
    strcpy(c->name,cli.name);
    c->cpf=cli.cpf;
    c->age=cli.age;
    c->ofAge=cli.ofAge;
	c->prev=NULL; c->next=NULL;
    return c;
}

void registerCustomer(SentinelC *st, Customer cli){
    Customer *c = getMemoryC(cli);
    if(!st->first){
        st->first=c;
        st->last=c;
    }else if(c->age < st->first->age){
        c->next = st->first;
        st->first->prev=c;
        st->first=c;
    }else{
        Customer *aux = st->first;
        for(; aux->next && c->age < aux->next->age;aux=aux->next);        
        c->next = aux->next;
        aux->next->prev = c;
        c->prev = aux;
        aux->next= c;        
    }
}

void printCustomers(Customer *cli, SentinelD *sr){
    printf("----------------------\n");
    Customer *aux;
    char alc;
    for (aux=sr->first;aux;aux=aux->next){
        alc=alc?"S":"N";
        printf("Codigo:%d\n",aux->cod);
        printf("Nome:%s\n",aux->name);
        printf("CPF:%d\n",aux->cpf);
        printf("Idade:%d\n",aux->age);
        printf("Maior de idade?%d\n",aux->ofAge);
    }
    printf("----------------------\n");
}
