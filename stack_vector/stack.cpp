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

/*Verifica se a pilha está vazia*/
bool Stack::isEmpty() const {
  /*Estará vazia se a structure for nulo*/
  return (structure == NULL);
}

/*Verifica se a pilha está cheia*/
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

/*Operação push, adicionar um novo nó*/
void Stack::push(ItemType item) {
  if(!isFull()) {
    /*Aloca um nó em qualquer lugar da memória*/
    NodeType* location;
    location = new NodeType;
    /*Indica as informações e o próximo nó, que é o topo onde as operações serão feitas*/
    location->info = item;
    /*Nulo*/
    location->next = structure;
    /*Atualizando o structure para o novo topo da pilha, para que sempre o acesso seja ao último item adicionada a minha pilha*/
    structure = location;
  } else {
    throw "Stack is already full!";
  }
}

/*Operação pop, remover o nó/elemento do topo e retornar a informação contida nele*/
ItemType Stack::pop() {
  if(!isEmpty()) {
    /*Ponteiro temporário que irá guardar o dado que está no topo da pilha, ou seja, o dado acessível no momento*/
    NodeType* tempPont;
    /*A variável temporária agora aponta para o topo da pilha*/
    tempPont = structure;
    /*Acessando o dado contido em item - variável que guarda o valor alocado no topo da pilha*/
    ItemType item = structure->info;
    /*Visto que a intenção é remover o topo da pilha, iremos definir um novo topo, que será o próximo elemento definido na estrutura*/
    structure = structure->next;
    /*Desalocar da memória o espaço que guardava o nó removido*/
    delete tempPont;
    return item;
  } else {
    throw "Stack is empty";
  }
}

/*Imprimi a pilha*/
void Stack::print() const{
  /*Ponteiro temporario que aponta para o topo da pilha*/
  NodeType* tempPont = structure;
  /*Enquanto tempPont, ou seja, topo não igual a nulo (caracteriza o fim da pilha)*/
  while(tempPont != NULL && !isEmpty()) {
    cout << tempPont->info;
    /*tempPont agora apontará para o próximo nó/elemento da pilha, seguirá desde que a condição do while seja satisfeita*/
    tempPont = tempPont->next;
  }

  if(isEmpty()) cout << "\nIs empty (pilha vazia)" << endl;
  cout << endl;
}