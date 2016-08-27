#include <vector>
#include <iostream>
#include <map>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices){
  int maxProfitsWhenBuyOrCooldown = 0;
  int maxProfitsWhenSellOrCooldown = 0;
  int maxProfitsWhenMustCooldown = 0;
  int tmp;
  for(int i = prices.size()-1; i >= 0; i --){
    tmp = maxProfitsWhenBuyOrCooldown;
    maxProfitsWhenBuyOrCooldown = max(-prices[i] + maxProfitsWhenSellOrCooldown, maxProfitsWhenBuyOrCooldown);
    maxProfitsWhenSellOrCooldown = max(prices[i] + maxProfitsWhenMustCooldown, maxProfitsWhenSellOrCooldown);
    maxProfitsWhenMustCooldown = tmp;
  }
  return maxProfitsWhenBuyOrCooldown;
}

int main(){
  vector<int> prices = {1, 2, 4};
  cout << maxProfit(prices) << endl;
  prices = {1, 2, 3, 0, 2};
  cout << maxProfit(prices) << endl;
  prices = {48, 12, 60, 93, 97, 42, 25, 64, 17, 56, 85, 93, 9, 48, 52, 42, 58, 85, 81, 84, 69, 36, 1, 54, 23, 15, 72, 15, 11, 94};
  cout << maxProfit(prices) << endl;
  prices = {};
  cout << maxProfit(prices) << endl;
}
