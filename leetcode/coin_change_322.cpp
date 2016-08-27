#include <vector>
#include <iostream>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
  vector<int> res(amount+1, INT_MAX);
  res[0] = 0;
  for(int i = 1; i <= amount; i ++){
    for(int coin : coins){
      if(i >= coin && res[i-coin] != INT_MAX)
        res[i] = min(res[i], res[i-coin] + 1);
    }
  }
  return res[amount] == INT_MAX ? -1 : res[amount];
}

int main(){
  vector<int> coins = {1, 2, 5};
  cout << coinChange(coins, 11) << endl;
  coins = {2};
  cout << coinChange(coins, 3) << endl;
}
