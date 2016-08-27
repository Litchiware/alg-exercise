#include <iostream>
#include <vector>
using namespace std;

int numSquares(int n) {
  vector<int> res(n+1, INT_MAX);
  res[0] = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j * j <= i; j ++){
      res[i] = min(res[i], 1 + res[i-j*j]);
    }
  }
  return res[n];
}

int main(){
  cout << 50 << ": " << numSquares(50) << endl;
  cout << 9732 << ": " << numSquares(9732) << endl;
}
