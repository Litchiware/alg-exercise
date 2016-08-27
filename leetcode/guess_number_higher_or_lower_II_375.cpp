#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int DP(vector<vector<int>>& amount, int b, int e){
  if(b >= e)
    return 0;
  if(amount[b][e] != 0)
    return amount[b][e];
  int res = __INT_MAX__;
  for(int x = b; x <= e; x++){
    int temp = x + max(DP(amount, b, x - 1), DP(amount, x + 1, e));
    res = min(res, temp);
  }
  amount[b][e] = res;
  return res;
}

int getMoneyAmount(int n) {
  vector<vector<int>> amount(n + 1, vector<int>(n + 1)); 
  return DP(amount, 1, n);
}

int main(){
  cout << getMoneyAmount(10) << endl;
}
