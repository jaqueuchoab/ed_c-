typedef char ItemType;

/*Estrutura utilizada para guardar o dados e o endereço do próximo elemento.*/

struct NodeType
{
  ItemType info;
  NodeType* next;
};
