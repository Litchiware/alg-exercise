#include <vector>
#include <set>
#include <iostream>
using namespace std;

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
  int m = matrix.size();
  if(m == 0)
    return 0;
  int n = matrix[0].size();
  vector<vector<int>> areas(m, vector<int>(n));
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      areas[i][j] = matrix[i][j];
      if(i > 0)
        areas[i][j] += areas[i-1][j];
      if(j > 0)
        areas[i][j] += areas[i][j-1];
      if(i > 0 && j > 0)
        areas[i][j] -= areas[i-1][j-1];
    }
  }
  int maxArea = INT_MIN;
  for(int c1 = 0; c1 < n; c1++){
    for(int c2 = c1; c2 < n; c2++){
      set<int> areaSet;
      areaSet.insert(0);
      for(int r = 0; r < m; r++){
        int area = areas[r][c2];
        if(c1 > 0)
          area -= areas[r][c1-1];
        auto it = areaSet.lower_bound(area - k);
        if(it != areaSet.end() && area - *it > maxArea)
          maxArea = area - *it;
        areaSet.insert(area);
      }
    }
  }
  return maxArea;
}

int main(){
  vector<vector<int>> matrix = {
    {1,  0, 1},
    {0, -2, 3}
  };
  cout << maxSumSubmatrix(matrix, 2) << endl;
  matrix = {
    {2, 2, -1}
  };
  cout << maxSumSubmatrix(matrix, 3) << endl;
}
