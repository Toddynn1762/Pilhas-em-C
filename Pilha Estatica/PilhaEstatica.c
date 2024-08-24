#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int topo, tamanho;
    float *valores;
}Pilha;

Pilha* criarPilha(int tam){

    Pilha *p = malloc(sizeof(Pilha));
    p ->topo = -1;
    p ->tamanho = tam;
    p ->valores = calloc(tam, sizeof(float));

    return p;
}

bool push(Pilha *p, float valor){

    p ->topo++;
    p ->valores[p ->topo] = valor;
}

float pop(Pilha *p){

    float aux = 0.0;

    aux = p -> valores[p ->topo];
    p ->topo--;

    return aux;
}

bool isEmpty(Pilha *p){

    return(p -> topo == -1);
}

bool isFull(Pilha *p){

    return(p -> topo == p -> tamanho -1);
}

int Pilha_a(Pilha *p){

    printf("A");
    push(p, 10.0);
    push(p, 5.0);
    push(p, 4.0);
    push(p, 2.0);
    push(p, 1.0);
}

int imprime_pilha(Pilha *p){

    while(!isEmpty(p)){
        printf("\n%.2f\n", pop(p));
    }
    printf("\n\n");
}

int main(){

    Pilha *p = criarPilha(5);
    Pilha *p2 = criarPilha(5);
    Pilha *aux = criarPilha(5);
    Pilha_a(p);

    while(!isEmpty(p)){
        push(aux, pop(p));
    }

    while(!isEmpty(aux)){
        float valor = pop(aux);
        push(p, valor);
        push(p2, valor);
    }

    imprime_pilha(p2);

    free(p->valores);
    free(p);

    return 0;

}
