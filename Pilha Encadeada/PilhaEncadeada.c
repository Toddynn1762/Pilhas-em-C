#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no {
    int valor;
    No *prox;
};

typedef struct pilha {
    No *topo;
} Pilha;

Pilha* criarPilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int isEmpty(Pilha *p) {
    return p->topo == NULL;
}

void push(Pilha *p, int valor) {
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = p->topo;
    p->topo = novoNo;
}

int pop(Pilha *p) {
    if(isEmpty(p)) {
        printf("Pilha vazia!");
        return '\0';
    }

    int valor = p->topo->valor;
    No *noAux = p->topo;
    p->topo = p->topo->prox;
    free(noAux);
    return valor;
}

void ordenarPilha(Pilha *p) {
    Pilha *pAux = criarPilha();

    while (!isEmpty(p)) {
        int valor = pop(p);

        while (!isEmpty(p) && pAux->topo->valor < valor) {
            push(p, pop(pAux));
        }
        push(p, pop(pAux));
    }
    while (!isEmpty(pAux)) {
        push(p, pop(pAux));
    }
    free(pAux);
}

int comparaTamanho(Pilha *p1, Pilha *p2) {
    int tamanhoP1 = 0;
    int tamanhoP2 = 0;

    No *noAux = p1->topo;
    while (noAux != NULL) {
        tamanhoP1++;
        noAux = noAux->prox;
    }

    noAux = p2->topo;
    while (noAux != NULL) {
        tamanhoP2++;
        noAux = noAux->prox;
    }

    if (tamanhoP1 > tamanhoP2) {
        return 1;
    } else if (tamanhoP1 < tamanhoP2) {
        return -1;
    } else {
        return 0;
    }
}

void mostrarInfo(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia\n");
        return;
    }

    No *noAux = p->topo;
    int maior = noAux->valor;
    int menor = noAux->valor;
    int soma = 0;
    int quantidade = 0;

    while (noAux != NULL) {
        int valor = noAux->valor;
        if (valor > maior) {
            maior = valor;
        }
        if (valor < menor) {
            menor = valor;
        }
        soma += valor;
        quantidade++;
        noAux = noAux->prox;
    }

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Media dos valores: %.2f\n", (float)soma / quantidade);
}

int mesmaMedia(Pilha *p1, Pilha *p2) {
    if (isEmpty(p1) || isEmpty(p2)) {
        printf("Uma das pilhas esta vazia!\n");
        return 0;
    }

    int somaP1 = 0;
    int somaP2 = 0;
    int quantidadeP1 = 0;
    int quantidadeP2 = 0;

    No *noAux = p1->topo;
    while (noAux != NULL) {
        somaP1 += noAux->valor;
        quantidadeP1++;
        noAux = noAux->prox;
    }

    noAux = p2->topo;
    while (noAux != NULL) {
        somaP2 += noAux->valor;
        quantidadeP2++;
        noAux = noAux->prox;
    }

    float mediaP1 = (float)somaP1 / quantidadeP1;
    float mediaP2 = (float)somaP1 / quantidadeP2;

    return mediaP1 == mediaP2;
}

void imprimePilha(Pilha *p) {
    if (isEmpty(p)) {
        printf("A pilha esta vazia\n");
        return;
    }

    No *noAux = p->topo;
    printf("Pilha:");
    while (noAux != NULL) {
        printf(" %d", noAux->valor);
        noAux = noAux->prox;
    }
    printf("\n");
}

int main() {
    Pilha *p1 = criarPilha();
    Pilha *p2 = criarPilha();

    push(p1, 10);
    push(p1, 5);
    push(p1, 8);

    push(p2, 10);
    push(p2, 5);
    push(p2, 8);

    ordenarPilha(p1);
    ordenarPilha(p2);

    switch (comparaTamanho(p1, p2)) {
    case 1:
        printf("\nA pilha 1 possui mais elementos que a pilha 2.\n");
        break;
    case -1:
        printf("\nA pilha 2 possui mais elementos que a pilha 1.\n");
        break;
    case 0:
        printf("As pilhas possuem o mesmo numero de elementos.\n");
        break;
    default:
        printf("Erro ao comparar as pilhas.\n");
    }

    printf("\nPilha 1 antes de ordenar:\n");
    mostrarInfo(p1);
    printf("\nPilha 2 antes de ordenar:\n");
    mostrarInfo(p2);

    if (mesmaMedia(p1, p2)) {
        printf("\nAs pilhas possuem a mesma media!\n");
    } else {
        printf("\nAs pilhas nao possuem a mesma media.\n");
    }

    printf("\nPilha 1 apos ordenacao:\n");
    imprimePilha(p1);

    printf("\nPilha 2 apos ordenacao:\n");
    imprimePilha(p2);

    free(p1);
    free(p2);

    return 0;
}
