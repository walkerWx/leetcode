#include<vector>
#include<algorithm>
#include<iostream>
 
 using namespace std;

class Solution{
public:
  int maxProfit(vector<int> &prices){
    int profit = 0;
	vector<int>::iterator iter = prices.begin();
	while(iter != prices.end()){
	  int tmp;
	  iter = maxProfitInner(prices, iter, tmp);
	  profit = max(profit, tmp);
	}
	return profit;
  }
private:
  vector<int>::iterator maxProfitInner(vector<int> &prices, vector<int>::iterator iter, int &profit){
    if(iter == prices.end()){
	  return iter;
	}
	
	int max_price = *iter;
	int min_price = *iter;
	vector<int>::iterator max_iter;
	for(vector<int>::iterator i = iter; i != prices.end(); ++i){
	  if(max_price <= *i){
	    max_price = *i;
		max_iter = i;
	  }
	}
    for(vector<int>::iterator i = iter; i != max_iter; ++i){
	   if(min_price >= *i){
	     min_price = *i;
	   }
	}
  profit = max_price - min_price;
  iter = ++max_iter;
  return iter;
  }
};

int main(){
  int size = 10000;
  int array[size]; 
  for(int i = 0; i < size; i++){
    array[i] = size - i;
  }
  vector<int> prices(array,array + size);
  Solution s;
  cout << s.maxProfit(prices) << endl;
}
