#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
} Lista;

bool localizar(int valor, Lista *lista) {
    Lista *p;
    for (p = lista; p; p = p->prox) {
        if (valor == p->dado)
            return true;
    }
    return false;
}

Lista *inserir(int valor, Lista *lista) {
    Lista *novo = (Lista*)malloc(sizeof(Lista));

    novo->dado = valor;
    novo->prox = NULL;

    Lista *p, *pR;
    for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
        if (valor == p->dado) {
            free(novo);
            return lista;
        }
        if (valor < p->dado)
            break;
    }

    if (p == lista) {
        novo->prox = p;
        return novo;
    }
    if (!p) {
        pR->prox = novo;
        return lista;
    }

    pR->prox = novo;
    novo->prox = p;
    return lista;
}

void exibir(Lista *lista) {
    Lista *p;
    for (p = lista; p; p = p->prox) {
        cout << p->dado << " ";
    }
    cout << endl;
}

int contar(Lista *lista) {
    Lista *p;
    int qtd = 0;
    for (p = lista; p; p = p->prox)
        qtd++;
    return qtd;
}

void exibirComuns(Lista *a, Lista *b) {
    Lista *p;
    
    cout << "Numeros comuns: ";
    for (p = a; p; p = p->prox) {
        if (localizar(p->dado, b)) {
            cout << p->dado << " ";
        }
    }
    cout << endl;
}

Lista *removerPares(Lista *lista) {
    Lista *p = lista;
    Lista *ant = NULL;

    while (p) {
        if (p->dado % 2 == 0) {
            Lista *remover = p;
            if (p == lista) {
                lista = p->prox;
                p = lista;
            } else {
                ant->prox = p->prox;
                p = p->prox;
            }
            free(remover);
        } else {
            ant = p;
            p = p->prox;
        }
    }
    return lista;
}

Lista *unirListas(Lista *a, Lista *b) {
    Lista *nova = NULL;
    Lista *p;
    for (p = a; p; p = p->prox) {
        nova = inserir(p->dado, nova);
    }
    for (p = b; p; p = p->prox) {
        nova = inserir(p->dado, nova);
    }
    return nova;
}

Lista *ordenar(Lista *lista) {
    return lista;
}

Lista *limparLista(Lista *lista) {
    Lista *p = lista;
    while (p) {
        Lista *aux = p;
        p = p->prox;
        free(aux);
    }
    cout << "-- A lista foi limpa. --";
    return NULL;
}
