#include <iostream>

using namespace std;

class Solution {
public:
  int maxProduct(int A[], int n) {
    int product = 0;
    int i;
    for (i = 0; i < n; ++i) {
      if(A[i] != 0){
        product *= A[i];       
      } else {
        break;
      }
    }

    if(i == n) {
      if(product > 0) {
        return product;
      } else {
        
      }
    }
  }
}
