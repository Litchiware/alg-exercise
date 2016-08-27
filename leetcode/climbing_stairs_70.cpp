#include <iostream>
using namespace std;

int climbStairs(int n) {
  int nWays1 = 1, nWays2 = 1, tmp;
  for(int i = 2; i <= n; i++){
    tmp = nWays1;
    nWays1 = nWays2;
    nWays2 = tmp + nWays2;
  }
  return nWays2;
}

int main(){
  for(int i = 0; i < 5; i ++){
    cout << i << ": " << climbStairs(i) << endl;
  }
}
