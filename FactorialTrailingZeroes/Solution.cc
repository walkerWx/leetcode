#include <iostream>

using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    int numZeros = 0;
    while ( n != 0) {
      n /= 5;
      numZeros += n; 
    }
    return numZeros;
  }

  long factorial(int n) {
    long output = 1;
    while(n != 0) {
      output *= n--;
    }
    return output;
  }
};

int main() {
  int n = 0;
  Solution s;
  while (n != -1) {
    cin >> n;
    cout << s.factorial(n) << endl;
    cout << s.trailingZeroes(n) << endl;
  }
}
