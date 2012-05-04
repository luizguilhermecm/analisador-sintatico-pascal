#include "sintatico.h"

void Sintatico::error(){
  cout << "ERRO " << tok << endl;
}

void Sintatico::error(int erro, int queria){
  cout << "ERRO " << erro << "--" << queria << "linha " << linha << endl;
  avancar();
}
void Sintatico::avancar(){ 
  tok = Lexico::getToken(); 
  Lexico::EraseToken(); 
}

void Sintatico::eat(int token_consumir){ 
  if (Lexico::IsEqual(tok,token_consumir)){
    avancar();
    if (Lexico::IsEqual(tok,BARRAN)){
      linha++;
      avancar();
    } 
    while (Lexico::IsEqual(tok,WHITE)) avancar();
  } else{
    error(tok,token_consumir);
  }
}

void Sintatico::programa(){
  linha = 1;
  avancar();
  eat(PROGRAM); 
  identificador(); 
  cout << PONTOVIRGULA << endl;
  eat(PONTOVIRGULA);
  bloco();
  eat(PONTO);
  cout << "SUCESS";
}

void Sintatico::identificador(){
  if (Lexico::IsEqual(tok,LETRA)){
    do{
      switch (tok) {
        case LETRA: eat(LETRA); break; 
        case DIGITO: eat(DIGITO); break;
      }
    } while (Lexico::IsEqual(tok,LETRA) || Lexico::IsEqual(tok,DIGITO));
  }
}

void Sintatico::bloco(){
  if (IsEqual(tok,LABEL)) {
    rotulos();
  }
  if (IsEqual(tok,CONST)) {
    constantes();
  }
  if (Lexico::IsEqual(tok,VAR)) {
    variaveis();
  }
  while (IsEqual(tok,FUNCTION) || IsEqual(tok,PROCEDURE)){
    rotina();
  }
  corpo();
}

void Sintatico::rotulos(){
  eat(LABEL);
  lista_de_numeros();
  eat(PONTOVIRGULA);
}

void Sintatico::constantes(){
  eat(CONST);
  do{
    identificador();
    eat(IGUAL);
    constante();
    eat(PONTOVIRGULA);
  } while (IsEqual(tok,LETRA));
}

void Sintatico::variaveis(){
  eat(VAR);
  do{
    lista_de_identificadores();
    eat(DOISPONTOS);
    tipo();
    eat(PONTOVIRGULA);
  } while (IsEqual(tok,LETRA));
}

void Sintatico::rotina(){
  if (IsEqual(tok,FUNCTION)) funcao();
  else if (IsEqual(tok,PROCEDURE)) procedimento();
}

void Sintatico::funcao(){
  eat(FUNCTION);
  identificador();
  parametros_formais();
  eat(DOISPONTOS);
  identificador();
  eat(PONTOVIRGULA);
  bloco();
  eat(PONTOVIRGULA);
}

void Sintatico::procedimento(){
  eat(PROCEDURE);
  identificador();
  parametros_formais();
  eat(PONTOVIRGULA);
  bloco();
  eat(PONTOVIRGULA);
}

void Sintatico::corpo(){
  eat(BEGIN);
  comando();
  while (IsEqual(tok,PONTOVIRGULA)) {
    eat(PONTOVIRGULA);
    comando();
  } 
  eat(END);
}

void Sintatico::tipo(){
  identificador();
}

void Sintatico::parametros_formais(){
  if (IsEqual(tok,ABREPAR)){
    eat(ABREPAR);
    parametro_formal();
    while (IsEqual(tok,PONTOVIRGULA)){
      eat(PONTOVIRGULA);
      parametro_formal();
    }
    eat(FECHAPAR);
  } else eat(ABREFECHAPAR);
}

void Sintatico::parametro_formal(){
  parametro_expressao();
}

void Sintatico::parametro_expressao(){
  if (IsEqual(tok,VAR)) eat(VAR);
  lista_de_identificadores();
  eat(DOISPONTOS);
  identificador();
}

void Sintatico::comando(){
  if (IsEqual(tok,DIGITO)){
    numero();
    eat(DOISPONTOS);
  }
  comando_sem_rotulo();
}

void Sintatico::variavel(){
  identificador();
}

void Sintatico::comando_sem_rotulo(){
  switch (tok){
    case GOTO: desvio(); break;
    case BEGIN: composto(); break;
    case IF: condicional(); break;
    case WHILE: repetitivo(); break;
    case LETRA: { 
                  identificador();
                  if (IsEqual(tok,DOISPONTOSIGUAL)) atribuicao();
                  else chamada_de_procedimento();
                }
    default: vazio();
  }
}

void Sintatico::atribuicao(){
  eat(DOISPONTOSIGUAL);
  expressao();
}

void Sintatico::chamada_de_procedimento(){
  if (IsEqual(tok,ABREPAR)){
    eat(ABREPAR);
    lista_de_expressoes();
    eat(FECHAPAR);
  } else eat(ABREFECHAPAR);
}

void Sintatico::desvio(){
  eat(GOTO);
  numero();
}

void Sintatico::composto(){
  eat(BEGIN);
  comando_sem_rotulo();
  while (IsEqual(tok,PONTOVIRGULA)){
    eat(PONTOVIRGULA);
    comando_sem_rotulo();
  }
  eat(END);
}

void Sintatico::condicional(){
  eat(IF);
  expressao();
  eat(THEN);
  comando_sem_rotulo();
  if (IsEqual(tok,ELSE)){
    eat(ELSE);
    comando_sem_rotulo();
  }
}

void Sintatico::repetitivo(){
  eat(WHILE);
  expressao();
  eat(DO);
  comando_sem_rotulo();
}

void Sintatico::vazio(){
  
}

void Sintatico::expressao(){
  expressao_simples();
  if (IsEqual(tok,IGUAL) ||
      IsEqual(tok,DIFERENTE) ||
      IsEqual(tok,MENOR) ||
      IsEqual(tok,MENORIGUAL) ||
      IsEqual(tok,MAIORIGUAL) ||
      IsEqual(tok,MAIOR)){
    operador_relacional();
    expressao_simples();
  }
}

void Sintatico::operador_relacional(){
  switch (tok){
    case IGUAL      : eat(IGUAL)      ; break ;
    case DIFERENTE  : eat(DIFERENTE)  ; break ;
    case MENOR      : eat(MENOR)      ; break ;
    case MENORIGUAL : eat(MENORIGUAL) ; break ;
    case MAIORIGUAL : eat(MAIORIGUAL) ; break ;
    case MAIOR      : eat(MAIOR)      ; break ;
  }
}

void Sintatico::expressao_simples(){
  if (IsEqual(tok,MAIS)) eat(MAIS);
  else if (IsEqual(tok,MENOS)) eat(MENOS);
  termo();
  while (IsEqual(tok,MAIS) ||
         IsEqual(tok,MENOS) ||
         IsEqual(tok,OR)){
    operador_aditivo();
    termo();
  }
}

void Sintatico::operador_aditivo(){
  switch (tok){
    case MAIS  : eat(MAIS)  ; break ;
    case MENOS : eat(MENOS) ; break ;
    case OR    : eat(OR)    ; break ;
  }
}

void Sintatico::termo(){
  fator();
  while (IsEqual(tok,VEZES) ||
         IsEqual(tok,DIV) ||
         IsEqual(tok,AND)){
    operador_multiplicativo();
    fator();
  }
}

void Sintatico::operador_multiplicativo(){
  switch (tok){
    case VEZES : eat(VEZES) ; break ;
    case DIV   : eat(DIV)   ; break ;
    case AND   : eat(AND)   ; break ;
  }
}

void Sintatico::fator(){
  switch (tok){
    case NOT     : eat(NOT)     ; fator()     ; break         ;
    case ABREPAR : eat(ABREPAR) ; expressao() ; eat(FECHAPAR) ; break ;
    case DIGITO  : numero()     ; break       ;
    case LETRA   : {
                    identificador();
                    if (IsEqual(tok,ABREPAR) || IsEqual(tok,ABREFECHAPAR)) chamada_de_funcao();
                    break;
                   }
  }
}

void Sintatico::chamada_de_funcao(){
  if (IsEqual(tok,ABREPAR)) {
    eat(ABREPAR);
    lista_de_expressoes();
    eat(FECHAPAR);
  } else eat(ABREFECHAPAR);
}

void Sintatico::constante(){
  if (IsEqual(tok,LETRA)) identificador();
  else{
    if (IsEqual(tok,MAIS)) eat(MAIS);
    else if (IsEqual(tok,MENOS)) eat(MENOS);
    numero();
  }
}

void Sintatico::numero(){
  do{
    eat(DIGITO);
  } while (IsEqual(tok,DIGITO));
}

void Sintatico::lista_de_identificadores(){
  identificador();
  while (IsEqual(tok,VIRGULA)){
    eat(VIRGULA);
    identificador();
  }
}

void Sintatico::lista_de_numeros(){
  numero();
  while (IsEqual(tok,VIRGULA)){
    eat(VIRGULA);
    numero();
  }
}

void Sintatico::lista_de_expressoes(){
  expressao();
  while (IsEqual(tok,VIRGULA)){
    eat(VIRGULA);
    expressao();
  }
}
