#include <vector>
#include <iostream>
using namespace std;

int combinationSum4(vector<int>& nums, int target){
  vector<int> res(target + 1);
  for(int i = 1; i <= target; i ++){
    for(int num : nums){
      if(num > i)
        continue;
      if(num == i)
        res[i] += 1;
      else
        res[i] += res[i-num];
    }
  }
  return res[target];
}

int main(){
  vector<int> nums = {1, 2, 3};
  int target = 4;
  cout << combinationSum4(nums, target) << endl;
}
