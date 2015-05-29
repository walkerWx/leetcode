#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
  bool canJump(int A[], int n) {
    bool visited[n];
    for (int i = 0; i < n; ++i) {
      visited[i] = false;
    }

    stack<int> toVisit;

    // you are initially positioned at the first index of the array.
    toVisit.push(0);
    int visiting = 0;
    while ( !toVisit.empty() ) {
      visiting = toVisit.top();
      toVisit.pop();
      if ( visited[visiting] ) {
        continue;
      }
      visited[visiting] = true;
      for (int i = 0; i < A[visiting]; ++i) {
        if ( visiting + i + 1 >= n ) {
          break;
        }
        if ( !visited[visiting + i + 1] ) {
          toVisit.push(visiting + i + 1);
        }
      }
      for ( int i = 0; i < n; ++i ) {
        cout << visited[i] << " ";
      }
      cout << endl;
      if ( visited[n-1] ) {
        return true;
      }
    }
    return false; 
  }
};

class S {
public:
  bool canJump(int A[],int n) {
    int lowerBound = 0, higherBound = 0;
    int nextBound = 0;
    while (higherBound < n - 1) {
      for (int i = 0; i <= (higherBound - lowerBound); ++i  {
        if (nextBound < (lowerBound + i + A[lowerBound + i]) ) {
          nextBound = lowerBound + i + A[lowerBound + i];
        }
      }
      lowerBound = higherBound+ 1;
      higherBound = nextBound;
      if(lowerBound > higherBound) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  S s;
  int n = 5;
  int A[] = {2,3,1,1,0};
  cout << s.canJump(A,n) << endl;
}
