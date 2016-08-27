#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
  vector<int> products;
  Solution(){
    products = vector<int>(59);
  }

  int integerBreak(int n) {
    if(n == 2)
      return 1;
    if(products[n] != 0)
      return products[n];
    int res = INT_MIN;
    for(int i = 1; i <= n / 2; i ++){
      res = max(res, i * max(integerBreak(n - i), n - i));
    }
    products[n] = res;
    return res;
  }
};

int main(){
  Solution sol = Solution();
  cout << sol.integerBreak(10) << endl;
}
