#include <iostream>
#include <vector>

class Token {
  public:
    int getToken ();
    void setToken (int new_token);
  
  private:
    vector<int> Tokens;
}
