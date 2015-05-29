#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > output;
    stack<vector<int> > s;

    if (k == 0 || k > n) {
      return output;
    } 
    // initialization
    for (int i = 1; i < n - k + 2; ++i) {
      vector<int> init;
      init.push_back(i);
      s.push(init);
    }

    while (!s.empty()) {
      vector<int> v = s.top();
      s.pop();

      if (v.size() == k) {
        output.push_back(v);
        continue;
      }
      
      for (int i = v.back() + 1; i < n - k + v.size() + 2; ++i) {
        vector<int> cp (v);
        cp.push_back(i);
        s.push(cp);
      }
    } 
    return output;
  }
};

int main() {
  int n,k;
  Solution s;
  while (true) {
    cin >> n;
    if (n == -1) {
      break;
    }
    cin >> k;
    vector<vector<int> > output = s.combine(n,k);
    for (auto v : output) {
      for(auto i : v) {
        cout << i << " ";
      }
      cout << endl;
    }
    cout << "total : " << output.size() << endl;
  }
}
