#include <vector>
#include <iostream>

#include "lexico.h"

Lexico::Lexico () {
  //seta vetor indice
  //seta matriz automato
}

int Lexico::getAutomato (int estado, int caracter) {
  return automato [estado][caracter];
}

int Lexico::PosicaoIndice (char ch){
  int i = 2;
  while (i < alfabeto){
    if (ch == indice [i])
      return i;
    i++;
  }
  if (isalpha(ch))
    return 0;
  if (isdigit(ch))
    return 1;
}

bool isFinal (int estado){
  if (estado != 1 && estado != 0) return true;
  else return false;
}
