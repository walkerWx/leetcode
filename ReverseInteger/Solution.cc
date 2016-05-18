#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int reverse(int x) {
      bool negative = false;
      if (x < 0) {
        negative = true;
        x = -x;
      }
      string str = to_string(x);
      ::reverse(str.begin(), str.end());
      stringstream ss(str);
      ss >> x;
      return negative? -x : x;
      
    }
};

int main() {
  int x = 0;
  Solution s;
  cin >> x;
  cout << s.reverse(x) << endl;
}
