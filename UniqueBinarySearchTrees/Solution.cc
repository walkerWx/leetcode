#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numTrees(int n) {
    static const int arr[] = {1,1}; 
    static int m = 1;
    static vector<int> nums(arr,arr + sizeof(arr)/sizeof(arr[0]));

    for (int i = 0; i < nums.size(); ++i) {
      cout << nums.at(i) << " ";
    }
    cout << endl;

    if (m >= n) {
      return nums.at(n);
    } else {
      for (int i = m + 1; i <= n; ++i) {
        nums.push_back(0);
        for (int j = 0; j < i; ++j) {
          nums.at(i) += nums.at(j) * nums.at(i - j - 1);
        }
      }
      m = n;
      return nums.at(n);
    }
  }
private:
};

int main() {
  Solution s;
  //cout << s.numTrees(5) << endl;
  cout << s.numTrees(3) << endl;
  cout << s.numTrees(10) << endl;
  cout << s.numTrees(8) << endl;
}
