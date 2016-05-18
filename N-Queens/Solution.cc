#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        std::vector<std::vector<std::string>> solveNQueens(int n) {
            std::vector<std::vector<std::string>> solution;
            std::vector<int> queens;
            std::vector<std::vector<int>> occupation(n, std::vector<int>(n, 0)); 
            int row = 0;
            dfs(queens, occupation, solution, row, n); 
            return solution;
        }

    private:
        void dfs(std::vector<int>& queens, std::vector<std::vector<int>>& occupation, std::vector<std::vector<std::string>>& solution, int row, int n) {
            std::cout << "-------------------------------------------" << std::endl;
            std::cout << "ROW : " << row << std::endl;
            std::cout << "QUEEN'S POSTION:" << std::endl; 
            for (unsigned int i = 0; i < queens.size(); ++i) {
                std::cout << "( " << i << ", " << queens[i] << " )" << std::endl; 
            }
            std::cout << "OCCUPATION:" << std::endl; 
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    std::cout << occupation[i][j] << "\t"; 
                } 
                std::cout << std::endl;
            }
            if (row == n) {
                // contrust a solution according to queens 
                std::vector<std::string> line;
                for (unsigned int i = 0; i < queens.size(); ++i) {
                    std::string s(n, '.');        
                    s[queens[i]] = 'Q';
                    line.push_back(s);
                }
                solution.push_back(line);
                return;
            } 
            
            for (int col = 0; col < n; ++col) {
                if (occupation[row][col] == 0) {
                    queens.push_back(col);    // add a queen to that positon 
                    // update occupation 
                    occupation[row][col]++;
                    for (int j = 0; j < n; ++j) {
                        if (j != col) {
                            occupation[row][j]++;  
                        }
                        if (j != row) {
                            occupation[j][col]++;
                        }
                        if (j != 0 && row + j < n && col + j < n) {
                            occupation[row+j][col+j]++; 
                        }
                        if (j != 0 && row - j >= 0 && col - j >= 0) {
                            occupation[row-j][col-j]++; 
                        }
                        if (j != 0 && row + j < n && col - j >= 0) {
                            occupation[row+j][col-j]++; 
                        }
                        if (j != 0 && row - j >= 0 && col +j < n) {
                            occupation[row-j][col+j]++; 
                        }
                    }
                    
                    ++row;                 // update row 

                    dfs(queens, occupation, solution, row, n);

                    --row;
                    occupation[row][col]--;
                    for (int j = 0; j < n; ++j) {
                        if (j != col) {
                            occupation[row][j]--;  
                        }
                        if (j != row) {
                            occupation[j][col]--;
                        }
                        if (j != 0 && row + j < n && col + j < n) {
                            occupation[row+j][col+j]--; 
                        }
                        if (j != 0 && row - j >= 0 && col - j >= 0) {
                            occupation[row-j][col-j]--; 
                        }
                        if (j != 0 && row + j < n && col - j >= 0) {
                            occupation[row+j][col-j]--; 
                        }
                        if (j != 0 && row - j >= 0 && col +j < n) {
                            occupation[row-j][col+j]--; 
                        }
                    }
                    queens.pop_back();
                }
            }
        }
};

int main() {
    Solution s;
    std::vector<std::vector<std::string>> result = s.solveNQueens(8);
    for (auto v : result) {
        for (auto s : v) {
            std::cout << s << std::endl; 
        } 
        std::cout << std::endl;
    }
}
