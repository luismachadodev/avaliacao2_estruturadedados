#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "metodos.h"

int main() {
    Lista *listaA = NULL;
    Lista *listaB = NULL;
    srand(time(NULL));

    for (int i = 0; i < 30; i++) {
        listaA = inserir(rand() % 100 + 1, listaA);
        listaB = inserir(rand() % 100 + 1, listaB);
    }

    cout << "\nLista A: ";
    exibir(listaA);

    cout << "\nLista B: ";
    exibir(listaB);

    exibirComuns(listaA, listaB);

    listaA = removerPares(listaA);
    cout << "\nLista A sem pares: ";
    exibir(listaA);

    Lista *listaUnida = unirListas(listaA, listaB);
    cout << "\nLista Unida A + B: ";
    exibir(listaUnida);

    listaUnida = ordenar(listaUnida);
    cout << "\nLista Unida Ordenada: ";
    exibir(listaUnida);

    listaUnida = limparLista(listaUnida);
    cout << "\nLista unida depois da limpeza: ";
    exibir(listaUnida);

    return 0;
}