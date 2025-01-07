#include <iostream>
using namespace std;


typedef std::string ItemType;

/*Estrutura utilizada para guardar o dados e o endereço do próximo elemento.*/

struct NodeType
{
  ItemType info;
  NodeType* next;
};
