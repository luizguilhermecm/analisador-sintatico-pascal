#include "token.cpp"

#define estados 42//fazer o automato e confirmar valor
#define alfabeto 25//confirmar
#define estado_erro 42 

class Lexico : public Tokens{
  public:
    void AnalisadorLexico ();
    int PosicaoIndice (char ch);
    bool IsFinal (int estado);
    void print ();    
    void iniciar();
    Lexico();
    void Token (int final);
  private:
    int automato [estados][alfabeto];
    char indice [alfabeto];
};
