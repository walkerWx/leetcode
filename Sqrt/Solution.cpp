#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
  int sqrt(int x){
    int middle = log(x) / 2;
    int small = pow(10, middle) , large = min(pow(10, middle + 1),46341.0);// 46341 is the largest root of type int
    int root = small;
    while (root * root != x) {
      if ( large == small + 1) {
        return small;
      } 
      int root = (small + large) / 2;
      if(root * root > x) {
        large = root;
      } else if ( root * root < x) {
        small = root;
      } else {
        return root;
      }
    }
    return root;
  }

  int log(int x) {
    int a = 0;
    if(x >= 100000000) {
      x /= 100000000;
      a += 8;
    }
    if( x >= 10000) {
      x /= 10000;
      a += 4;
    }

    if(x >= 100) {
      x /= 100;
      a += 2;
    }
    
    if(x >= 10) {
      x /= 10;
      a += 1;
    }
    return a;
  }
};

