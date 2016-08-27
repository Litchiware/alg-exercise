#include <iostream>
#include <vector>
#include <sstream>
#include "../utils.h"
using namespace std;

vector<vector<int>> generateMatrix(int n){
  vector<vector<int>> result(n, vector<int>(n, 0));
  int k = 0, i = 0, j = -1;
  while(k < n * n){
    while(j + 1 < n && result[i][j+1] == 0) result[i][++j] = ++k;
    while(i + 1 < n && result[i+1][j] == 0) result[++i][j] = ++k;
    while(j - 1 >= 0 && result[i][j-1] == 0) result[i][--j] = ++k;
    while(i - 1 >= 0 && result[i-1][j] == 0) result[--i][j] = ++k;
  }
  return result;
}

int main(){
  auto result = generateMatrix(5);
  cout << vectorVectorToString(result) << endl;
}
