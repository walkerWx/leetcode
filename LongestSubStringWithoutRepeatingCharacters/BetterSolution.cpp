#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BetterSolution {
 static const int M = 128; 
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0) {
	  return 0;
	}

	int begin = 0;
	int end = 0;
	int maxLength = 0;
    bool exist[M] = {false};
    
    while (true) {
      if (end == s.size()) {
        return max(maxLength, end - begin);
      }

      if (exist[s[end]] == true) {
        maxLength = max(maxLength, end - begin);
        for(; s[begin] !=s[end]; ++begin) {
          exist[s[begin]] = false;
        }
        exist[s[end]] = true;
        ++begin;
        ++end;
      } else {
        exist[s[end]] = true;
        ++end;
      }
    }
  }
};

int main(){
  string s;
  BetterSolution bs;
  cin >> s;
  cout << bs.lengthOfLongestSubstring(s) << endl;
}
