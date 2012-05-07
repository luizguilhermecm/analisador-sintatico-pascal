#include <iostream>

#include "sintatico.cpp"
using namespace std;

int main (){
  cout << "prog" << endl;
  Sintatico novo;
  novo.AnalisadorLexico();
  novo.programa();
  return 0;
  
}
