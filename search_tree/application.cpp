#include "student.hpp"
#include "search_tree.hpp"
#include <iostream>

const int NUM_ALUNOS = 8;

int main() {
  SearchTree searchTree;

  int ras[NUM_ALUNOS] = {20, 18, 58, 7, 19, 26, 25, 30};

  string nomes[NUM_ALUNOS] = {
    "Jordan", "Jaqueline", "Izabel", "Joao", "Jackson", "Analu", "Mustafu", "Jordelina"
  };

  Student alunos[NUM_ALUNOS];

  for(int i = 0; i < NUM_ALUNOS; i++) {
    Student aluno = Student(ras[i], nomes[i]);
    alunos[i] = aluno;
    searchTree.insertStudent(aluno);
  }

  cout << "Árvore na forma atual:";
  cout << endl;

  cout << "Pre: ";
  searchTree.printPreOrder();
  cout << endl;
  cout << "In: ";
  searchTree.printInOrder();
  cout << endl;
  cout << "Post: ";
  searchTree.printPostOrder();
  cout << endl;

  cout << "Árvore após remoção do primeiro aluno:";
  cout << endl;

  searchTree.deleteStudent(alunos[0].getRa());
  cout << "************" << endl;
  cout << "Pre: ";
  searchTree.printPreOrder();
  cout << endl;
  cout << "In: ";
  searchTree.printInOrder();
  cout << endl;
  cout << "Post: ";
  searchTree.printPostOrder();
  cout << endl;
}