#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    if (s.length() == 0) {
      return 0;
    }

    vector<int> nums;

    // initialize 
    if (isValid(s.substr(0,1))) {
      nums.push_back(1);
    } else {
      return 0;
    }

    nums.push_back(0);

    if (isValid(s.substr(0,2))) {
      nums[1]++;
    }
    if (isValid(s.substr(1,1))) {
      nums[1]++;
    }

    for (int i = 2; i < s.length(); ++i) {
      nums.push_back(0);
      if (isValid(s.substr(i,1))) {
        nums[i] += nums[i-1];
      } 
      if (isValid(s.substr(i-1,2))) {
        nums[i] += nums[i-2];
      }
    }
    return nums.back();
  } 

  bool isValid(string s) {
    if (s.length() == 1) {
      return '1' <= s[0] && s[0] <= '9';
    } else if (s.length() == 2) {
      if (s[0] == '1') {
        return '0' <= s[1] && s[1] <= '9';
      } else if (s[0] == '2') {
        return '0' <= s[1] && s[1] <= '6';
      }
      return false;
    }
    return false;
  }
};

int main() {
  string str;
  Solution s;
  while (cin >> str) {
    cout << s.numDecodings(str) << endl;
  }
}
