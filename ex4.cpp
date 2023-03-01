//bibliotecas...
#include <iostream>
#include<cstdlib>
using namespace std;
//estrutura
struct no{
  int valor;
  no * anterior;
};
no*topo=NULL;
void push(int valor){
    no*novoNo=(no*)malloc(sizeof(no));
    novoNo->valor=valor;
    if(topo==NULL){
        novoNo->anterior=NULL;
    }else{
        novoNo->anterior=topo;
    }
    topo=novoNo;
}
int top(){
    if(topo==NULL){
        cout<<"Pilha vazia, sem topo"<<endl;
    }else{
        return topo->valor;
    }
}
void pop(){
    if(topo==NULL){
        cout<<"ta vazia"<<endl;
    }
    else{
        no*aux=topo;
        topo=topo->anterior;
        free(aux);
    }
}
void imprimepilha(){
    if(topo!=NULL){
        for(no*aux=topo;aux!=NULL;aux=aux->anterior){
            cout<<aux->valor<<" ";
        }   
    }
    else{
        cout<<"Pilha vazia";
    }
    cout<<endl;
}
int main(){
    top();
    push(10);
    cout<<top()<<endl;
    pop();
    imprimepilha();
}