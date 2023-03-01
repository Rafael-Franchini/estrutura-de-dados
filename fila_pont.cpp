//bibliotecas...
#include <iostream>
#include<cstdlib>
using namespace std;
//estrutura
struct no{
  int valor;
  no * proximo;
};
//ponteiros inicio e fim
no * inicio= NULL;
no * fim = NULL;
//retorna primeiro valor
int first(){
  return inicio -> valor;
}
//retorna ultimo valor
int back(){
  return fim -> valor;
}
//colocar/enfileirar 
void enqueue(int novoValor){
  no * novoNo = (no*)malloc(sizeof(no));
  novoNo -> valor = novoValor;
  novoNo -> proximo = NULL;
  //se inicio estiver vazio criar valor apenas...
  if(inicio == NULL){
    inicio = novoNo;
    fim = novoNo;
  }
  //senao fazer final do primeiro elemento apontar o proximo ...
  else{
    fim -> proximo = novoNo;
    fim = novoNo;
  }
}
//retirar valor
void dequeue(){
  no * removido = inicio;
  //se o inicio for igual ao fim ele zera tudo... 
  if(inicio==fim){
    inicio = NULL;
    fim = NULL;
  }
  //senao colocar o proximo valor como inicio...
  else{
    inicio=inicio->proximo;
  }
  free(removido);
}
//função para imprimir fila
void imprimefila(){
  for(no * aux=inicio;aux!=NULL;aux=aux->proximo){
    cout<<aux->valor<<" ";
  }
  cout<<endl<<endl;
}
int main(){
  cout<<"FUNFO";
  enqueue(8);//ad 8
  enqueue(10);// ad 10
  enqueue(12);//ad 12
  cout<<first()<<endl;//retorna primeiro valor
  enqueue(14);// ad 14
  imprimefila();
  dequeue();// retira primeiro valor
  cout<<first()<<endl;//retorna primeiro valor
  dequeue();// retira primeiro valor
  dequeue();// retira primeiro valor
  cout<<"inicio = "<<first()<<",final ="<<back()<<endl;// mostra primeiro e ultimo valor
}

  