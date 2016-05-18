#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

class Solution {
  public:
    void solveSudoku(vector<vector<char>> &board) {
      vector<vector<set<char>>> vvs;
      vector<set<char>> vs;
      set<char> s = {'1','2','3','4','5','6','7','8','9'};
      for (int i = 0; i < 9; ++i) {
        vvs.push_back(vs);
        for (int j = 0; j < 9; ++j) {
          vvs[i].push_back(s);
        }
      }
      
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.at(0).size(); ++j) {
          char c = board[i][j];
          if (c != '.') {
            vvs[i][j].clear();
            for (int k = 0; k < 9; ++k) {
              vvs[i][k].erase(c);
              vvs[k][j].erase(c);
            }
            for (int m = (i/3)*3; m < (i/3+1)*3; ++m) {
              for (int n = (j/3)*3; n < (j/3+1)*3; ++n) {
                vvs[m][n].erase(c);
              }
            }
          }
        }
      }

      cout << "------------------" <<endl;
      for (auto row : board) {
        for (auto c : row) {
          cout << c << " ";
        }
        cout << endl;
      }
      cout << endl;
      for (auto row : vvs) {
        for (auto col : row) {
          cout << col.size() << " ";
        }
        cout << endl;
      }
      cout << "------------------" << endl;
      
      for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
          if (board[i][j] == '.' && vvs[i][j].size() == 0) {
            return;
          }
        }
      }

      bool flag = false;
      for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
          if (vvs[i][j].size() == 1) {
            board[i][j] = * (vvs[i][j].begin());
            flag = true;
          }
        }
      }

      if (flag) {
        return solveSudoku(board);
      }


      stack<vector<vector<char>>> svv;
      for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
          if (board[i][j] == '.') {
            for (char c : vvs[i][j]) {
              board[i][j] = c;
              svv.push(board);
              board[i][j] = '.';
            }
          }
        }
      }
      
      while (!svv.empty()) {
        board = svv.top();
        svv.pop();
        solveSudoku(board);
        if (isValid(board)) {
          return;
        } else {
          continue;
        }
      }
    }
  
    bool isValid(vector<vector<char>> &board) {
      for (auto r : board) {
        for (auto c : r) {
          if (c == '.') {
            return false;
          }
        }
      }
      return true;
    }
};

int main() {
  Solution s;
  vector<vector<char>> board;
  vector<char> row;
  for (int i = 0; i < 9; ++i) {
    board.push_back(row);
  }
  board[0].push_back('.');
  board[0].push_back('.');
  board[0].push_back('.');
  board[0].push_back('.');
  board[0].push_back('.');
  board[0].push_back('7');
  board[0].push_back('.');
  board[0].push_back('.');
  board[0].push_back('9');
  
  board[1].push_back('.');
  board[1].push_back('4');
  board[1].push_back('.');
  board[1].push_back('.');
  board[1].push_back('8');
  board[1].push_back('1');
  board[1].push_back('2');
  board[1].push_back('.');
  board[1].push_back('.');
  
  board[2].push_back('.');
  board[2].push_back('.');
  board[2].push_back('.');
  board[2].push_back('9');
  board[2].push_back('.');
  board[2].push_back('.');
  board[2].push_back('.');
  board[2].push_back('1');
  board[2].push_back('.');

  board[3].push_back('.');
  board[3].push_back('.');
  board[3].push_back('5');
  board[3].push_back('3');
  board[3].push_back('.');
  board[3].push_back('.');
  board[3].push_back('.');
  board[3].push_back('7');
  board[3].push_back('2');
  
  board[4].push_back('2');
  board[4].push_back('9');
  board[4].push_back('3');
  board[4].push_back('.');
  board[4].push_back('.');
  board[4].push_back('.');
  board[4].push_back('.');
  board[4].push_back('5');
  board[4].push_back('.');

  board[5].push_back('.');
  board[5].push_back('.');
  board[5].push_back('.');
  board[5].push_back('.');
  board[5].push_back('.');
  board[5].push_back('5');
  board[5].push_back('3');
  board[5].push_back('.');
  board[5].push_back('.');

  board[6].push_back('8');
  board[6].push_back('.');
  board[6].push_back('.');
  board[6].push_back('.');
  board[6].push_back('2');
  board[6].push_back('3');
  board[6].push_back('.');
  board[6].push_back('.');
  board[6].push_back('.');

  board[7].push_back('7');
  board[7].push_back('.');
  board[7].push_back('.');
  board[7].push_back('.');
  board[7].push_back('5');
  board[7].push_back('.');
  board[7].push_back('.');
  board[7].push_back('4');
  board[7].push_back('.');

  board[8].push_back('5');
  board[8].push_back('3');
  board[8].push_back('1');
  board[8].push_back('.');
  board[8].push_back('7');
  board[8].push_back('.');
  board[8].push_back('.');
  board[8].push_back('.');
  board[8].push_back('.');

  s.solveSudoku(board);
}
