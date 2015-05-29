#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    if (s.length() <= 1) {
      return s.length;
    }
    vector<int> v;
    for (int i = 0; i < s.length(); ++i) {
      v.push_back(-1);
    }
    v.at(0) = 1;
    if (s.at(s.length() - 2) == '1' || (s.at(s.length() - 2) == '2' && s.at(s.length() - 1) <= '6') ) {
      v.at(1) = 2;
    } else {
      v.at(1) = 1;
    }
    for (int i = 2; i < s.length(); ++i) {
      if (s.at(s.length() - i - 1) == '1' || (s.at(s.length() - i - 1) == '2' && s.at(s.length() - i ) <= '6')) {
        v.at(i) = v.at(i - 1) + v.at(i - 2);
      } else {
        v.at(i) = v.at(i - 1);
      } 
    }
    for (int i : v) {
      cout << i << " ";
    }
    cout << endl;
    return v.at(s.length() - 1);
  }
};

int main() {
  string str;
  Solution s;
  while (cin >> str) {
    s.numDecodings(str);
  }
}
