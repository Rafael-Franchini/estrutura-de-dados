#include <iostream>
using namespace std;
struct lista{
    int v[10];
    int fim;
};

void insert(lista & l, int pos, int novoElemento){
    if(pos != l.fim){
        for(int i=l.fim;i>pos;i--){
            l.v[i]=l.v[i-1];
        }
    }
    l.v[pos]=novoElemento;
    l.fim++;
}

void imprime(lista l){
    for(int i=0;i<l.fim;i++){
        cout<<l.v[i]<<" ";
    }
    cout<<endl;
}

void remove(lista & l, int pos){
    if(pos!=l.fim-1){
        for(int i=pos;i<l.fim-1;i++){
            l.v[i]=l.v[i+1];
        }
    }
    l.fim--;
}

void menu(){
    cout<<"Menu"<<endl;
    cout<<"i: Insere na lista"<<endl;
    cout<<"r: Remove da lista"<<endl;
    cout<<"p: Procura elemento"<<endl;
    cout<<"e: Verifica uma posição"<<endl;
    cout<<"v: Imprime lista"<<endl;
    cout<<"s: Sair"<<endl;
    cout <<"Opcao:";
}

int element(lista l, int pos){
    return l.v[pos];
}

int pos(lista l, int elemento){
    for(int i=0;i<l.fim;i++){
        if(l.v[i] == elemento){
            return i;
        }
    }
    return -1;
}

int main(){
    lista ml;
    ml.fim=0;
    int posi,elemento;
    char op;

    while(true){
        menu();
        cin>>op;
        switch (op){
            case 'i':cout<<"Digite a posição que sera inserido: ";
                     cin>>posi;
                     cout<<"Digite o elemento a ser inserido: ";
                     cin>>elemento;
                     insert(ml,posi,elemento);
                    break;
            case 'r':cout<<"Qual a posiçao a ser removido: ";
                     cin>>posi;
                     remove(ml,posi);
                    break;
            case 'p':cout<<"Digiteo valor a se buscado: ";
                     cin>>elemento;
                     cout<<"Esta na posição: "<<pos(ml,elemento);
                    break;
            case 'e':cout<<"Digiteo a posiçao do elemento a ser vizualizado: ";
                     cin>>posi;
                     cout<<"Elemento na posição: "<<element(ml,posi);
                    break;
            case 'v':imprime(ml);
                    break;
            case 's':return 0;
                    break;
            default: cout<<"Opção invalida!!"<<endl;
        }
    }

}