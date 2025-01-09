#ifndef GRAPH_H
#define GRAPH_H
#include "vertex.hpp"
#include "queue.hpp"
#include "queue_vertex.hpp"

class Graph {
  private:
    // Constante para aresta nula
    int NULL_EDGE;
    // Número máximo de vértices
    int maxVertices;
    // Número de vértices adicionados
    int numVertices; 
    // Array com todos os vértices
    Vertex* vertices; 
    // Matriz de adjacências
    int** edges;
    // Marca se os vertice[i] foi utilizado, pode ser importante para momentos em que houver a busca em largura ou profundidadde maracar um vertice que ja foi visitado
    bool* marks;
    // Método que indicará dado o vétice qual o seu index na ,atriz de adjacência
    int getIndex(Vertex);
  public:
    // Construtor
    Graph(int max = 50, int null = 0);
    // Destrutor
    ~Graph();

    // Adiciona vértices
    void addVertex(Vertex);
    // Adiciona uma aresta, um par de vértices, que pode ser ponderado ou não
    void addEdge(Vertex, Vertex, int);

    // Método que dado o par de vértice devolve o peso associado a ela
    int getWeight(Vertex, Vertex);
    // Irá retornar uma fila de vértices que são adjacentes ao vértice indicado nos parâmetros
    void getAdjacents(Vertex, Queue& adjacents);
    void getAdjacentsVertex(Vertex, QueueVertex& adjacents);
    // Os próximos 3 métodos gerenciam as marcações
    void clearMarks(); // Limpa uma marcação
    void markVertex(Vertex); // Marca um vértice
    bool isMarked(Vertex); // Verififica se o vértice está marcado
    void printMatrix();
    // Busca em profundade
    void depthFirstSearch(Graph& graph, Vertex origem, Vertex destino);
    void breadthFirstSearch(Graph& graph, Vertex origem, Vertex destino);
};

#endif