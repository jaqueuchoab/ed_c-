typedef char ItemType;

/*Estrutura utilizada para guardar o dados e o endereço do próximo elemento.*/

/*Essa organização permitirá operações em tempo constante, visto que na pilha as operações ocorrem sempre na cabeça e será indicado um ponteiro para a cabeça.*/

struct NodeType {
  ItemType info;
  NodeType* next;
};