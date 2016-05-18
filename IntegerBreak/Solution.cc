#include <cmath>
#include <iostream>

class Solution {
    public:
        int integerBreak(int n) {
            if (n <= 3) {
                return n - 1; 
            }

            if (n%3==0) {
                return std::pow(3, n/3); 
            } else if (n%3 == 1) {
                return std::pow(3, n/3 - 1) * 4; 
            } else {
                return std::pow(3, n/3) * 2;
            }
        }
};

int main() {
    Solution s;
    for (int i = 0; i < 20; ++i) {
        std::cout << s.integerBreak(i) << std::endl;
    }
}
