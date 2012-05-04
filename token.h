#include <iostream>
#include <vector>

using namespace std;

class Tokens{
  protected:
    int getToken ();
    void setToken (int new_token);
    void printTokens ();
    void Inverter ();
    bool IsEqual (int tok_, int need);
    bool NextIsEqual (int t);
    bool IsReservada (string palavra);
    void setToken (int new_token, int qnt);
    void EraseToken ();
    enum automato_reservadas {LETRA = 2,
      DIGITO,  //3
      IGUAL,  //4
      MENOR,  //5
      DIFERENTE,
      MENORIGUAL,
      MAIOR,
      MAIORIGUAL,
      MAIS,  //7
      MENOS,  //8
      VEZES,  //9
      PONTO, //10
      PONTOPONTO,
      DOISPONTOS, //11
      DOISPONTOSIGUAL,
      ABREPAR, //12
      ABREFECHAPAR,
      FECHAPAR, //13
      ABRECOCH, //14
      FECHACOCH, //15
      VIRGULA, //16
      BARRAN, //17
      WHITE,  //18
      PONTOVIRGULA, //19
      BARRA, //20
      TIL, //21
      ARROBA, //22
      CIFRAO, //23
      SUSTENIDO, //24
      MAISIGUAL,
      MENOSIGUAL,
      VEZESIGUAL,
      BARRAIGUAL,
      ABRECOMENTARIO,
      FECHACOMENTAIO,
      ABREPARPONTO,
      PONTOFECHAPAR,
      BARRABARRA,
      UNDER, //25
      TABULACAO //26
    };
    enum reservadas {ABSOLUTE = 42,
      ELSE,
      NIL,
      SET,
      AND,
      END,
      NOT,
      SHL,
      ARRAY,
      OBJECT,
      SHR,
      ASM,
      FOR,
      OF,
      STRING,
      BEGIN,
      FUNCTION,
      ON,
      THEN,
      BREAK,
      GOTO,
      OPERATOR,
      TO,
      CASE,
      IF,
      OR,
      TYPE,
      CONST,
      IMPLEMENTATION,
      PACKED,
      UNIT,
      CONSTRUCTOR,
      IN,
      PROCEDURE,
      UNTIL,
      CONTINUE,
      INHERITED,
      PROGRAM,
      USES,
      DESTRUCTOR,
      INLINE,
      RECORD,
      VAR,
      DIV,
      INTERFACE,
      REINTRODUCE,
      WHILE,
      DO,
      LABEL,
      REPEAT,
      WITH,
      DOWNTO,
      MOD,
      SELF,
      XOR,
      AS,
      CLASS,
      EXCEPT,
      EXPORTS,
      FINALIZATION,
      FINALLY,
      INITIALIZATION,
      IS,
      LIBRARY,
      OUT,
      PROPERTY,
      RAISE,
      THREADVAR,
      TRY,
      DISPOSE,
      FALSE,
//      TRUE,
      EXIT,
      NEW
    };
  private:
    vector<int> Token;
};
