#include <iostream>
//Marco Antonio Ramirez Medellin
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *lista = NULL;

// Función para agregar un nuevo elemento a la lista
void insertarElemento(int data, Node *&p) {
    if (p == NULL) {
        p = new Node;
        p->data = data;
        p->next = NULL;
    } else {
        insertarElemento(data, p->next);
    }
}

// Función recursiva para buscar un elemento en la lista
bool buscarElemento(Node *lista, int x) {
    if (lista == NULL) {
        return false;
    }
    if (lista->data == x) {
        return true;
    }
    return buscarElemento(lista->next, x);
}

// Función recursiva para borrar un elemento en la lista
Node *deleteNode(Node *lista, int x) {
    if (lista == NULL) {
        return NULL;
    }
    if (lista->data == x) {
        Node *temp = lista->next;
        delete lista;
        return temp;
    }
    lista->next = deleteNode(lista->next, x);
    return lista;
}

// Función recursiva para imprimir la lista
void imprimirLista(Node *lista) {
    if (lista != NULL) {
        cout << lista->data << " ";
        imprimirLista(lista->next);
    } else return;

}

int main() {
    insertarElemento(1, lista);
    insertarElemento(2, lista);
    insertarElemento(3, lista);
    imprimirLista(lista);

    if (buscarElemento(lista, 3)) {
        cout << "\nElemento encontrado" << endl;
    } else {
        cout << "\nElemento no encontrado" << endl;
    }

    lista = deleteNode(lista, 1);
    imprimirLista(lista);

    
    return 0;
}