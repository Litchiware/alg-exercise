#include <vector>
#include <iostream>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
  vector<int> minSums = triangle.back();
  int n = triangle.size();
  for(int i = n-1; i >= 1; i--){
    for(int j = 0; j < i; j++){
      minSums[j] = min(minSums[j], minSums[j+1]) + triangle[i-1][j];
    }
  }
  return minSums.front();
}

int main(){
  vector<vector<int>> triangle = {
    {2},
    {3, 4},
    {6, 5, 7},
    {4, 1, 8, 3}
  };
  cout << minimumTotal(triangle) << endl;
}
