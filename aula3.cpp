#include <iostream>
using namespace std;

struct pilha{
    int v[15];
    int topo;
};

void push(pilha & p,int ne){
    p.topo++;
    p.v[p.topo]=ne;
}
void pop(pilha & p){
    p.topo--;
}
int top(pilha p){
    return p.v[p.topo];
}

int main(){
  pilha p1,p2;
  p1.topo=-1;
  p2.topo=-1;
  cout<<"pilha 1:"<<endl;
  push(p1,3);
  push(p1,2);
  push(p1,4);
  cout<<top(p1)<<endl;
  pop(p1);
  cout<<top(p1)<<endl;
  pop(p1);
  cout<<top(p1)<<endl;
  cout<<"pilha 2:"<<endl;
  push(p2,1);
  push(p1,top(p2));
  cout<<top(p2)<<endl;
  pop(p2);
  push(p2,2);
  push(p1,top(p2));
  cout<<top(p2)<<endl;
  pop(p2);
  

}