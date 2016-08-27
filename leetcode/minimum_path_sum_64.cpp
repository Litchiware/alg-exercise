#include <vector>
#include <iostream>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<int>> res = vector<vector<int>>(m, vector<int>(n));
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(i > 0 && j > 0)
        res[i][j] = min(res[i-1][j], res[i][j-1]) + grid[i][j];
      else if(i > 0)
        res[i][j] = res[i-1][j] + grid[i][j];
      else if(j > 0)
        res[i][j] = res[i][j-1] + grid[i][j];
      else
        res[i][j] = grid[i][j];
    }
  }
  return res[m-1][n-1];
}

int main(){
  vector<vector<int>> grid = {
    {5, 3, 4},
    {2, 1, 3},
    {6, 3, 5}
  };
  cout << minPathSum(grid) << endl;
  grid = {
    {1, 2},
    {1, 1}
  };
  cout << minPathSum(grid) << endl;
}
