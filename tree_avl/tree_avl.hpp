#ifndef STACK_H
#define STACK_H
#include "node.hpp"

class AVLSearchTree
{
public:
  AVLSearchTree() { root = NULL; }
  ~AVLSearchTree() { destroyTree(root); }
  bool isEmpty() const;
  bool isFull() const;
  void retrieveAluno(Aluno &item, bool &found) const
  {
    retrieveAluno(root, item, found);
  }
  void insertAluno(Aluno item)
  {
    // a arvoré é mais alta?
    bool isTaller;
    insertAluno(root, item, isTaller);
  }
  void deleteAluno(int item)
  {
    bool isShorter;
    deleteAluno(root, item, isShorter);
  }

private:
  void retrieveAluno(NodeType *&tree, Aluno &item, bool &found) const;
  void destroyTree(NodeType *&tree);
  void retrieveStudent(NodeType *tree, Student &item, bool &found) const;
  void insertStudent(NodeType *&tree, Student item, bool& isTaller);
  void deleteStudent(NodeType *&tree, int item, bool& isShorter);
  void deleteNode(NodeType *&tree, bool& isShorter);
  void getSuccessor(NodeType *tree, Student &data);
  void printTree(NodeType *tree) const;
  void printPreOrder(NodeType *tree) const;
  void printInOrder(NodeType *tree) const;
  void printPostOrder(NodeType *tree) const;
  void rotateToLeft(NodeType*& tree) const;
  void rotateToRight(NodeType*& tree) const;
  void rotateToLeftAndRight(NodeType*& tree) const;
  void rotateToRightAndLeft(NodeType*& tree) const;

  void performRotations(NodeType*& tree) const;

  // Raiz da árvore, início da árvore
  NodeType *root;
}
// parei no minuto 14:17
#endif