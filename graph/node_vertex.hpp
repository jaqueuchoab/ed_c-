#ifndef NODE_VERTEX_HPP
#define NODE_VERTEX_HPP
#include <iostream>
#include "vertex.hpp"
using namespace std;


typedef Vertex VertexType;

/*Estrutura utilizada para guardar o dados e o endereço do próximo elemento.*/

struct NodeTypeVertex
{
  VertexType item;
  NodeTypeVertex* next;
};
#endif