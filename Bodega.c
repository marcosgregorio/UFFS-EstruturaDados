#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Customer.h"
#include "Drink.h"

void initSentinels(SentinelD *senD, SentinelC *senC){
	senD->first=NULL;
    senD->last=NULL;
    //
	senC->first=NULL;
	senC->last=NULL;
}
int emptyDrinkList(SentinelD *stD){
    return (!stD->first);
}

int emptyCustomersList(SentinelC *stC){
    return (!stC->first);
}

void exitSystem(SentinelD *stDri, SentinelC *stCus){
    Drink *auxDri = stDri->first;
    Customer *auxCus = stCus->first;
    while (auxDri != NULL){
        auxDri = auxDri->next;
        free(stDri->first);
        stDri->first = auxDri;
        printf("@");
    }
    while (auxCus != NULL){
        auxCus = auxCus->next;
        free(stCus->first);
        stCus->first = auxCus;
        printf("@");
    }
    printf("\n\n");
    printf("OBRIGADO POR USAR O SISTEMA DA BODEGA DO SEU JOÃOZIN!!\n");
    printf("O Sistema da bodega do Seu Joãozin só foi possível\n de ser feita com a ajuda dos programadores Júniores Dênio Duarte e Geomar Schreiner\n");
    printf("E com a supervisão do Desenvolvedor Sênior Marcos!\n");
}

int main (){
    SentinelD senD;
    SentinelC senC;
    int opc;
    initSentinels(&senD, &senC);
    // initBoteco();
    do{ 
        printf("----------------------\n");
        printf("1 - Registrar bebida\n2 - Mostrar bebidas\n3 - Comprar bebidas\n4 - Vender bebidas\n5 - Cadastrar cliente\n6 - Mostrar Clientes\n0 - Sair do sistema");
        printf("\n");
        scanf("%d",&opc);
        switch (opc){
            case 1:
                Drink dr;
                printf("Insira o codigo da bebida:");
                scanf("%d",&dr.cod);
                printf("Digite o nome da bebida:");
                scanf("%s",dr.name);
                do{
                    printf("Quantos Ml");
                    scanf("%f",&dr.ml);
                    if(dr.ml<=0) printf("insira um valor valido!\n");
                }while(dr.ml<=0);
                do{
                    printf("Qual o valor da bebida?");
                    scanf("%f",&dr.price);
                    if(dr.price<=0) printf("insira um valor valido!\n");
                }while(dr.price<=0);
                do{
                    printf("Quantidade em estoque:");
                    scanf("%d",&dr.stock);
                    if(dr.stock<=0) printf("insira um valor valido!\n");
                }while(dr.stock<=0);
                printf("Ela é alcóolica? Digite [0] para não, qualquer outro valor númerico para sim.");
                scanf("%d",&dr.alchoolic);
                registerDrink(&senD,dr);
                break;
            case 2:
                if(emptyDrinkList(&senD)){
                    printf("catalago de bebidas vazio!\n");
                    break;
                }
                printDrinks(&dr,&senD);
                break;
            case 3:
                if(emptyDrinkList(&senD)){
                    printf("catalago de bebidas vazio!\n");
                    break;
                }
                buyDrinks(&senD, &dr);
                break;
            case 4:
                if(emptyDrinkList(&senD)){
                    printf("catalago de bebidas vazio!\n");
                    break;
                }else if(emptyCustomersList(&senC)){
                    printf("Lista de clientes vázia :(\n");
                    break;
                }             
                sellDrinks(&senD, &dr);
                break;
            case 5:
                Customer cli;
                printf("Digite o codigo do cliente:");
                scanf("%d", &cli.cod);
                printf("Digite o nome do cliente:");
                scanf("%s", cli.name);
                do{
                    printf("Digite o CPF do cliente:");
                    scanf("%d", &cli.cpf);
                    if(cli.cpf<=0) printf("insira um valor valido!\n");
                }while(cli.cpf<=0);
                do{
                    printf("Digite a idade do cliente");
                    scanf("%d",&cli.age);
                    if(cli.age<=5) printf("Você deve ter pelo mais de 5 anos pare se registrar no nosso sistema!\n");
                }while(cli.age<=5);
                if(cli.age>=18) cli.ofAge = 1;
                else cli.ofAge = 0;
                registerCustomer(&senC, cli);
                break;
            case 6:
                printCustomers(&cli,&senC);
                break;
            case 0:
                exitSystem(&senD,&senC);
            default:
                printf("Valor invalido");
        }
    }while(opc!=0);
       
    // registerDrink(*st,  dr);
    // Mostrar bebidas;
    // Comprar bebida;
    // Vender bebida;
    // Cadastrar cliente;
    // Mostrar clientes;
    // Sair do sistema;
    return 0;
}