#ifndef STACK_H
#define STACK_H
#include "item_type.hpp"

class Stack
{
public:
  Stack();  // Constructor
  ~Stack(); // Destructor
  bool isEmpty() const;
  bool isFull() const;
  void print() const;

  void push(ItemType);
  ItemType pop();

private:
  // Var para auxiliar no tamanho da pilha
  int length;
  // Estrutura linear que irá guardar cada elemento da pilha
  ItemType* structure;
};

#endif