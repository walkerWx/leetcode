#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    for(char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        stk.push(c);
      } else if (c == ')') {
        if (!stk.empty() && stk.top() == '(') {
          stk.pop();
          continue;
        } else {
          return false;
        }
      } else if (c == ']') {
        if (!stk.empty() && stk.top() == '[') {
          stk.pop();
          continue;
        } else {
          return false;
        }
      } else if (c == '}') {
        if (!stk.empty() && stk.top() == '{') {
          stk.pop();
          continue;
        } else {
          return false;
        }
      }
    }
    if (stk.empty()){
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  string str;
  Solution s;
  while (true) {
    cin >> str;
    cout << s.isValid(str) << endl;
  }
}
