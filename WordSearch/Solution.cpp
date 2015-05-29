#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
  bool exist(vector< vector<char> > &board, string word){
	for(vector< vector<char> >::iterator line_iter = board.begin(); line_iter != board.end(); ++line_iter){
	  for(vector<char>::iterator char_iter = line_iter->begin(); char_iter != line_iter->end(); ++char_iter){
	    
	  }
	}
    return false;
  }
};

class Point{
public: 
  char val;
  int coordinate_x;
  int coordinate_y;

  Point(){
	coordinate_x = 0;
	coordinate_y = 0;
  }
  
  Point(char val, int coordinate_x, int coordinate_y) : val(val), coordinate_x(coordinate_x), coordinate_y(coordinate_y) {}

};

int main(){
  Solution s;
  Point p('a', 1, 2);
  vector< vector<char> > board;
  vector<char> line_1(10,'a');
  vector<char> line_2(20,'b');
  board.push_back(line_1);
  board.push_back(line_2);
  s.exist(board, "a");
}
