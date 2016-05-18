#include <iostream>

using namespace std;

class Solution {
  public:
    int uniquePaths(int m, int n) {
      if (m > n) {
        return uniquePaths(n, m);
      }
      if (m <= 0) {
        return 0;
      }

      long int numPaths = 1;

      for (int i = 1; i <=m; ++i) {
        numPaths *= (i + n);
        numPaths /= i;
      }
      return numPaths;
    }
}
