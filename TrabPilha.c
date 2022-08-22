#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct url{
    char url[61];
    struct url *next;
}Url;

// typedef struct node{
//     Url p;
//     struct node *next;
// }Node;

typedef struct stack{
    Url *top;
}Stack;

void iniStack(Stack *stack){
    stack->top = NULL;
}

int emptyStack(Stack *stack){
    return (stack->top == NULL);
}

void push(Stack *stack, char url[61]){
    Url *new = (Url *)malloc(sizeof(Url));
    if(new){
        strcpy(new->url, url);
        new->next = stack->top;
        stack->top = new; 
    }
}

void freeStack(Stack *stack){
    if(emptyStack(stack)){
        printf("!");
    }else{
        Url *aux;
        while(stack->top){
            aux = stack->top;
            stack->top = stack->top->next;
            printf("@");
            free(aux);
        }
    }
}

void pop(Stack *stack){
    if(stack->top){
        Url *remove = stack->top;
        stack->top = remove->next;
        free(remove);
    }
}
int main(){
    Stack page;
    iniStack(&page);
    while(1){
        char url[61];
        scanf("%s",url);
        if(!strcmp(url,"B")){
            if(emptyStack(&page)){
                printf("Vazio\n");
            }else{
                printf("%s\n", page.top->url);
                pop(&page);
            }
        }else if(!strcmp(url,"E")){
            freeStack(&page);
            break;
        }else{
            push(&page,url);
        }
    }
    printf("\n");
    return 0;
}