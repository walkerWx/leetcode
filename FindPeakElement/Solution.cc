#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    if (nums.size() <= 1) {
      return 0;
    }

    int middle = nums.size() / 2;
    if (nums.at(middle - 1) >= nums.at(middle)) {
      vector<int> sub(nums.begin(), nums.begin() + middle);
      return findPeakElement(sub);
    } else {
      vector<int> sub(nums.begin() + middle, nums.end());
      return middle + findPeakElement(sub);
    } 
  }
};

int main() {
  vector<int> nums;
  int n = 0;
  while(n != -1) {
    cin >> n;
    nums.push_back(n);
  }
  Solution s;
  cout << s.findPeakElement(nums) << endl;
}
