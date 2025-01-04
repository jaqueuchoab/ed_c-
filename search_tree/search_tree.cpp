#include "search_tree.hpp"
#include <iostream>

/*Invocado pelo destrutor, irá deletar nó a nó visitando de forma recursiva, até deletar a árvore inteira*/
void SearchTree::destroyTree(NodeType*& tree) {
  /*Se a árvore for diferente de nulo*/
  if(tree != NULL) {
    destroyTree(tree->left);
    destroyTree(tree->right); 
    delete tree;
  }
}

bool SearchTree::isEmpty() const {
  return root == NULL;
}

bool SearchTree::isFull() const {
  NodeType* location;
  try {
    location = new NodeType;
    delete location;
    return false;
  } catch(std::bad_alloc exception) {
    return true;
  }
}

/*Método de busca, recursivo*/
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
void SearchTree::insertStudent(NodeType*& tree, Student aluno) {
  if(tree == NULL) {
    tree =  new NodeType;
    tree->right = NULL;
    tree->left = NULL;
    tree->aluno =  aluno;
  } else if (aluno.getRa() < tree->aluno.getRa()) {
    insertStudent(tree->left, aluno);
  } else {
    insertStudent(tree->right, aluno);
  }
}

/*Imprimindo árvore na saída padrão*/
void SearchTree::printPreOrder(NodeType* tree) const {
  if(tree != NULL) {
    std::cout << tree->aluno.getNome() << " , ";
    printPreOrder(tree->left);
    printPreOrder(tree->right);
  }
}

void SearchTree::printInOrder(NodeType* tree) const {
  if(tree != NULL) {
    printInOrder(tree->left);
    std::cout << tree->aluno.getNome() << " , ";
    printInOrder(tree->right);
  }
}

void SearchTree::printPostOrder(NodeType* tree) const {
  if(tree != NULL) {
    printPostOrder(tree->left);
    printPostOrder(tree->right);
    std::cout << tree->aluno.getNome() << " , ";
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

void SearchTree::deleteNode(NodeType*& tree) {
  Student data;
  NodeType* tempPont;
  tempPont = tree;

  if(tree->left == NULL) {
    tree = tree->right;
    delete tempPont;
  } else if (tree->right == NULL) {
    tree = tree->left;
    delete tempPont;
  } else {
    getSuccessor(tree, data);
    tree->aluno =  data;
    deleteStudent((tree->right), data.getRa());
  }
}

void SearchTree::getSuccessor(NodeType* tree, Student& data) {
  tree = tree->right;
  while (tree->left != NULL) {
    tree = tree->left;
  }
  data = tree->aluno;
}