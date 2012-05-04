#include <vector>
#include <iostream>
#include <string>

#include "token.h"

using namespace std;

void Tokens::setToken (int new_token, int qnt){
  int i = 0;
  while (i < qnt){
    Token.push_back(new_token);
    i++;
  }
}

bool Tokens::IsReservada (string palavra){
  if (palavra == "program") {
    setToken (PROGRAM);
    return true;
  }
  if (palavra == "var") {
    setToken (VAR);
    return true;
  }
  if (palavra == "begin") {
    setToken (BEGIN);
    return true;
  }
  if (palavra == "end") {
    setToken (END);
    return true;
  }
  if (palavra == "function") {
    setToken (FUNCTION);
    return true;
  }
  if (palavra == "procedure") {
    setToken (PROCEDURE);
    return true;
  }
  if (palavra == "then") {
    setToken (THEN);
    return true;
  }
  if (palavra == "if") {
    setToken (IF);
    return true;
  }
  if (palavra == "not") {
    setToken (NOT);
    return true;
  }
  if (palavra == "or") {
    setToken (OR);
    return true;
  }
  //if (palavra == "true") {
  //  return true;
  //}
  if (palavra == "else") {
    setToken (ELSE);
    return true;
  }
  return false;
}

void Tokens::setToken (int new_token) {
  Token.push_back(new_token);
}

int Tokens::getToken () {
  return Token.back();
}

void Tokens::EraseToken () {
  Token.pop_back();
}

void Tokens::Inverter (){
  vector<int>aux;
  aux = Token;
  Token.clear();
  while (!aux.empty()){
    Token.push_back(aux.back());
    aux.pop_back();
  }
  aux.clear();
}

void Tokens::printTokens(){
  int i;
  while (i < Token.size()){
    cout << Token[i] << " ";
    i++;
  }
}

bool Tokens::IsEqual (int tok_, int need) {
  if (tok_ == need) return true;
  else return false;
}

bool Tokens::NextIsEqual(int t){
  int next = getToken();
  if (next == t){
  return true;
  } else return false;

}
