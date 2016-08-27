#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include "../utils.h"
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> result;    
  sort(nums.begin(), nums.end());
  int n = nums.size();
  set<int> visited;
  for(int i = 0; i < n - 2; i++)
    if(visited.find(nums[i]) == visited.end()){
      map<int, bool> targets;
      int twoSum = -nums[i];
      for(int j = i + 1; j < n; j++){
        if(targets.find(nums[j]) == targets.end())
          targets[twoSum - nums[j]] = true;
        else if(targets[nums[j]]){
          result.insert(result.end(), vector<int>{nums[i], nums[j], twoSum - nums[j]});
          targets[nums[j]] = false;
        }
      }
      visited.insert(nums[i]);
    }
  return result;
}

int main(){
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  cout << vectorToString(nums) << endl;
  vector<vector<int>> triplets = threeSum(nums);
  cout << vectorVectorToString(triplets) << endl;
}
