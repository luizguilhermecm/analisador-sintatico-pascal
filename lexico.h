#include <iostream>
#include <vector>

using namespace std;

#define estados 25  //fazer o automato e confirmar valor
#define alfabeto 18 //confirmar


class Lexico {
  public:
    Lexico ();
    void AnalisadorLexico ();
    int getAutomato (int estado, int caracter);
    int PosicaoIndice (char ch);
    bool isFinal (int estado);
    
  private:
    int automato [estados][alfabeto];
    char indice [alfabeto];
    

};

