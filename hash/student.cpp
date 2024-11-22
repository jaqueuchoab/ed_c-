#include "student.hpp"
#include <iostream>

using namespace std;

// Instância um estudante
Student::Student() {
  // Indica que a posição do vetor está vazia, assumindo que nessa escola todos os alunos recebem um RA maior que 0
  this->ra = -1;
  this->nome = "";
}

// Instância um estudante definindo inicialmente suas informações
Student::Student(int ra, string nome) {
  this->ra = ra;
  this->nome = nome;
}

// Retorna o RA
int Student::getRa() const{
  return ra;
}

// Retorna o nome do aluno
string Student::getNome() const{
  return nome;
}