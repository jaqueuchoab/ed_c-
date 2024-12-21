#ifndef STACK_H
#define STACK_H
#include "node.hpp"

class AVLSearchTree {
  public: 
    AVLSearchTree() { root = NULL; }
    ~AVLSearchTree() { destroyTree(root); }
    bool isEmpty() const;
    bool isFull() const;
    void retrieveAluno(Aluno& item, bool& found) const{
      retrieveAluno(root, item, found);
    }
    void insertAluno(Aluno item) {
      // a arvoré é mais alta?
      bool isTaller;
      insertAluno(root, item, isTaller);
    }
    void deleteAluno(int item) {
      bool isShorter;
      deleteAluno(root, item, isShorter);
    }
  private: 
    void destroyTree(NodeType*& tree);
    void retrieveAluno(NodeType*& tree, Aluno& item, bool& found);
}
// parei no minuto 14:17
#endif