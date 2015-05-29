#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
bool compare(string a,string b) {
  if (a.find(b) == 0 && a.compare(b) != 0) {
    return compare(a.substr(b.size()), b);
  }
  if (b.find(a) == 0 && a.compare(b) != 0) {
    return compare(a, b.substr(a.size()));
  }
  
  if (a.compare(b) <= 0) {
    return false;
  } else {
    return true;
  }
}

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    vector<string> str_nums;
    for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
      str_nums.push_back(to_string(*itr));
    }
    sort(str_nums.begin(),str_nums.end(),compare);
    string s("");
    if (str_nums.at(0).compare("0") ==0) {
      return "0";
    }
    for(auto itr = str_nums.begin(); itr != str_nums.end(); ++itr) {
      s.append(*itr);
    }
    return s;  
  }

};

int main() {
  Solution s;
  int a[] = {0,0,0};
  vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
  cout << s.largestNumber(nums) << endl;
}
