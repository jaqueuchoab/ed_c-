#include "queue.hpp"
#include <iostream>

using namespace std;
const int  MAX_ITEMS = 8;


Queue::Queue() {
  // Posição do elemento da frente da fila, o front irá crescer além do tamanho do vetor
  front = 0;
  // Posição do elemento atrás da fila
  back = 0;
  // Structure é um vetor de char
  structure = new ItemType[MAX_ITEMS];
}

// Desaloca tudo que o construtor alocou
Queue::~Queue() {
  delete [] structure;
}

bool Queue::isEmpty() const {
  // A lógica é que se eles forem iguais não há nenhum elemento na fila, visto que o back aponta para o espaço após o último elemento inserido.
  return (front == back);
}

bool Queue::isFull() const {
  // A fila só estará cheia se todas as posições estiverem ocupadas
  // A operação de subtração indicará qual o tamanho do vetor, e se esse tamanho for igual a constante, ele está cheio pois ela indica o limite.
  return (back - front == MAX_ITEMS);
}

void Queue::enqueue(ItemType item) {
  if(!isFull()) {
    // Seguindo a lógica de que o vetor é circular, por usando o módulo para indicar a posição de inserção
    structure[back % MAX_ITEMS] = item;
    back++;
  } else {
    throw "Queue is full";
  }
}

ItemType Queue::dequeue() {
  if(!isEmpty()) {
    front++;
    return structure[(front - 1) % MAX_ITEMS];
  } else {
    throw "Queue is empty";
  }
}

void Queue::print() const {
  cout << "Fila = ";
  for (int i = front; i < back; i++) {
    cout << structure[i % MAX_ITEMS];
  }

  cout << endl;
}