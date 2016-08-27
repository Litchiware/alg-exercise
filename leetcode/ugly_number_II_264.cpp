#include <iostream>
#include <vector>
using namespace std;

int nthUglyNumber(int n) {
  vector<int> res(n);
  res[0] = 1;
  int t1 = 0, t2 = 0, t3 = 0;
  for(int i = 1; i < n; i ++){
    res[i] = min(min(res[t1]*2, res[t2]*3), res[t3]*5);
    if(res[i] == res[t1]*2) t1++;
    if(res[i] == res[t2]*3) t2++;
    if(res[i] == res[t3]*5) t3++;
  }
  return res[n-1];
}

int main(){
  for(int i = 1; i <= 10; i ++)
    cout << i << ": " << nthUglyNumber(i) << endl;
}
