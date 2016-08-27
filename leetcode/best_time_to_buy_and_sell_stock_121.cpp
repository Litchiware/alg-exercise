#include <vector>
#include <iostream>
using namespace std;

int maxProfitRecursive(vector<int>& prices, int state) {
  if(prices.empty() || state == 2)
    return 0;
  vector<int> remaining = vector<int>(prices.begin() + 1, prices.end());
  if(state == 0)
    return max(-prices[0] + maxProfitRecursive(remaining, 1), maxProfitRecursive(remaining, 0));
  return max(prices[0] + maxProfitRecursive(remaining, 2), maxProfitRecursive(remaining, 1));
}

int maxProfit(vector<int>& prices){
  int res = 0, buyPrice = INT_MAX;
  for(int price : prices){
    if(price - buyPrice > res)
      res = price - buyPrice;
    if(price < buyPrice)
      buyPrice = price;
  }
  return res;
}

int main(){
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << maxProfit(prices) << endl;
  prices = {7, 6, 4, 3, 1};
  cout << maxProfit(prices) << endl;
}
