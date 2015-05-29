#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    map<int, int> duplicate;
    map<int, int>::iterator itr;
    for (int num : nums) {
      itr = duplicate.find(num);
      if (itr != duplicate.end()) {
        return true;
      } else {
        duplicate.insert(pair<int, int>(num, 1));
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> nums;
  int num;
  while (cin >> num ) {
    nums.push_back(num);
  }
  cout << s.containsDuplicate(nums) << endl;
}
