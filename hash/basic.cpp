#include "hash.hpp"
#include <iostream>

using namespace std;

// Instância a class definindo alguns dados iniciais
Hash::Hash(int max)
{
  // Tamanho da tabela
  length = 0;
  // Qtde max de itens
  max_items = max;
  // Criando a estrutura/vetor de estudantes
  structure = new Student[max_items];
}

Hash::~Hash()
{
  delete[] structure;
}

bool Hash::isFull() const
{
  return (length == max_items);
}

int Hash::getLength() const
{
  return length;
}

// Utiliza parâmetros por referência ou seja, tudo que for modificado dentro da função afetará fora dela também
// A variável indica se a chave procurada foi encontrada ou não
// Pelo que entendi, o objetivo dessa função é buscar a partir de uma chave(ra) o aluno dentro da estruturae fazer com que, seja modificada a minha instância de aluno para ser igual ao aluno presente na tabela uma vez que os dados como RA são condizentes;
void Hash::retrieveItem(Student &student, bool &found)
{
  // Calculará a posição desse estudante por meio do seu RA, essa posição terá de ser igual a posição indicada na criação dele na função insert
  int location = getHash(student);
  // Criando um estudante auxiliar que guardará o valor do estudante presente no vetor posição location (vetor[location])
  Student aux = structure[location];

  // Verificação importante, para verificar se realmente não há nenhuma colisão de valores, porém essa implementação assume que colisões não existem
  // Verifica se o RA do aluno da entrada, é igual ao do RA do aluno que foi encontrado na posição achada em getHash()
  if (student.getRa() != aux.getRa())
  {
    // Se os RA`s não forem iguais, significa que o aluno não foi encontrado
    found = false;
  }
  else
  {
    // Se forem iguais, então o aluno foi achado e as informações completas dele podem ser acessadas por meio do objeto instânciado apenas com o RA, pois o student (parâmetro indicado na função) é modificado para ser igual ao aux que guarda o aluno achado na posição
    found = true;
    // Modificação, dentro e fora
    student = aux;
  }
}

// Notas sobre essa função retrieveItem: poderia ser mais instuitiva e de melhor compreensão e usabilidade de código, uma abordagem um tanto complicado. Para melhorar, o que deveria ser de entrada era o RA do aluno, e retornar um objeto aluno completo caso o RA fosse verificado. Assim, essa modificação dentro da função não seria necessária e facilitaria em não necessariamente ter que criar um objeto já com RA e campo de nome vazio.

void Hash::insertItem(Student student)
{
  // Indicando a localização do estudante no array
  int location = getHash(student);
  // Adicionando na posição gerado anteriormente o estudante a ser criado
  structure[location] = student;
  // Atualizando o tamanho da estrutura/tabela
  length++;
}

void Hash::deleteItem(Student student)
{
  // Indicando a localização do estudante no array
  int location = getHash(student);
  // Indicando que na posição indicada anteriormente agora será adicionado o construtor padrão, que seu RA é -1 e o nome é vazio, ou seja, indicada que não há aluno;
  structure[location] = Student();
  // Atualizando o tamanho da estrutura/tabela
  length--;
}

void Hash::print()
{
  for (int i = 0; i < max_items; i++)
  {
    if(structure[i].getRa() == -1) {
      cout << "[" << (i + 1) << " - POSIÇÃO SEM ALUNO]" << "\n" << endl;
    } else {
      cout << "[ALUNO " << (i + 1) << "] - " << "RA: " << structure[i].getRa() << " | " << "NOME: " << structure[i].getNome() << "\n" << endl;
    }
  }
}

// Irá gerar posições elegíveis para o tamanho do vetor
int Hash::getHash(Student student)
{
  return student.getRa() % max_items;
}