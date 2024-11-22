#include <iostream>
#include "hash.hpp"

using namespace std;

int main()
{
  // Instância da class Hash
  Hash alunosHash(10);

  // Obs: Visto que a qtde de de itens na tabela é 10 (um número par), os RA's devem sempre ter seus algorismos finais diferentes, para que assim não haja colisões, de sobrescrever a posição de um aluno por outro ter o mesmo resto da divisão.

  // Vetores com os valores correspondentes a 6 alunos
  int ras[6] = {12345, 34542, 46543, 87654, 98750, 12567};
  string nomes[6] = {"Jordan", "Jaqueline", "Jackson", "AnaLu", "João", "Izabel"};

  // Instânciando os 6 alunos
  for (int i = 0; i < 6; i++)
  {
    Student student = Student(ras[i], nomes[i]);
    alunosHash.insertItem(student);
  }

  alunosHash.print();
}