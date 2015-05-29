#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findMin(vector<int> &num) {
    return findMin(num, 0, num.size() - 1);
  }

  int findMin(vector<int> &num, int begin,int end) {
    if (begin < 0 || end < 0 || begin >= num.size() || end >= num.size()) {
      cerr << "vector: out of bound exception" << endl;
      return 0;
    }
    if (num.at(begin) <= num.at(end)) {
      return num.at(begin);
    } else {
      return min(findMin(num, begin, (begin + end)/2), findMin(num,(begin + end)/2 + 1,end));
    }
  }
};

int main() {
  Solution s;
  vector<int> num;
  //for (int i = 0; i < 10; ++i) {
  //  num.push_back(11-i);
  //}
  //num.push_back(1);
  num.push_back(13);
  cout << s.findMin(num) << endl;
}
