#include "lexico.cpp"

class Sintatico : public Lexico {
  public:
    void avancar();
    void eat(int token_consumir);
    void error();
    void programa();
    void identificador();
    void bloco();
  private:
    int tok;

};
