#include <iostream>
#include <stdexcept>

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0) {
      if (x == 0) {
        throw invalid_argument("invalide argument");
      }
      return 1;
    }
    if (n == 1) {
      return x;
    }
    if ( n == -1) {
      return 1.0 / x;
    }
    //double tmp = myPow(x, n/2);
    //return tmp * tmp * myPow(x,n%2); 
    return  myPow(x, n/2)* myPow(x, n/2) * myPow(x,n%2); 
  }
};

int main () {
  int n;
  Solution s;
  cin >> n;
  for (int i =0; i< n; ++i) {
    s.myPow(1.0000,-2147483648);
  }
}
