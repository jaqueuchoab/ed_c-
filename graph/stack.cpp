#include "stack.hpp"
#include <iostream>

using namespace std;

Stack::Stack() {
  /*Definido como NULL pois não há a necessidade de inserir nada na pilha através do constructor*/
  structure = NULL;
}

/*Desaloca cada nova inserção*/
Stack::~Stack() {
  NodeTypeVertex* tempPont;

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
  NodeTypeVertex* location;

  try {
    /*Lógica: se for possivel alocar o novo nó e deleta-lo chegando até o return false, sem que seja executado o catch(exception) podemos concluir que a pilha não está vazia*/
    location = new NodeTypeVertex;
    delete location;
    return false;
  } catch(bad_alloc exception) {
    return true;
  }
}

/*Operação push, adicionar um novo nó*/
void Stack::push(VertexType item) {
  if(!isFull()) {
    /*Aloca um nó em qualquer lugar da memória*/
    NodeTypeVertex* location;
    location = new NodeTypeVertex;
    /*Indica as itemrmações e o próximo nó, que é o topo onde as operações serão feitas*/
    location->item = item;
    /*Nulo*/
    location->next = structure;
    /*Atualizando o structure para o novo topo da pilha, para que sempre o acesso seja ao último item adicionada a minha pilha*/
    structure = location;
  } else {
    throw "Stack is already full!";
  }
}

/*Operação pop, remover o nó/elemento do topo e retornar a itemrmação contida nele*/
VertexType Stack::pop() {
  if(!isEmpty()) {
    /*Ponteiro temporário que irá guardar o dado que está no topo da pilha, ou seja, o dado acessível no momento*/
    NodeTypeVertex* tempPont;
    /*A variável temporária agora aponta para o topo da pilha*/
    tempPont = structure;
    /*Acessando o dado contido em item - variável que guarda o valor alocado no topo da pilha*/
    VertexType item = structure->item;
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
  NodeTypeVertex* tempPont = structure;
  /*Enquanto tempPont, ou seja, topo não igual a nulo (caracteriza o fim da pilha)*/
  while(tempPont != NULL && !isEmpty()) {
    cout << tempPont->item.getNome();
    /*tempPont agora apontará para o próximo nó/elemento da pilha, seguirá desde que a condição do while seja satisfeita*/
    tempPont = tempPont->next;
  }

  if(isEmpty()) cout << "\nIs empty (pilha vazia)" << endl;
  cout << endl;
}