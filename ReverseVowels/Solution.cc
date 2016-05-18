#include <iostream>
#include <string>

class Solution {
    public:
        std::string reverseVowels(std::string s) {
            int i = 0; 
            int j = s.length() - 1;
            char c;
            while (i < j) {
                if (!isVowel(s[i])) {
                    ++i; 
                } else if (!isVowel(s[j])){
                    --j; 
                } else {
                    c = s[i];  
                    s[i] = s[j];
                    s[j] = c;
                    ++i;
                    --j;
                }
            }
            return s;
        }

    private:
        bool isVowel(char c) {
            std::string vowels = "aeiouAEIOU";
            return vowels.find(c) != std::string::npos;
        }
};

int main() {
    std::string s = "abcdefgh";
    Solution solution;
    std::cout << solution.reverseVowels(s);
}
