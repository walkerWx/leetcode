#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> countBits(int num) {
            std::vector<int> bits;
            bits.push_back(0);
            while (bits.size() <= num) {
                int size = bits.size();
                bits.push_back(1);
                for (int i = 1; i < size && bits.size() <= num; ++i) {
                    bits.push_back(1+bits[i]); 
                }
            }
            return bits;
        }
};

int main() {
    Solution s;
    int i;
    std::cin >> i;
    std::vector<int> bits = s.countBits(i);
    for (int i = 0; i < bits.size(); ++i) {
        std::cout << bits[i] << " "; 
    }
}
