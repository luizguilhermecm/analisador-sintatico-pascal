#include <vector>
#include <iostream>
#include <string>
#include <cstring>

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
  char * lower;
  lower = new char[palavra.size()+1];
  strcpy (lower, palavra.c_str());
  if (strcasecmp(lower,"program")==0) {
    setToken (PROGRAM);
    return true;
  }
  if (strcasecmp(lower,"var")==0) {
    setToken (VAR);
    return true;
  }
  if (strcasecmp(lower,"begin")==0) {
    setToken (BEGIN);
    return true;
  }
  if (strcasecmp(lower,"end")==0) {
    setToken (END);
    return true;
  }
  if (strcasecmp(lower,"function")==0) {
    setToken (FUNCTION);
    return true;
  }
  if (strcasecmp(lower,"procedure")==0) {
    setToken (PROCEDURE);
    return true;
  }
  if (strcasecmp(lower,"then")==0) {
    setToken (THEN);
    return true;
  }
  if (strcasecmp(lower,"if")==0) {
    setToken (IF);
    return true;
  }
  if (strcasecmp(lower,"not")==0) {
    setToken (NOT);
    return true;
  }
  if (strcasecmp(lower,"or")==0) {
    setToken (OR);
    return true;
  }
  //if (strcasecmp(lower,"true") {
  //  return true;
  //}
  if (strcasecmp(lower,"else")==0) {
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
