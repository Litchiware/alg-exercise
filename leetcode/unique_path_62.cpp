#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n){
  long res = 1;
  for(int i = 0; i < min(m - 1, n - 1); i ++){
    res = res * (m + n - 2 -i) / (i + 1);
  }
  return (int)res;
}

int main(){
  cout << "(" << 3 << ", " << 3 << "): " << uniquePaths(3, 3) << endl;
}
