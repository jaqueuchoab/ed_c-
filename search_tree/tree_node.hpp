#include "student.hpp"

/*Estrutura criada para guardar as informações e endereços de subárvores*/

struct NodeType {
  /*Informação que será guardada*/
  Student aluno;
  /*Ponteiro para a subárvore esquerda*/
  NodeType* left;
  /*Ponteiro para a subárvore direita*/
  NodeType* right;
};