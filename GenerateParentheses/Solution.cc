#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> generateParenthesis(int n) {
      vector<string> parenthesis;
      if (n == 0) {
        parenthesis.push_back("");
        return parenthesis;
      }
      if (n == 1) {
        parenthesis.push_back("()");
        return parenthesis;
      }
      for (string s : generateParenthesis(n - 1)) {
        string special = "";
        for (int i = 0; i < n - 1; ++i) {
          special += "()";
        }
        if (s.compare(special) == 0) {
          parenthesis.push_back(s + "()");
        } else {
          parenthesis.push_back(s + "()");
          parenthesis.push_back("()" + s);
        }
        parenthesis.push_back("(" + s + ")");
      }
      return parenthesis;
    }
};

int main() {
  int n;
  Solution s;
  cin >> n ;

  for (string str : s.generateParenthesis(n)) {
    cout << str << endl;
  }
  
}
