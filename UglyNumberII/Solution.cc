#include <iostream>
#include <vector>

class Solution {
    public:
        int nthUglyNumber(int n) {
            int pointer_2 = 0, pointer_3 = 0, pointer_5 = 0;
            std::vector<int> ugly_numbers;
            ugly_numbers.push_back(1);
            int p2, p3, p5;
            for (int i = 0; i <= n; ++i) {
                p2 = ugly_numbers[pointer_2] * 2;
                p3 = ugly_numbers[pointer_3] * 3;
                p5 = ugly_numbers[pointer_5] * 5;
                if (p2 == p3 && p3 == p5) {
                    ugly_numbers.push_back(p2);
                    ++pointer_2; 
                    ++pointer_3; 
                    ++pointer_5; 
                    continue;
                } 

                if (p2 == p3 && p3 < p5) {
                    ugly_numbers.push_back(p2); 
                    ++pointer_2; 
                    ++pointer_3; 
                    continue;
                }

                if (p2 == p5 && p2 < p3) {
                    ugly_numbers.push_back(p2); 
                    ++pointer_2; 
                    ++pointer_5; 
                    continue;
                }

                if (p3 == p5 && p3 < p2) {
                    ugly_numbers.push_back(p3); 
                    ++pointer_3; 
                    ++pointer_5; 
                    continue;
                }

                if (p2 < p3 && p2 < p5) {
                    ugly_numbers.push_back(p2); 
                    ++pointer_2;
                    continue;
                }

                if (p3 < p2 && p3 < p5) {
                    ugly_numbers.push_back(p3); 
                    ++pointer_3;
                    continue;
                }

                if (p5 < p2 && p5 < p3) {
                    ugly_numbers.push_back(p5); 
                    ++pointer_5;
                    continue;
                }

            }
            return ugly_numbers.back();
        }

};

int main() {
    Solution s;
    for (int i = 0; i < 120; ++i) {
        std::cout << s.nthUglyNumber(i) << " "; 
    }
}
