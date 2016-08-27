#include <vector>
#include <iostream>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
  int m = matrix.size();
  if(m == 0)
    return 0;
  int n = matrix[0].size();
  if(n == 0)
    return 0;
  vector<vector<int>> maxLen(m, vector<int>(n));    
  int res = 0;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(matrix[i][j] == '1'){
        if(i > 0 && j > 0)
          maxLen[i][j] = min(maxLen[i-1][j], min(maxLen[i][j-1], maxLen[i-1][j-1])) + 1;
        else
          maxLen[i][j] = 1;
        res = max(res, maxLen[i][j]);
      }
    }
  }
  return res * res;
}

int main(){
  vector<vector<char>> matrix = {
    {'1', '0', '1', '0', '0'},
    {'1', '0', '1', '1', '1'},
    {'1', '1', '1', '1', '1'},
    {'1', '0', '0', '1', '0'}
  };
  cout << maximalSquare(matrix) << endl;
}
