#include <vector>
#include <iostream>
#include "../utils.h"
using namespace std;

class NumMatrix {
public:
  vector<vector<int>> sums;
  NumMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size();
    if(m > 0){
      int n = matrix[0].size();
      sums = vector<vector<int>>(m + 1, vector<int>(n + 1));
      for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
          sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + matrix[i-1][j-1];
        }
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if(sums.size() <= 1 || sums[0].size() <=1)
      return 0;
    return sums[row2+1][col2+1] - sums[row1][col2+1] - sums[row2+1][col1] + sums[row1][col1];
  }
};

int main(){
  vector<vector<int>> nums = {
    {3, 0, 1, 4, 2},
    {5, 6, 3, 2, 1},
    {1, 2, 0, 1, 5},
    {4, 1, 0, 1, 7},
    {1, 0, 3, 0, 5}
  };
  NumMatrix matrix = NumMatrix(nums);
  cout << matrix.sumRegion(2, 1, 4, 3) << endl;
  cout << matrix.sumRegion(1, 1, 2, 2) << endl;
  cout << matrix.sumRegion(1, 2, 2, 4) << endl;
}
