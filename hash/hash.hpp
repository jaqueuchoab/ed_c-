#ifndef HASH_H
#define HASH_H
#include "student.hpp"

class Hash
{
public:
// Instância a class definindo a qtde de items
  Hash(int max_items = 100);
  // Destrutor, desalocará tudo que foi alocado de memória
  ~Hash();
  // Retorna se a tabela está cheia ou não
  bool isFull() const;
  // Retorna o tamanho da tabela
  int getLength() const;

//
  void retrieveItem(Student &student, bool &found);
  void insertItem(Student student);
  void deleteItem(Student student);
  void print();

private:
// Método que calcula o módulo de RA por a qtde de items na tabela, se a qtde de items é 100 então será gerado posições de 0 a 99.
  int getHash(Student student);
  int max_items;
  int length;
  // Vetor de objetos aluno
  Student* structure;
};

#endif