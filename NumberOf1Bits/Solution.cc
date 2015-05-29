#include <iostream>

using namespace std;

class Solution {
  public:
    int hammingWeight(uint32_t n) {
      n = n - ((n >> 1) & 0x55555555);
      n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
      return (((n + (n >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
    }
};

int main() {
  uint32_t n;
  Solution s;
  cin >> n;
  cout << s.hammingWeight(n) << endl;
}
