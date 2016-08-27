#include <vector>
#include <iostream>
using namespace std;

int longestIncreasingPathRecursive(vector<vector<int>>& matrix, vector<vector<int>>& length, int i, int j){
  int left = 1, right = 1, top = 1, bottom = 1;
  if(length[i][j] != 0)
    return length[i][j];
  if(i > 0 && matrix[i-1][j] > matrix[i][j])
    left += longestIncreasingPathRecursive(matrix, length, i - 1, j);
  if(i + 1 < matrix.size() && matrix[i+1][j] > matrix[i][j])
    right += longestIncreasingPathRecursive(matrix, length, i + 1, j);
  if(j > 0 && matrix[i][j-1] > matrix[i][j])
    top += longestIncreasingPathRecursive(matrix, length, i, j - 1);
  if(j + 1 < matrix[0].size() && matrix[i][j+1] > matrix[i][j])
    bottom += longestIncreasingPathRecursive(matrix, length, i, j + 1);
  length[i][j] = max(max(max(left, right), top), bottom);
  return length[i][j];
}

int matrixMax(vector<vector<int>>& matrix){
  vector<int> maxVals(matrix.size());
  for(int i = 0; i < maxVals.size(); i++){
    maxVals[i] = *max_element(matrix[i].begin(), matrix[i].end());
  }
  return *max_element(maxVals.begin(), maxVals.end());
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
  if(matrix.size() == 0 || matrix[0].size() == 0)
    return 0;
  vector<vector<int>> length(matrix.size(), vector<int>(matrix[0].size(), 0));
  for(int i = 0; i < matrix.size(); i++)
    for(int j = 0; j < matrix[0].size(); j++)
      if(length[i][j] == 0)
        longestIncreasingPathRecursive(matrix, length, i, j);
  return matrixMax(length);
}

int main(){
  vector<vector<int>> nums = {
    vector<int>{3, 4, 5},
    vector<int>{3, 2, 6},
    vector<int>{2, 2, 1}
  };
  cout << longestIncreasingPath(nums) << endl;
}
