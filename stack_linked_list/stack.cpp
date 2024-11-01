#include "stack.hpp"
#include <iostream>

using namespace std;

Stack::Stack() {
  /*Definido como NULL pois não há a necessidade de inserir nada na pilha através do constructor*/
  structure = NULL;
}

/*Desaloca cada nova inserção*/
Stack::~Stack() {
  NodeType* tempPont;

  /*Percorrerá cada nó da estrutura deletando cada um, até que não haja nó*/
  while(structure != NULL) {
    /*Aponta para a nó atual, de inicio a 'cabeça', guarda temporáriamente*/
    tempPont = structure;

    /*structure passa a apontar para o nó seguinte, pois o atual está em tempPont*/
    structure = structure -> next;

    /*Deleta o nó atual guardado em tempPont*/
    delete tempPont;
  }
}

bool Stack::isEmpty() const {
  /*Estará vazia se a structure for nulo*/
  return (structure == NULL);
}

bool Stack::isFull() const {
  NodeType* location;

  try {
    /*Lógica: se for possivel alocar o novo nó e deleta-lo chegando até o return false, sem que seja executado o catch(exception) podemos concluir que a pilha não está vazia*/
    location = new NodeType;
    delete location;
    return false;
  } catch(bad_alloc exception) {
    return true;
  }
}

void Stack::push(ItemType item) {
  if(!isFull()) {
    /*Aloca um nó em qualquer lugar da memória*/
    NodeType* location;
    location = new NodeType;
    /*Indica as informações e o próximo nó, que é o topo onde as operações serão feitas*/
    location->info = item;
    /*Nulo*/
    location->next = structure;
    /*Atualizando o structure para o novo topo da pilha*/
    structure = location;
  } else {
    throw "Stack is already full!";
  }
}