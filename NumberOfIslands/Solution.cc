#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Position { 
  static const Position npos;
  int pos_x, pos_y;
  Position(int x, int y) : pos_x(x), pos_y(y) {}
  Position() : pos_x(0), pos_y(0) {}
  vector<Position> neighbors(int n, int m) {
    vector<Position> neighbors;
    Position p;
    if (0 < pos_x) {
      p.pos_x = pos_x - 1;
      p.pos_y = pos_y;
      neighbors.push_back(p);
    }

    if (pos_x < n - 1) {
      p.pos_x = pos_x + 1;
      p.pos_y = pos_y;
      neighbors.push_back(p);
    }

    if (0 < pos_y) {
      p.pos_x = pos_x;
      p.pos_y = pos_y - 1;
      neighbors.push_back(p);
    }

    if (pos_y < m - 1) {
      p.pos_x = pos_x;
      p.pos_y = pos_y + 1;
      neighbors.push_back(p);
    }

    return neighbors;
  } 
  bool operator==(const Position &p) {
    return this->pos_x == p.pos_x && this->pos_y == p.pos_y;
  }
  bool operator!=(const Position &p) {
    return this->pos_x != p.pos_x || this->pos_y != p.pos_y;
  }
};

const Position Position::npos(-1,-1);


class Solution {
public:
  int numIslands(vector<vector<char> > &grid) {
    int num = 0;
    stack<Position> s;
    Position p;
    for (int i = 0; i < grid.size(); ++i) {
      for(int j = 0; j < grid.at(0).size(); ++j) {
        if (grid.at(i).at(j) == '1') {
          p.pos_x = i;
          p.pos_y = j;
          s.push(p);
        }
      }
    }
    while (!s.empty()) {
      p = s.top();
      s.pop();
      if (grid.at(p.pos_x).at(p.pos_y) == '0') {
        continue;
      } 
      ++num;
      sinkIsland(grid,p);
    }

    return num;
  }

  Position findIsland(vector<vector<char> > &grid) {
    for(int i = 0; i < grid.size(); ++i) {
      for(int j = 0; j < grid.at(0).size(); ++j) {
        if (grid.at(i).at(j) == '1') {
          Position p(i,j);
          return p;
        }
      }
    }
    return Position::npos;
  }

  void sinkIsland(vector<vector<char> > &grid, Position pos) {
    if (pos == Position::npos) {
      return;
    }
    stack<Position> s;
    s.push(pos);
    while (!s.empty()) {
      Position p = s.top();
      s.pop();
      grid.at(p.pos_x).at(p.pos_y) = '0';
      for (auto neighbor : p.neighbors(grid.size(), grid.at(0).size())) {
        if (grid.at(neighbor.pos_x).at(neighbor.pos_y) == '1') {
          s.push(neighbor);
        }
      }
    }
  }
};


void showIsland(const vector<vector<char> > &grid) {
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid.at(0).size(); ++j) {
      cout << grid.at(i).at(j) << " "; 
    }
    cout << endl;
  }
  cout << endl;
}


int main() {
  Solution s;
  int n = 0, m = 0;
  char c;
  vector<vector<char> > grid;
  cin >> n;
  cin >> m;
  for (int i = 0; i < n; ++i) {
    vector<char> line;
    for (int j = 0; j < n; ++j) {
      cin >> c;
      line.push_back(c);
    }
    grid.push_back(line);
  }

  cout << s.numIslands(grid) << endl;
  
  
  
  
}
