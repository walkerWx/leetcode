#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int maxDepth(TreeNode *root) {
    stack<TreeNode *> s;
    TreeNode *t;
    int depth(0);
    if (!root) {
      return 0;
    }
    s.push(root);
    
    while (!s.empty()) {
      t = s.top();
      s.pop();
    }
    
  }
}
