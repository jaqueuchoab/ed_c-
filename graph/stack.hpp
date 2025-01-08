#ifndef STACK_H
#define STACK_H
#include "node_vertex.hpp"

class Stack
{
public:
  Stack();  // Constructor
  ~Stack(); // Destructor
  bool isEmpty() const;
  bool isFull() const;
  void print() const;

  void push(VertexType);
  VertexType pop();

private:
  /*Apontará sempre para o elemento do topo, ou seja, o lugar a inserção*/
  NodeTypeVertex *structure;

};

#endif