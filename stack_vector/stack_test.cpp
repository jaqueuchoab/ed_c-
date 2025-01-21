#include "stack.hpp"
#include <iostream>

using namespace std;

int main() {
  /*Receberá dado a ser adicionado*/
  ItemType character;
  /*Instanciando a pilha*/
  Stack stack;
  /*Receberá o item/info do dado guardado no topo da pilha*/
  ItemType stackItem;

  /*Leitura de uma string, um conjunto de caracteres que irão compor a pilha*/
  cout << "Adicione uma string: " << endl;
  cin.get(character);
  /*Enquanto o prenchimento for diferente da quebra de linha, a leitura irá continuar e os caracteres serão constantemente adicionados à pilha*/
  while(character != '\n') {
    /*Acessando função push*/
    stack.push(character);
    cin.get(character);
  }

  /*Imprimindo a pilha antes das remoções*/
  cout << "\nPilha atual: ";
  stack.print();
  
  /*Enquanto a pilha não estiver vazia a operação pop (remoção de elementos) acontecerá*/
  while(!stack.isEmpty()) {
    stackItem = stack.pop();
    cout << "\nItem removido: ";
    cout << stackItem;
  }

  /*Imprimindo a pilha após as remoções*/
  cout << "\n\nPilha após remoções: ";
  stack.print();
}
