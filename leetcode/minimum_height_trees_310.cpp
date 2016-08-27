#include <vector>
#include <set>
#include <map>
#include <iostream>
#include "../utils.h"
using namespace std;

void deleteLeaves(map<int, set<int>>& graph){
  while(graph.size() > 2){
    vector<int> leaves;
    for(auto it = graph.begin(); it != graph.end(); it ++)
      if(it->second.size() <= 1)
        leaves.push_back(it->first);
    for(int leaf : leaves){
      for(int neighbor : graph[leaf])
        graph[neighbor].erase(leaf);
      graph.erase(leaf);
    }
  }
}

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
  if(n == 1)
    return vector<int>(1);
  map<int, set<int>> graph;
  for(const pair<int, int>& e : edges){
    graph[e.first].insert(e.second);
    graph[e.second].insert(e.first);
  }
  deleteLeaves(graph);
  vector<int> result;
  for(auto it = graph.begin(); it != graph.end(); it++){
    result.push_back(it->first);
  }
  return result;
}

int main(){
  vector<pair<int, int>> edges;
  edges.push_back(pair<int, int>(1, 0));
  edges.push_back(pair<int, int>(1, 2));
  edges.push_back(pair<int, int>(1, 3));
  vector<int> result = findMinHeightTrees(4, edges);
  cout << vectorToString(result) << endl;
  edges.clear();
  edges.push_back(pair<int, int>(0, 3));
  edges.push_back(pair<int, int>(1, 3));
  edges.push_back(pair<int, int>(2, 3));
  edges.push_back(pair<int, int>(4, 3));
  edges.push_back(pair<int, int>(5, 4));
  result = findMinHeightTrees(6, edges);
  cout << vectorToString(result) << endl;
}
