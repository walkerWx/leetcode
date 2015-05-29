#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string output("");
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int p, q, carry = 0;
    int length  = max(a.length(), b.length());
    for (int i = 0; i <= length; ++i) {
      if (i >= a.size()) {
        p = 0;
      } else {
        p = a.at(i) - '0';
      }
      if (i >= b.size()) {
        q = 0;
      } else {
        q = b.at(i) - '0';
      }
      
      output.push_back(char((p + q + carry)%2 + '0'));
      if ((p + q + carry) > 1) {
        carry = 1;
      } else {
        carry = 0;
      }
    }
    reverse(output.begin(), output.end());
    while (output.front() == '0' && output.length() != 1) {
      output = output.substr(1);
    }
    return output;
  }
};

int main() {
  Solution  s;
  string a, b;
  while (true) {
    cin >> a;
    cin >> b;
    cout << s.addBinary(a,b) << endl;
  }
}
