#include <iostream>
#include <string>

class Solution {
    public:
        static int factorial[10];
        std::string getPermutation(int n, int k) {
            std::string s;
            for (int i = 1; i <= n; ++i) {
                s += std::to_string(i); 
            }
            std::cout << s << std::endl;
            return getPermutationUtil(s, k);
        }

        std::string getPermutationUtil(std::string s, int k) {
            std::cout << "call util function with parameter: s= " << s << " k = " << k << std::endl;
            if (k == 1) return s;
            int n = s.length();
            int d = (k - 1) / factorial[n-1];
            int m = k - d * factorial[n-1];
            std::string head = s.substr(d, 1); 
            std::cout << "append : " << head;
            return s.substr(d, 1) + getPermutationUtil(s.substr(0, d) + s.substr(d+1), m);
        }

};

int Solution::factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int main() {
    Solution s;
    std::cout << s.getPermutation(9, 17) << std::endl;     
}
