#include "lexico.h"
#include <fstream>
using namespace std;


Lexico::Lexico(){
  for (int i = 0; i < estados; i++){
    for (int j = 0; j < alfabeto; j++){
      automato[i][j] = 0;
    }
  }
  automato[1][0]   = 2;
  automato[1][1]   = 3;
  automato[1][2]   = 4;
  automato[1][3]   = 5;
  automato[1][4]   = 8;
  automato[1][5]   = 10;
  automato[1][6]   = 11;
  automato[1][7]   = 12;
  automato[1][8]   = 13;
  automato[1][9]   = 15;
  automato[1][10]  = 17;
  automato[1][11]  = 19;
  automato[1][12]  = 20;
  automato[1][13]  = 21;
  automato[1][14]  = 22;
  automato[1][15]  = 23;
  automato[1][16]  = 24;
  automato[1][17]  = 25;
  automato[1][18]  = 26;
  automato[1][19]  = 27;
  automato[1][20]  = 28;
  automato[1][21]  = 29;
  automato[1][22]  = 30;
  automato[1][23]  = 40;
  automato[1][24]  = 41;
  automato[2][0]   = 2;
  automato[5][2]   = 7;
  automato[5][4]   = 6;
  automato[8][2]   = 9;
  automato[10][2]  = 31;
  automato[11][2]  = 32;
  automato[12][2]  = 33;
  automato[12][11] = 36;
  automato[13][8]  = 14;
  automato[13][11] = 38;
  automato[15][2]  = 16;
  automato[17][11] = 18;
  automato[17][8]  = 37;
  automato[17][7]  = 35;
  automato[26][18] = 39;
  automato[26][2]  = 34;

  indice[0]  = 'a';
  indice[1]  = '0';
  indice[2]  = '=';
  indice[3]  = '<';
  indice[4]  = '>';
  indice[5]  = '+';
  indice[6]  = '-';
  indice[7]  = '*';
  indice[8]  = '.';
  indice[9]  = ':';
  indice[10] = '(';
  indice[11] = ')';
  indice[12] = '[';
  indice[13] = ']';
  indice[14] = ',';
  indice[15] = '\n';
  indice[16] = ' ';
  indice[17] = ';';
  indice[18] = '/';
  indice[19] = '^';
  indice[20] = '@';
  indice[21] = '$';
  indice[22] = '#';
  indice[23] = '_';
  indice[24] = '\t';
}

int Lexico::PosicaoIndice (char ch){
  int i = 2;
  while (i < alfabeto){
    if (ch == indice [i])
      return i;
    i++;
  }
  if (isalpha(ch))
    return 0;
  if (isdigit(ch))
    return 1;
  return -1;
}

bool Lexico::IsFinal (int estado){
  if (estado != 1 && estado != 0) return true;
  else return false;
}

void Lexico::print () {
  for (int i = 0; i < estados; i++){
    cout << "\n";
    for (int j = 0; j < alfabeto; j++){
      cout << automato[i][j] << "  ";  
    }
  }
}


void Lexico::AnalisadorLexico(){
  ifstream fin ("teste.txt");
  vector<char> caracter;
  char ch;
  int i;
  while (fin.get(ch)) caracter.push_back(ch); 
  for(i = 0; i < caracter.size(); i++) cout << caracter[i]; 
  fin.clear();
  fin.close();
  cout << "\n\nSaida\n\n" << caracter.back() << "- \n" << flush;
  int current_state = 1;
  int final_state = 0;
  int indice_caracter;
  string palavra;
  i = 0;
  while (i < caracter.size()) {
    indice_caracter = PosicaoIndice(caracter[i]);
    if (indice_caracter == -1 && current_state != 1) current_state = 0;
    if (indice_caracter == -1 && current_state == 1) current_state = estado_erro;
    if (indice_caracter != -1) current_state = automato[current_state][indice_caracter];

    if (IsFinal(current_state)) final_state = current_state;

    if (current_state != 0) {
      if (current_state == 2) palavra.push_back(caracter[i]);
      if (caracter [i] != '\n') cout << caracter [i] << flush;
      if (caracter [i] == '\n') cout << "\\n" << flush;
      i++; 
    }
    if (current_state == estado_erro) exit(0);
    if (current_state == 0) {
      if (final_state == 2 || final_state == 40){
        if (IsReservada(palavra)) cout << "RESERVADA\n"; 
        else setToken(2,palavra.size());
        palavra.clear();
      }
      else Token (final_state);
      current_state = 1;
      final_state = 0;
    }
  }
  Token (final_state);
  cout << "\n\n\n\n";
  printTokens();
  cout << "\n\n\n\n";
  Inverter();
  printTokens();
}

void Lexico::Token (int final) {
	switch (final) {
		case 3 : cout << " num\n"  ; setToken (3) ; break;
		case 4 : cout << " EQ\n"   ; setToken (4) ; break;
    case 5 : cout << " <\n"    ; setToken (5) ; break;
    case 6 : cout << " <>\n"   ; setToken (6) ; break;
		case 7 : cout << " <=\n"   ; setToken (7) ; break;
		case 8 : cout << " >\n"    ; setToken (8) ; break;
		case 9 : cout << " >=\n"   ; setToken (9) ; break;
		case 10: cout << " +\n"    ; setToken (10); break;
		case 11: cout << " -\n"    ; setToken (11); break;
    case 12: cout << " *\n"    ; setToken (12); break;
    case 13: cout << " .\n"    ; setToken (13); break;
    case 14: cout << " ..\n"   ; setToken (14); break;
    case 15: cout << " :\n"    ; setToken (15); break;
    case 16: cout << " :=\n"   ; setToken (16); break;
    case 17: cout << " (\n"    ; setToken (17); break;
    case 18: cout << " ()\n"   ; setToken (18); break;
    case 19: cout << " )\n"    ; setToken (19); break;
    case 20: cout << " [\n"    ; setToken (20); break;
    case 21: cout << " ]\n"    ; setToken (21); break;
    case 22: cout << " ,\n"    ; setToken (22); break;
    case 23: cout << " \\n\n"  ; setToken (23); break;
    case 24: cout << " W\n"    ; setToken (24); break;
    case 25: cout << ";\n"     ; setToken (25); break;
    case 26: cout << " /\n"    ; setToken (26); break;
    case 27: cout << " ˆ\n"    ; setToken (27); break;
    case 28: cout << " @\n"    ; setToken (28); break;
    case 29: cout << " $\n"    ; setToken (29); break;
    case 30: cout << " #\n"    ; setToken (30); break;
    case 31: cout << " +=\n"   ; setToken (31); break;
    case 32: cout << " -=\n"   ; setToken (32); break;
    case 33: cout << " *=\n"   ; setToken (33); break;
    case 34: cout << " /=\n"   ; setToken (34); break;
    case 35: cout << " (*\n"   ; setToken (35); break;
    case 36: cout << " *)\n"   ; setToken (36); break;
    case 37: cout << " (.\n"   ; setToken (37); break;
    case 38: cout << " .)\n"   ; setToken (38); break;
    case 39: cout << " //\n"   ; setToken (39); break;
    case 40: cout << " _\n"    ; setToken (2) ; break;
    case 41: cout << " tab\n"  ; setToken (24); break;
    case 42: cout << " error\n"; break;
  }
}
