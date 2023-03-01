#include <iostream>
using namespace std;

struct pilha{
    int v[10];
    int topo;
};

bool estavazia(pilha p){
    return p.topo<0;
}

bool estacheia(pilha p){
    return p.topo==9;
}

void push(pilha & p,int novoelemento){
    if(estacheia(p)){
        cout<<"Erro,pilha cheia!"<<endl;
    }else{
        p.topo++;
        p.v[p.topo]=novoelemento;  
    }
    
}

int top(pilha & p){
    if(estavazia(p)){
        cout<<"Erro,não há topo em pilha vazia!"<<endl;   
    }else{
        return p.v[p.topo];
    }
}

void pop(pilha & p){
  if(estavazia(p)){
      cout<<"Erro,a pilha esta vazia"<<endl;
  }else{
      p.topo--;
  }
}

int main(){
    pilha minhapilha;
    minhapilha.topo=-1;
    if(estavazia(minhapilha)){
        cout<<"pilha esta vazia!"<<endl;
    }
    push(minhapilha, 4);
    cout <<top(minhapilha)<<endl;
    push(minhapilha, 5);
    pop(minhapilha);
    push(minhapilha, 10);
    push(minhapilha, 9);
    push(minhapilha, 8);
    push(minhapilha, 7);
    push(minhapilha, 6);
    push(minhapilha, 5);
    push(minhapilha, 4);
    push(minhapilha, 3);
    push(minhapilha, 2);
    push(minhapilha, 1);
    push(minhapilha, 10);
    push(minhapilha, 10);
    push(minhapilha, 1);
    cout <<top(minhapilha)<<endl;
    pop(minhapilha);
    pop(minhapilha);
    if(estavazia(minhapilha)){
        cout<<"pilha esta vazia!"<<endl;
    }
    else{
        cout<<top(minhapilha);
    }
    return 0;
}
