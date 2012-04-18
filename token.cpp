#include <vector>
#include <iostream>
#include "token.h"

using namespace std;

void Tokens::setToken (int new_token) {
  Token.push_back(new_token);
}

int Tokens::getToken () {
  return Token.back();
}

void Tokens::EraseToken () {
  Token.pop_back();
}

bool Tokens::isEqual (int token_comparativo) {
  if (Token.back() == token_comparativo)
    return true;
  else
    return false;
}
