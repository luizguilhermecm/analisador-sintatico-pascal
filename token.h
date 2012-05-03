#include <iostream>
#include <vector>

using namespace std;

class Tokens{
  protected:
    int getToken ();
    void setToken (int new_token);
    void printTokens ();
    bool isEqual (int token_comparativo);
    bool IsReservada (string palavra);
    void setToken (int new_token, int qnt);
    void EraseToken (); 
    enum reservadas {ABSOLUTE = 42,
      ELSE,
      NIL,
      SET,
      AND,
      END,
      NOT,
      SHL,
      ARRAY,
      FILE,
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
      TRUE,
      EXIT,
      NEW
    };
  private:
    vector<int> Token;
};
