#include <iostream>
#include <cstdlib>

using namespace std;

struct no{
    int valor;
    no * proximo;
};

no * inicio = NULL;

void insert(int pos, int novoValor){
    no * novoNo = (no * ) malloc(sizeof(no));
    novoNo-> valor = novoValor;
    if(pos == 0){
        if(inicio == NULL){
            inicio = novoNo;
            inicio->proximo = NULL;
        }else{
            novoNo->proximo = inicio;
            inicio = novoNo;
        }
    }else{
        no * aux = inicio;
        for(int i = 0; i < pos-1; i++){
            aux = aux->proximo;
        }
        if(aux->proximo == NULL){
            aux->proximo = novoNo;
            novoNo->proximo = NULL;
        }else{
            novoNo->proximo = aux->proximo;
            aux->proximo = novoNo;
        }
    }
}

int element(int pos){
    no * aux = inicio;
    for(int i = 0; i < pos; i++){
        aux = aux->proximo;
    }
    return aux->valor;
}

int pos(int elemento){
    no * aux = inicio;
    for(int i = 0; aux != NULL; i++){
        if(aux->valor == elemento){
            return i;
        }
        aux = aux->proximo;
    }
    return -1;
}

void remove(int pos){
    no * removido = NULL;
    if(pos == 0){
        removido = inicio;
        if(inicio->proximo == NULL){
            inicio = NULL;
        }else{
            inicio = inicio->proximo;
        }
    }else{
        no * aux = inicio;
        for(int i = 0; i < pos-1; i++){
            aux = aux->proximo;
        }
        removido = aux->proximo;
        aux->proximo = removido->proximo;
    }
    free(removido);
}

void imprime(){
    for(no * aux = inicio; aux!=NULL; aux=aux->proximo){
        cout << aux->valor << " ";
    }
    cout << endl;
}


int main()
{
    for(int i = 0; i < 10; i++){
        insert(i, i);
    }
    imprime();
    
    insert(0, 10);
    imprime();
    
    insert(5, 11);
    imprime();
    
    insert(2, 12);
    imprime();
    
    cout << "Elemento da posição 7: " << element(7) << endl;
    cout << "Posição do elemento 8: " << pos(8) << endl;
    
    remove(0);
    imprime();
    
    remove(5);
    imprime();
    
    remove(10);
    imprime();
    
    return 0;
}