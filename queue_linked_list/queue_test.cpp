#include <iostream>
#include "queue.hpp"

using namespace std;

int main() {
  char character;
  Queue queue;
  char queueChar;

  cout << "Adicione uma string: " << endl;
  cin.get(character);

  // Enquanto o caracter inserido não for uma quebra de linha e a fila não estiver cheia
  while(character != '\n' and !queue.isFull()) {
    // Acontecerá o enfileiramento 
    queue.enqueue(character);
    // Realiza a leitura
    cin.get(character);
  }

  /*Imprimindo a pilha antes das remoções*/
  cout << "\nFila atual: ";
  queue.print();
  
  // Enquanto a fila não for vazia
  while (!queue.isEmpty())
  {
    // Acontecerá o desinfileiramento
    queueChar = queue.dequeue();
    // Imprimindo o elemento que está removido
    cout << "\nItem removido: ";
    cout << queueChar;
  }
  cout << endl;

  /*Imprimindo a pilha após as remoções*/
  cout << "\nFila após remoções: ";
  queue.print();
}
