#include <iostream>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        int square_sum;
        do {
            square_sum = 0;
            while (n != 0) {
                square_sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = square_sum;
            cout << square_sum << " ";
        } while (square_sum >= 10);
        if (square_sum == 1) {
            return true;
        } else {
            return false;
        }
    }
}; 

int main() {
  Solution s;
  for (int i = 1; i < 999; ++i) {
    cout << i << " : " << s.isHappy(i) << endl;
  }
}
