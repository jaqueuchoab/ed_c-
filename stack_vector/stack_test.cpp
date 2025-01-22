#include "stack.hpp"
#include <iostream>

using namespace std;

int main()
{
  try
  {
    /*Receberá dado a ser adicionado*/
    ItemType character;
    /*Instanciando a pilha*/
    Stack stack;
    /*Receberá o item/info do dado guardado no topo da pilha*/
    ItemType stackItem;

    /*Leitura de uma string, um conjunto de caracteres que irão compor a pilha*/
    cout << "Add item na pilha: " << endl;
    cin.get(character);
    /*Enquanto o prenchimento for diferente da quebra de linha, a leitura irá continuar e os caracteres serão constantemente adicionados à pilha*/
    // ATENÇÃO: ESPAÇOS SÃO CONTADOS COMO CARACTERES
    while (character != '\n')
    {
      /*Acessando função push*/
      stack.push(character);
      cin.get(character);
    }

    /*Imprimindo a pilha antes das remoções*/
    stack.print();

    cout << "----------------\n";
    cout << "|ITENS REMOVIDOS|";
    /*Enquanto a pilha não estiver vazia a operação pop (remoção de elementos) acontecerá*/
    while (!stack.isEmpty())
    {
      stackItem = stack.pop();
      cout << "\n     [ " << stackItem << " ]";
    }
    cout << "\n----------------\n";

    /*Imprimindo a pilha após as remoções*/
    stack.print();
  }
  catch (const char *e)
  {
    std::cerr << "Erro: " << e << std::endl;
  }
}
