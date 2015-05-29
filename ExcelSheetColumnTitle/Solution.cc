#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int titleToNumber(string s) {
    if (s.length() == 0) {
      return 0;
    }  
    return titleToNumber(s.substr(0, s.length() - 1))*26 + (s.back() - 'A' + 1);
  }
};

int main() {
  string s = "AB";
  Solution sl;
  cout << s.substr(0,3) <<endl;
  cout << sl.titleToNumber(s) << endl;
}
