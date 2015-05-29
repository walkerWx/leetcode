#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    string whitespace = " \t";
    auto beginWord = s.find_first_not_of(whitespace);
    while (beginWord != string::npos) {
      const auto endWord = s.find_first_of(whitespace, beginWord);
      if (endWord == string::npos) {
        reverse(s.begin() + beginWord, s.end());
        break;
      }
      reverse(s.begin() + beginWord, s.begin() + endWord);
      const auto newStart = endWord + 1;
      beginWord = s.find_first_not_of(whitespace, newStart);
    }
    s = reduce(s);
  }

  string trim(const string &str, const string &whitespace = " \t") {
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos) {
      return "";
    }
    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
  }

  string reduce(const string &str, const string &fill = " ", const string &whitespace = " \t") {
    auto result = trim(str, whitespace);
    auto beginSpace = result.find_first_of(whitespace);
    while (beginSpace != std::string::npos) {
      const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
      const auto range = endSpace - beginSpace;
      result.replace(beginSpace, range, fill);
      const auto newStart = beginSpace + fill.length();
      beginSpace = result.find_first_of(whitespace, newStart);
    }
    return result;
  }
};

int main() {
  Solution s;
  string str;
  while (true) {
    getline(cin,str);
    s.reverseWords(str);
    cout << str << endl;
  }
}
