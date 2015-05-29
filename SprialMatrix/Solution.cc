#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> sprialOrder(vector<vector<int> > &matrix) {
    vector<int> result;
    if (matrix.size() == 0) {
      return result;  
    }
    int rows = matrix.size();
    int cols = matrix.at(0).size(); 
    int loop = min((rows + 1) / 2, (cols + 1 ) / 2);
    for (int i = 0; i < loop; ++i) {
      int current_cols = cols - 2 * i;
      int current_rows = rows - 2 * i;
      if (current_cols == 1 && current_rows == 1) { 
        result.push_back(matrix.at(i).at(i));
        break;
      }
      if (current_cols == 1) {
        for (int j = i; j < rows - i ; ++j) {
          result.push_back(matrix.at(j).at(i));
        }
        break;
      }
      if (current_rows == 1) {
        for(int j = i; j < cols - i; ++j) {
          result.push_back(matrix.at(i).at(j));
        }
        break;
      }
      for (int j = i; j < cols - i - 1; ++j) {
        result.push_back(matrix.at(i).at(j));
      }
      for (int j = i; j < rows - i - 1; ++j) {
        result.push_back(matrix.at(j).at(cols - i - 1));
      }
      for (int j = i; j < cols - i - 1; ++j) {
        result.push_back(matrix.at(rows - i - 1).at(cols - j - 1));
      }
      for (int j = i; j < rows - i - 1; ++j) {
        result.push_back(matrix.at(rows - j - 1).at(i));
      }
    }
    return result;
  }
};

int main() {
  int a1[] = {1,2,3};
  int a2[] = {4,5,6};
  int a3[] = {7,8,9};
  int a4[] = {13,14,15,16};
  int a5[] = {17,18,19,20};
  vector<int> v1 (a1, a1 + sizeof(a1) / sizeof(a1[0]));
  vector<int> v2 (a2, a2 + sizeof(a2) / sizeof(a2[0]));
  vector<int> v3 (a3, a3 + sizeof(a3) / sizeof(a3[0]));
  vector<int> v4 (a4, a4 + sizeof(a4) / sizeof(a4[0]));
  vector<int> v5 (a5, a5 + sizeof(a5) / sizeof(a5[0]));
  
  vector<vector<int> > matrix;
  matrix.push_back(v1);
  matrix.push_back(v2);
  matrix.push_back(v3);
  //matrix.push_back(v4);
  //matrix.push_back(v5);

  Solution s;
    
  vector<int> r = s.sprialOrder(matrix);

  for(auto itr = r.begin(); itr != r.end(); ++itr) {
    cout << *itr << " ";
  }
  cout << endl;
}
