#include <iostream>
#include <vector>

class Solution {
    public:
        int coinChange(std::vector<int>& coins, int amount) {
            std::vector<int> change(amount + 1, -1);
            for (auto coin : coins) {
                if (coin >= change.size()) {
                    continue; 
                } 
                change[coin] = 1;
            }
            for (int i = 0; i < change.size(); ++i) {
                if (change[i] == -1) {
                    int min = -1;
                    for (auto coin : coins) {
                        if ( (i - coin) >= 0 && change[i - coin] != -1 ) {
                            if ( min == -1 || min > change[i - coin] ) {
                                min = change[i - coin]; 
                            } 
                        } 
                    }    
                    if ( min != -1 ) {
                        change[i]  = 1 + min;
                    }
                }
            }  
            return change[amount];
        } 
};

int main() {
    Solution s;
    std::vector<int> coins;
    coins.push_back(3);
    coins.push_back(7);
    coins.push_back(5);
    int amount = 4;
    std::cout << s.coinChange(coins, amount);
}
