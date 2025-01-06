#include "tree_avl.hpp"
#include <iostream>

void SearchTree::retrieveStudent(NodeType* tree, Student& aluno, bool& found) const {
  if(tree == NULL)
    found = false;
  else if (aluno.getRa() < tree->aluno.getRa())
    retrieveStudent(tree->left, aluno, found);
  else if (aluno.getRa() > tree->aluno.getRa())
    retrieveStudent(tree->right, aluno, found);
  else {
    aluno = tree->aluno;
    found = true;
  }
}

/*Inserir aluno na árvore*/
void SearchTree::insertStudent(NodeType*& tree, Student aluno, bool& isTaller) {
  if(tree == NULL) {
    tree =  new NodeType;
    tree->right = NULL;
    tree->left = NULL;
    tree->aluno =  aluno;
    tree->fatorB = 0;
    isTaller = true;
    return;
  }  else if (aluno.getRa() < tree->aluno.getRa()) {
    insertStudent(tree->left, aluno, isTaller);
    if(isTaller) {
      tree->fatorB = tree->fatorB - 1;
    }
  } else {
    insertStudent(tree->right, aluno);
    if(isTaller) {
      tree->fatorB = tree->fatorB - 1;
    }
  }
}

void SearchTree::deleteStudent(NodeType*& tree, int aluno) {
  if (tree == NULL) return; 
  if(aluno < tree->aluno.getRa()) {
    deleteStudent(tree->left, aluno);
  } else if (aluno > tree->aluno.getRa()) {
    deleteStudent(tree->right, aluno);
  } else {
    deleteNode(tree);
  }
}