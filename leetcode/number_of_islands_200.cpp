#include <vector>
#include <iostream>
using namespace std;

void DFS(vector<vector<char>>& grid, int i, int j){
  grid[i][j] = '0';
  if(i > 0 && grid[i-1][j] != '0')
    DFS(grid, i - 1, j);
  if(i + 1 < grid.size() && grid[i+1][j] != '0')
    DFS(grid, i + 1, j);
  if(j > 0 && grid[i][j-1] != '0')
    DFS(grid, i, j - 1);
  if(j + 1 < grid[0].size() && grid[i][j+1] != '0')
    DFS(grid, i, j + 1);
}

int numIslands(vector<vector<char>>& grid) {
  int num = 0;
  for(int i = 0; i < grid.size(); i++)
    for(int j = 0; j < grid[0].size(); j++){
      if(grid[i][j] == '1'){
        num++;
        DFS(grid, i, j);
      }
    }
  return num;
}

int main(){
  vector<vector<char>> grid;
  grid.push_back(vector<char>{'1', '1', '0', '0', '0'});
  grid.push_back(vector<char>{'1', '1', '0', '0', '0'});
  grid.push_back(vector<char>{'0', '0', '1', '0', '0'});
  grid.push_back(vector<char>{'0', '0', '0', '1', '1'});
  cout << numIslands(grid) << endl;
}
