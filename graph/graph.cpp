#include "graph.hpp"
#include "queue.hpp"
#include "queue_vertex.hpp"
#include "stack.hpp"
#include "vertex.hpp"
#include <iostream>

using namespace std;

// Grafo direcionado
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

void Graph::getAdjacentsVertex(Vertex vertex, QueueVertex &adjVertices)
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
      adjVertices.enqueueVertex(vertices[toIndex].getNome());
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

// Parâmetros: Grafo, o vértice de origem, e o vértice de destino
void Graph::depthFirstSearch(Graph &graph, Vertex origem, Vertex destino)
{
  // Pilha
  Stack vertexStack;
  // Var que indica que foi achado ou não um caminho
  bool found = false;
  // Vértice auxiliar
  Vertex vertex;

  // Limpar marcações no grafo
  graph.clearMarks();
  // Empilhar a origem
  vertexStack.push(origem);

  do
  {
    // Desempilhando um vérice e alocando seu valor na var aux
    vertex = vertexStack.pop();
    // Verificando se o vértice desempilhado acima é compátivel com de destino, isso indicará que há sim um caminho do vértice de origem até o destino
    if (vertex.getNome() == destino.getNome())
    {
      cout << "\nCaminho encontrado, destino: " << vertex.getNome() << "!" << endl;
      // Indicando que foi encontrado
      found = true;
    }
    else
    {
      // Verificando se o vértice que está guardado na var aux não está marcado como visitado, se não estiver ele precisa ser marcado pois já foi visitado
      if (!graph.isMarked(vertex))
      {
        graph.markVertex(vertex);
        cout << "\nVisitado: " << vertex.getNome();
        // Fila de adjacents, será passada como parâmetro para a funçào getAdjacentes que irá popular nela os vértices a determinado adjacentes a um determinado vértice.
        // OBS: Na função getAdjacentes essa fila é passada por referência ou seja, o que for modificado nela denttro da função impactará na fila do lado de fora da função.
        QueueVertex adjacents;
        // Verificando adjacentes do vértice
        graph.getAdjacentsVertex(vertex, adjacents);
        cout << "\n" << endl;
        // Enquanto a fila de adjacents for vazia
        while (!adjacents.isEmpty())
        {
          // Desimfileirando um adjacente e guardando seu valor
          Vertex adjacent = adjacents.dequeueVertex();
          // Verificando se esse vértice que é adjacente do vértice da vez está marcado como visitado ou não;
          if (!graph.isMarked(adjacent))
          {
            // Se o vértice não está marcado como visitado então ele será empilhado para ser comparado com o vértice que estamos à procura.
            cout << "Empilhando adjacente do anterior: " << adjacent.getNome() << endl;
            vertexStack.push(adjacent);
          }
        }
      }
    }
    // Enquanto a pilha não estiver vazia, e o caminho ainda não foi achado o processo será refeito
  } while (!vertexStack.isEmpty() && !found);
}

void Graph::breadthFirstSearch(Graph &graph, Vertex origem, Vertex destino)
{
  // Fila de vértice a serem comparadas
  QueueVertex vertexQueue;
  // Var que indica se o procurado foi achado
  bool found = false;
  // Var auxiliar
  Vertex vertex;

  // Limpando as marcações do grafo
  graph.clearMarks();
  // Empilhando a origem
  vertexQueue.enqueueVertex(origem);

  do
  {
    // Desimfileirando e guardando o vértice da fila
    vertex = vertexQueue.dequeueVertex();
    // Verificando se o vértice desimfileirando acima é compátivel com de destino, isso indicará que há sim um caminho do vértice de origem até o destino
    if (vertex.getNome() == destino.getNome())
    {
      // Indicando que há um caminho
      cout << "\nCaminho encontrado, destino: " << vertex.getNome() << "!" << endl;
      found = true;
    }
    else
    {
      // Se o vértice da vez não for marcado então devemos marcar este como visitado
      if (!graph.isMarked(vertex))
      {
        graph.markVertex(vertex);
        cout << "\nVisitado: " << vertex.getNome() << endl;
        // Fila de adjacents, será passada como parâmetro para a funçào getAdjacentes que irá popular nela os vértices a determinado adjacentes a um determinado vértice.
        // OBS: Na função getAdjacentes essa fila é passada por referência ou seja, o que for modificado nela denttro da função impactará na fila do lado de fora da função.
        QueueVertex adjacents;
        // Verificando os adjacentes
        graph.getAdjacentsVertex(vertex, adjacents);
        cout << "\n" << endl;
        // Enquanto adjacents não é vazia
        while (!adjacents.isEmpty())
        {
          Vertex adjacent = adjacents.dequeueVertex();
          if (!graph.isMarked(adjacent))
          {
            // Se o vértice não está marcado como visitado então ele será empilhado para ser comparado com o vértice que estamos à procura, que é o de destino
            cout << "Empilhando adjacente do anterior: " << adjacent.getNome() << endl;
            vertexQueue.enqueueVertex(adjacent);
          }
        }
      }
    }
    // Enquanto a pilha não estiver vazia, e o caminho ainda não foi achado o processo será refeito
  } while (!vertexQueue.isEmpty() && !found);
}