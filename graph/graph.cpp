#include "graph.hpp"
#include "queue.hpp"
#include "vertex.hpp"
#include <iostream>

using namespace std;

// Método construtor
Graph::Graph(int max, int null_edge)
{
  NULL_EDGE = null_edge;
  maxVertices = max;
  numVertices = 0;
  vertices = new Vertex[maxVertices];
  marks = new bool[maxVertices];
  // Linhas da matriz
  edges = new int *[maxVertices];

  // Criando a matriz de adjacências
  for (int row = 0; row < maxVertices; row++)
  {
    edges[row] = new int[maxVertices];
  }

  // Populando a matriz
  for (int row = 0; row < maxVertices; row++)
  {
    for (int col = 0; col < maxVertices; col++)
    {
      edges[row][col] = NULL_EDGE;
    }
  }
}

// Desalocará toda a memória alocada
Graph::~Graph()
{
  delete[] vertices;
  delete[] marks;

  for (int row = 0; row < maxVertices; row++)
  {
    delete[] edges[row];
  }
  delete[] edges;
}

// Verificação de qual é o index associado ao vertie em questão
int Graph::getIndex(Vertex vertex)
{
  int index = 0;
  // Enquanto o vertice dado não for igual ao vertices na posição [index] de vertices, o index++ acontecerá a fim de percorrer o array vérices
  while (!(vertex.getNome() == vertices[index].getNome()))
  {
    index++;
  }
  return index;
}

// Adicionar vértice
void Graph::addVertex(Vertex vertex)
{
  vertices[numVertices] = vertex;
  numVertices++;
}

// Adicionar arestas
void Graph::addEdge(Vertex fromVertex, Vertex toVertex, int weight)
{
  int row = getIndex(fromVertex);
  int col = getIndex(toVertex);

  edges[row][col] = weight;

  // Remover se o grafo não for direcionado.
  edges[col][row] = weight;
}

// Verificar o peso de uma aresta
int Graph::getWeight(Vertex fromVertex, Vertex toVertex)
{
  int row = getIndex(fromVertex);
  int col = getIndex(toVertex);
  return edges[row][col];
}

// Enfileira todos os adjacentes
void Graph::getAdjacents(Vertex vertex, Queue &adjVertices)
{
  int fromIndex;
  int toIndex;

  // Pega o index do vertice em questão
  fromIndex = getIndex(vertex);
  // Intera entre todos os outros vértices que estão ao redor desse fromIndex, ou seja do indice incial
  for (toIndex = 0; toIndex < numVertices; toIndex++)
  {
    if (edges[fromIndex][toIndex] != NULL_EDGE)
      // Uma cópia do elemento é adicionada no array
      adjVertices.enqueue(vertices[toIndex].getNome());
  }
}

// Métodos que gerenciam as marcações
void Graph::clearMarks()
{
  for (int i = 0; i < numVertices; i++)
  {
    marks[i] = false;
  }
}

void Graph::markVertex(Vertex vertex)
{
  int index = getIndex(vertex);
  marks[index] = true;
}

bool Graph::isMarked(Vertex vertex)
{
  int index = getIndex(vertex);
  return marks[index];
}

// Imprimir matriz
void Graph::printMatrix()
{
  for (int i = 0; i < numVertices; i++)
  {
    for (int j = 0; j < numVertices; j++)
    {
      std::cout << edges[i][j] << "  ";
    }
    std::cout << std::endl;
  }
}