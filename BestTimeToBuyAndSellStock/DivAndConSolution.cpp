#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution{
public:
  int maxProfit(vector<int> &prices){
    return maxProfitRec(prices.begin(), prices.end());
  }
private:
  int findMax(vector<int>::iterator begin, vector<int>::iterator end){
    int max = *begin;
	while(begin != end){
	  if(max <= *begin){
	    max = *begin;
	  }
	  begin++;
	}
	cout << "Find maximal : " << max << endl;
	return max;
  }
  int findMin(vector<int>::iterator begin, vector<int>::iterator end){
    int min = *begin;
	while(begin != end){
	 if(min >= *begin){
	   min = *begin;
	 }
	 begin++;
	}
	cout << "Find minimal : " << min << endl;
	return min;
  }
  int maxProfitRec(vector<int>::iterator begin, vector<int>::iterator end){
    if((end - begin) <= 1){
	  return 0;
	}
	vector<int>::iterator middle = begin + (end - begin) / 2;
	int minimal = findMin(begin, middle);
	int maximal = findMax(middle, end);
    int profit = max(maxProfitRec(begin, middle),maxProfitRec(middle,end));
	cout << "Find minimal : " << minimal << endl;
	cout << "Find maximal : " << maximal << endl;
	cout << "profit : " << profit << endl;
	return max(maximal - minimal, profit);
  }

};
int main(){
  //int size = 10000;
  //int iarray[size];
  //for(int i = 0; i < size; i++){
  //  iarray[i] = size - i;
  //}
  //vector<int> prices(iarray, iarray + size);
  vector<int> prices;
  prices.push_back(2);
  prices.push_back(1);
  prices.push_back(4);
  Solution s;
  cout << s.maxProfit(prices) << endl;
}
