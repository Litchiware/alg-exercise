#include <vector>
#include <iostream>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int m = obstacleGrid.size(), n = obstacleGrid[0].size();
  vector<vector<int>> res = vector<vector<int>>(m, vector<int>(n));
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(!obstacleGrid[i][j]){
        if(i > 0 && j > 0)
          res[i][j] = res[i-1][j] + res[i][j-1];
        else if(i > 0)
          res[i][j] = res[i-1][j];
        else if(j > 0)
          res[i][j] = res[i][j-1];
        else
          res[i][j] = 1;
      }
    }
  }
  return res[m-1][n-1];
}

int main(){
  vector<vector<int>> obstacleGrid = {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
  };
  cout << uniquePathsWithObstacles(obstacleGrid) << endl;
  obstacleGrid = {{1}};
  cout << uniquePathsWithObstacles(obstacleGrid) << endl;
}
