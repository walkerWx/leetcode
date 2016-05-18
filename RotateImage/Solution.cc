#include <iostream>
#include <vector>

class Solution {
  public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      if (n == 0) {
        return;
      }
      
      for (int i = 0; i < (n + 1) / 2; ++i) {
        for (int j = 0; j < (n + 1) / 2 - n % 2 ; ++j) {
          swap(matrix[i][j], matrix[j][n-1-i]);
          swap(matrix[n-1-j][i], matrix[i][j]);
          swap(matrix[n-1-i][n-1-j], matrix[n-1-j][i]);
        } 
      }

    }

    void swap(int& a, int& b) {
      a = a + b;
      b = a - b;
      a = a - b;
    }
}

//i j
//j n-1-i
//n-1-i n-1-j
//n-1-j i

1 2 3
4 5 6
7 8 9

7 2 4 
8 5 1
9 6 3
