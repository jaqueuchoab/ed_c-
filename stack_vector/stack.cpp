#include "stack.hpp"
#include <iostream>
#define MAX_ITEMS 10

using namespace std;

// Método construtor
Stack::Stack() {
  // Inicializando var legth e a estrutura linear com definição de tamanho da capacidade
  length = 0;
  structure = new ItemType[MAX_ITEMS];
}

// Destrutor, desaloca a estrutura linear
Stack::~Stack() {
  delete [] structure;
}

/*Verifica se a pilha está vazia*/
bool Stack::isEmpty() const {
  return (length == 0);
}

/*Verifica se a pilha está cheia*/
bool Stack::isFull() const {
  return (length == MAX_ITEMS);
}

/*Operação push, adicionar um novo elemento*/
void Stack::push(ItemType item) {
  if(item == ' ') return;
  // Verificando se a pilha está cheia ou não para que o limite de itens seja respeitado
  if(!isFull()) {
    /* 
    Inserir elementos na pilha se baseando na var de tamanho, 
    isso garantirá que sempre seja guardado um elemento em posições distintas no vetor 
    */
    
    structure[length] = item;
    // Incrementando o tamanho da pilha
    length++;
  } else {
    // Caso em que a pilha está cheia
    throw "Stack is already full | A pilha está cheia";
  }
}

/*Operação pop, remover o elemento do topo e retornar a informação contida nele*/
ItemType Stack::pop() {
  if(!isEmpty()) {
    // A var aux guarda o valor do último elemento inserido na pilha (o topo)
    ItemType aux = structure[length - 1];
    // Decrementando o tamanho da pilha
    length--;
    return aux;
  } else {
    throw "Stack is empty";
  }
}

/*Imprimi a pilha*/
void Stack::print() const{
  if(isEmpty()) {
    cout << "\n\nIs empty | Pilha vazia" << endl;
  } else {
    cout << "----------------\n";
    cout << "| PILHA LINEAR |\n";
    for(int i = 0; i < length; i++) {
      cout << "\n     [ " << structure[i] << " ]";
    }
    cout << "\n----------------";
  }
  cout << endl;
}