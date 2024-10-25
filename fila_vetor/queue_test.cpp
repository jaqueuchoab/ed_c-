#include "queue.hpp"
#include <iostream>

using namespace std;

int main() {
  char character;
  Queue queue;
  char queueChar;

  cout << "Adicione uma string: " << endl;
  cin.get(character);

  while(character != '\n' and !queue.isFull()) {
    queue.enqueue(character);
    cin.get(character);
  }

  queue.dequeue();
  queue.print();
}