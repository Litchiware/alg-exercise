#include <vector>
#include <iostream>
using namespace std;

int numTreesRecursive(int s, int e){
  int res = 0;
  if(s > e)
    return 1;
  for(int i = s; i <= e; i++){
    int left = numTreesRecursive(s, i-1);
    int right = numTreesRecursive(i+1, e);
    res += left * right;
  }
  return res;
}

int numTrees(int n) {
  vector<int> res = vector<int>(n+1);
  res[0] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < i; j ++){
      res[i] += res[j] * res[i-1-j];
    }
  }
  return res[n];
}

int main(){
  for(int i = 1; i <= 19; i ++)
    cout << numTrees(i) << endl;
}
