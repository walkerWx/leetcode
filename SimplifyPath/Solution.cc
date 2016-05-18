#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, elems);
  return elems;
}

class Solution {
  public:
    string simplifyPath(string path) {
      vector<string> files= split(path,'/');
      string current;
      stack<string> simplifyPath;
      for (string file : files) {
        if (file.compare(".") == 0 || file.compare("") == 0) {
          continue;
        }

        if (simplifyPath.empty()) {
          simplifyPath.push(file);
          continue;
        }

        if (file.compare("..") == 0) {
          current = simplifyPath.top();
          if (current.compare("..") == 0) {
            simplifyPath.push(file);
          } else {
            simplifyPath.pop();
          }
        } else {
          current = simplifyPath.top();
          if (current.compare("..") == 0) {
            simplifyPath.pop();  
          } else {
            simplifyPath.push(file);
          }
        }
      }

      // now the path is in reverse order, we should reverse it
      string s = "";
      stack<string> reverse;
      while (!simplifyPath.empty()) {
        reverse.push(simplifyPath.top());
        simplifyPath.pop();
      }
      while (!reverse.empty()) {
        s += "/" + reverse.top();
        reverse.pop();
      }
      if (s.compare("") == 0) {
        return "/";
      }
      
      return s;
    }
};


int main() {
  string path;
  cin >> path;
  Solution s;
  cout << s.simplifyPath(path) << endl;
}
