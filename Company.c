#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Drink.h"
#include "Company.h"

Company registerBodega(){
    Company empresa;
    strcpy(empresa.name,"Unicornio Saltiante");
    empresa.cnpj = 4242424242;
    return empresa;
//     Company bodega;
//     printf("SAUDAÇÕES, ESTAMOS INICIANDO O SISTEMA DO BODEGA!!\n");
//     printf("Insira nome e o CNPJ da sua bodega!!\n");
//     scanf("%s",bodega.name);
//     scanf("%d",&bodega.cnpj);
//     printf("INICIANDO O SISTEMA DA BODEGA: %s\n",bodega.name);
//     printf("CNPJ: %d\n",bodega.cnpj);
//     return bodega;
}