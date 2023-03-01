
/*1)_________________________________________

// bibliotecas...
#include <iostream>
#include <cstdlib>
using namespace std;
// estrutura
struct no
{
  int valor;
  no *proximo;
};
// ponteiros inicio e fim
no *inicio = NULL;
no *fim = NULL;
// retorna primeiro valor
int first()
{
  return inicio->valor;
}
// retorna ultimo valor
int back()
{
  return fim->valor;
}
// colocar/enfileirar
void enqueueFrente(int novoValor)
{
  no *novoNo = (no *)malloc(sizeof(no));
  novoNo->valor = novoValor;
  novoNo->proximo = inicio;
  // se inicio estiver vazio criar valor apenas...
  if (inicio == NULL)
  {
    inicio = novoNo;
    fim = novoNo;
  }
  // senao fazer final do primeiro elemento apontar o proximo ...
  else
  {
    no *antigoInicio = inicio;
    inicio = novoNo;
    inicio->proximo = antigoInicio;
  }
}

void enqueueTras(int novoValor)
{
  no *novoNo = (no *)malloc(sizeof(no));
  novoNo->valor = novoValor;
  novoNo->proximo = NULL;
  // se inicio estiver vazio criar valor apenas...
  if (inicio == NULL)
  {
    inicio = novoNo;
    fim = novoNo;
  }
  // senao fazer final do primeiro elemento apontar o proximo ...
  else
  {
    fim->proximo = novoNo;
    fim = novoNo;
  }
}

// retirar valor
void dequeueTras()
{
  // no *removido = inicio;
  // se o inicio for igual ao fim ele zera tudo...
  if (inicio == fim)
  {
    inicio = NULL;
    fim = NULL;
  }
  // senao colocar o proximo valor como inicio...
  else
  {
    // inicio = inicio->proximo;
    for (no *aux = inicio; aux != NULL; aux = aux->proximo)
    {
      if (aux->proximo == fim)
      {
        // cout << "penultimo elemento" << aux->valor << endl;
        no *removido = fim;
        fim = aux;
        fim->proximo = NULL;
        free(removido);
      }
    }
  }
}

void dequeueFrente()
{
  no *removido = inicio;
  // se o inicio for igual ao fim ele zera tudo...
  if (inicio == fim)
  {
    inicio = NULL;
    fim = NULL;
  }
  // senao colocar o proximo valor como inicio...
  else if (fim)
  {
    inicio = inicio->proximo;
  }
  free(removido);
}

// função para imprimir fila
void imprimefila()
{
  for (no *aux = inicio; aux != NULL; aux = aux->proximo)
  {
    cout << aux->valor << " ";
  }
  cout << endl
       << endl;
}
int main()
{
  cout << "FUNFO" << endl;
  enqueueFrente(8);
  imprimefila();
  enqueueFrente(7);
  imprimefila();
  enqueueTras(9);
  imprimefila();
  enqueueTras(10);
  imprimefila();
  dequeueFrente();
  imprimefila();
  dequeueTras();
  imprimefila();
  dequeueTras();
  imprimefila();
  // enqueue(8);              // ad 8
  // enqueue(10);             // ad 10
  // enqueue(12);             // ad 12
  // cout << first() << endl; // retorna primeiro valor
  // enqueue(14);             // ad 14
  // imprimefila();
  // dequeue();                                                      // retira primeiro valor
  // cout << first() << endl;                                        // retorna primeiro valor
  // dequeue();                                                      // retira primeiro valor
  // dequeue();                                                      // retira primeiro valor
  // cout << "inicio = " << first() << ",final =" << back() << endl; // mostra primeiro e ultimo valor
}

//_________________________________________
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

void trocapos(int pos1, int pos2)
{

    for (no *aux = inicio; aux != NULL; aux = aux->proximo)
    {
        if (aux->valor == pos1)
        {
            aux->valor = pos2;
        }
        else if (aux->valor == pos2)
        {
            aux->valor = pos1;
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
    
    cout << "Elemento da posicao 7: " << element(7) << endl;
    cout << "Posicao do elemento 8: " << pos(8) << endl;
    
    remove(0);
    imprime();
    
    remove(5);
    imprime();

    trocapos(0, 12);
    imprime();

    trocapos(12, 7);
    imprime();
    
    return 0;
}




//_________________________________________
#include <iostream>
#include <cstdlib>
using namespace std;
struct no
{
    int valor;
    no *proximo;
};
no *inicio = NULL;
no *fim = NULL;

int first()
{
    return inicio->valor;
}

int back()
{
    return fim->valor;
}

void enqueue(int novoValor)
{
    int totalFila = 0;
    for (no *aux = inicio; aux != NULL; aux = aux->proximo)
    {
        totalFila += aux->valor;
    }
    if (novoValor < totalFila || inicio == NULL)
    {

        no *novoNo = (no *)malloc(sizeof(no));
        novoNo->valor = novoValor;
        novoNo->proximo = NULL;

        if (inicio == NULL)
        {
            inicio = novoNo;
            fim = novoNo;
        }

        else
        {
            fim->proximo = novoNo;
            fim = novoNo;
        }
    }
}

void dequeue()
{
    no *removido = inicio;

    if (inicio == fim)
    {
        inicio = NULL;
        fim = NULL;
    }

    else
    {
        inicio = inicio->proximo;
    }
    free(removido);
}

void imprimefila()
{
    for (no *aux = inicio; aux != NULL; aux = aux->proximo)
    {
        cout << aux->valor << " ";
    }
    cout << endl
         << endl;
}

int main()
{
    enqueue(8); // ad 8
    imprimefila();
    enqueue(7); // ad 10
    imprimefila();
    enqueue(12); // ad 12
    imprimefila();
    cout << first() << endl; // retorna primeiro valor
    enqueue(14);             // ad 14
    imprimefila();
    dequeue(); // retira primeiro valor
    imprimefila();
    cout << first() << endl; // retorna primeiro valor
    dequeue();               // retira primeiro valor
    imprimefila();
    dequeue(); // retira primeiro valor
    imprimefila();
    cout << "inicio = " << first() << ",final =" << back() << endl; // mostra primeiro e ultimo valor
}

//4)_________________________________________
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


*/