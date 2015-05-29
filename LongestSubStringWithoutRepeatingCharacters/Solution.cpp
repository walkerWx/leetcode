#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
  int lengthOfLongestSubstring(string s){
    if(s.size() == 0){
	  return 0;
	}
  
    int begin = 0;
    int end = 0;
	int maxLength = 0;
    
	while(begin != s.size() && end != s.size()){
	  vector<bool> exist(256, false);
	  end = begin;
	  while(true){
	    cout << "Position: " << end << " . Character: " << s[end] << endl;
	    if(end == s.size()){
		  cout << "if: end == size()" << endl;
		  maxLength = max(maxLength, end - begin);
		  return maxLength;
		}

		if(exist.at(s[end]) == true){
		  cout << "if: find repeating character" << endl;
		  showExistingCharacters(exist);
		  maxLength = max(maxLength, end - begin);
		  for(int i = begin; i != end; ++i){
		    if(s[i] == s[end]){
			  begin = i + 1;
			  break;
			}
		  }
		  break;
		}
		else{
		  cout << "else" << endl;
		  exist.at(s[end]) = true;
		  //showExistingCharacters(exist);
		  end++;
		}
	  }
	}
	return maxLength;
  }

private:
  void showExistingCharacters(vector<bool> exist){
    for(vector<bool>::iterator itr = exist.begin(); itr !=  exist.end(); ++itr){
	  cout << *itr;
	}
	cout << endl;
  }
};

int main(){
 string s;
 cin >> s;
 Solution solution;
 cout << solution.lengthOfLongestSubstring(s) << endl;
}
