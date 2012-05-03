#include <iostream>
#include <vector>

#include "sintatico.h"

void Sintatico::error(){
  cout << "ERRO" << endl;
}

void Sintatico::avancar(){
  tok = Lexico::getToken();
  Lexico::EraseToken();
}

void Sintatico::eat(int token_consumir){
  if (token_consumir == tok){
    avancar();
    while (tok == 16) avancar();
  } else{
    avancar(); 
  }
}

void Sintatico::programa(){
  eat(PROGRAM); cout << "!pro"; identificador(); cout << "!id"; eat (17); cout << "!;"; bloco(); eat(8);
}

void Sintatico::identificador(){
  if (Lexico::NextIsEqual(2) || Lexico::NextIsEqual(3)){
    eat(2);
    while (Lexico::NextIsEqual(2) || Lexico::NextIsEqual(3)){
      switch(tok){
        case 2: eat(2); break;
        case 3: eat(3); break;
      }
    }
    switch(tok){
      case 2: eat(2); break;
      case 3: eat(3); break;
    }
  } else eat(2);
}

void Sintatico::bloco(){
  cout << "BLOCO";
}
