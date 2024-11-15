#ifndef QUEUE_H
#define QUEUE_H
#include "node.hpp"

class Queue
{
public:
  Queue(); // Construtor
  ~Queue(); // Destrutor
  bool isEmpty() const;
  bool isFull() const;
  void print() const;

  void enqueue(ItemType);
  ItemType dequeue();

private:
  // Ponteiro da primeiro elemento da fila
  NodeType *front;
  // Ponteiro para o último elemento da fila
  NodeType *rear;
};

#endif