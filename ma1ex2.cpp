#include <iostream>
using namespace std;
struct lista{
    int v[10];
    int fim;
    int inicio;
};

void push_front(lista & l, int novoElemento){
    if(l.inicio != l.fim){
        for(int i=l.fim;i>l.inicio;i--){
            l.v[i]=l.v[i-1];
        }
    }
    l.v[l.inicio]=novoElemento;
    l.fim++;
}
void push_back(lista & l, int novoElemento){
    l.v[l.fim]=novoElemento;
    l.fim++;
}

void back(lista l){
    cout<<l.v[l.fim-1]<<" ";
    cout<<endl;
}
void front(lista l){
    cout<<l.v[l.inicio]<<" ";
    cout<<endl;
}

void pop_back(lista & l){
    l.fim--;
}
void pop_front(lista & l){
    l.inicio++;
}
void imprime(lista l){
    for(int i=l.inicio;i<l.fim;i++){
        cout<<l.v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    lista d;
    d.fim=0;
    d.inicio=0;
    
    push_back(d, 0);
    imprime(d);
    push_back(d, 1);
    imprime(d);
    push_front(d, 2);
    imprime(d);
    push_front(d, 3);
    imprime(d);
    pop_back(d);
    imprime(d);
    back(d);
    pop_front(d);
    imprime(d);
    front(d);
}