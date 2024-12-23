#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
private:
  int ra;
  string nome;

public:
  Student();
  Student(int ra, string nome);
  string getNome() const;
  int getRa() const;
};

#endif
