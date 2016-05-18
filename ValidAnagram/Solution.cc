#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
    public:
        bool isAnagram(std::string s, std::string t) {
            std::unordered_map<char, int> m;
            if (s.length() != t.length()) return false;
            for (int i = 0; i < s.length(); ++i) {
                ++m[s[i]];     
                --m[t[i]];
            }  
            for (auto itr = m.begin(); itr != m.end(); ++itr) {
                if (itr->second != 0) {
                    return false; 
                } 
            }
            return true;
        }
};

int main() {
    Solution solution;
    std::string s, t; 
    std::cin >> s >> t;
    std::cout << solution.isAnagram(s, t);
}
