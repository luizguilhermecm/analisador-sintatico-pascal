#include <iostream>
#include <vector>

using namespace std;

class Tokens{
  public:
    int getToken ();
    void setToken (int new_token);
    bool isEqual (int token_comparativo);
    void EraseToken ();

  private:
    vector<int> Token;
};
