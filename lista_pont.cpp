#include <iostream>
#include <cstdlib>
using namespace std;
//estrutura
struct no{
    int valor;
    no * proximo;
};
//ponteiro para marcar o inicio...
no * inicio = NULL;
//adiciona valor na posição
void insert(int pos, int novoValor){
    no * novoNo = (no*)malloc(sizeof(no));
    novoNo -> valor = novoValor;
    //inserção na posição 0
    if(pos == 0){
    //se a lista estiver vazia...
        if(inicio == NULL){
            inicio = novoNo;
            inicio -> proximo = NULL;
        }
        //lista nao esta vazia
        else{
            novoNo -> proximo =inicio;
            inicio = novoNo;
        }
    }
    // posição maior que 0
    else{
        //localizar o elemento anterior da posição
        no * aux = inicio;
        for(int i = 0 ; i < pos-1 ; i++){
        aux = aux -> proximo;
        }
        //final da lista
        if(aux -> proximo == NULL){
        aux -> proximo = novoNo;
        novoNo -> proximo = NULL;
        }
        //meio da lista
        else{
        novoNo -> proximo = aux -> proximo;
        aux -> proximo = novoNo;
        }
    }
}
//retorna o elemento da posição
int element(int pos){
    no * aux = inicio;
    for(int i =0; i < pos; i++){
    aux = aux -> proximo;
    }
    return aux->valor;
}
//retorna a posição do valor
int pos(int elemento){
    no * aux = inicio;
    for(int i = 0; aux != NULL; i++){
        if(aux -> valor == elemento){
        return i;
        }
        aux = aux -> proximo;
    }
    return -1;
    }
//remove valor da posição
void remove(int pos){
    no * removido = NULL;
    if(pos == 0){
        removido = inicio;
        //removendo quando tem so 1 elemento
        if(inicio -> proximo == NULL){
            removido = inicio;
            inicio = NULL;
            }
        //remover um elemento na posição 0
        else{
            inicio = inicio -> proximo;
            }
    }
    else{
        no* aux = inicio;
        for(int i = 0; i < pos-1; i++){
        aux = aux -> proximo;
        } //remover do final e do inicio
        removido = aux -> proximo;
        aux -> proximo = removido -> proximo;
    }
    free (removido);
}
//imprime lista...
void imprime(){
    for(no * aux = inicio ; aux != NULL ; aux = aux -> proximo){
        cout << aux -> valor << " ";
    }
cout<<endl;
}
//principal

int main(){
    for(int i = 0; i < 10; i++){
    insert(i, i);
    }
    imprime();

    insert(0, 10);
    imprime();

    insert(5, 11);
    imprime();

    insert(2,12);
    imprime();

    cout << "Elemento da posição 7: " << element(7) << endl;
    cout << "Posiçao do elemento 8: " << pos(8) << endl;

    remove(0);
    imprime();

    remove(5);
    imprime();

    remove(10);
    imprime();

    return 0;
}