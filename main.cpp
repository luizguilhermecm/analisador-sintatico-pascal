#include <iostream>

#include "sintatico.cpp"
using namespace std;

int main () {

  Sintatico novo;
  novo.AnalisadorLexico();
  novo.programa();
  return 0;
  
}
