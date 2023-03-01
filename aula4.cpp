#include <iostream>
using namespace std;

struct fila{
    int v[10];
    int inicio;
    int fim;
};

void enqueue(fila & f,int novoElemento){
    f.v[f.fim]=novoElemento;
    if(f.fim+1<10){
        f.fim++;
    }
    else if(f.inicio<0){
        f.fim=0;
    }
    
}

bool estacheia(fila f){
    return(f.inicio==0 && f.fim==9)||(f.fim+1==f.inicio);
}

bool estavazia(fila f){
    return f.inicio==f.fim;
}

//metodo canonico
void imprimefila(fila f){
    for(int i =f.inicio;i<f.fim;i++){
        cout<<f.v[i]<<" ";
    }
    cout<<endl;
}

int first(fila f){
    return f.v[f.inicio];
}

void dequeue(fila & f){
    if(f.inicio+1<10){f.inicio++;}
    else{f.inicio=0;}
}

int main(){
    fila fn;
    fn.inicio=fn.fim=0;
    imprimefila(fn);
    enqueue(fn,3);
    enqueue(fn,5);
    enqueue(fn,9);
    enqueue(fn,2);
    imprimefila(fn);
    cout<<first(fn)<<endl;
    dequeue(fn);
    cout<<first(fn)<<endl;
    imprimefila(fn);
}