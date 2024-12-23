#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H
#include "student.hpp"
#include "tree_node.hpp"

class SearchTree {
  public:
    SearchTree() { root = NULL; }
    ~SearchTree() { destroyTree(root); }
    bool isEmpty() const;
    bool isFull() const;

    /* Os métodos abaixo tem chamada recursiva de métodos privados, porém, com mais alguns parâmetros. */
    void retrieveStudent(Student& item, bool& found) const {
      retrieveStudent(root, item, found);
    }
    void insertStudent(Student item) { insertStudent(root, item); }
    void deleteStudent(int item) { deleteStudent(root, item); }
    void printPreOrder() const { printPreOrder(root); }
    void printInOrder() const { printInOrder(root); }
    void printPostOrder() const { printPostOrder(root); }

    private:
      void destroyTree(NodeType*& tree);
      void retrieveStudent(NodeType* tree, Student& item, bool& found) const;
      void insertStudent(NodeType*& tree, Student item);
      void deleteStudent(NodeType*& tree, int item);
      void deleteNode(NodeType*& tree);
      void getSuccessor(NodeType*& tree, Student& data);
      void printTree(NodeType* tree) const;
      void printPreOrder(NodeType* tree) const;
      void printInOrder(NodeType* tree) const;
      void printPostOrder(NodeType* tree) const;
      // Raiz da árvore, início da árvore
      NodeType* root;
};

#endif