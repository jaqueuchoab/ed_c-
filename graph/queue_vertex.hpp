#ifndef QUEUE_VERTEX_H
#define QUEUE_VERTEX_H
#include "node_vertex.hpp"

class QueueVertex
{
public:
  QueueVertex(); // Construtor
  ~QueueVertex(); // Destrutor
  bool isEmpty() const;
  bool isFull() const;
  void print() const;

  void enqueueVertex(VertexType);
  VertexType dequeueVertex();

private:
  // Ponteiro da primeiro elemento da fila
  NodeTypeVertex *front;
  // Ponteiro para o último elemento da fila
  NodeTypeVertex *rear;
};

#endif