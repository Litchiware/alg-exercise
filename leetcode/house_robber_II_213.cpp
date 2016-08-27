#include <vector>
#include <iostream>
using namespace std;

int subRob(const vector<int>& nums, int i, int j){
  int moneyWhenRobbable = 0, moneyWhenNotRobbable = 0, tmp;
  for(int k = i; k <=j; k++){
    tmp = moneyWhenRobbable;
    moneyWhenRobbable = max(moneyWhenRobbable, moneyWhenNotRobbable);
    moneyWhenNotRobbable = tmp + nums[k];
  }
  return max(moneyWhenRobbable, moneyWhenNotRobbable);
}

int rob(vector<int>& nums) {
  int n = nums.size();
  if(n == 1)
    return nums[0];
  return max(subRob(nums, 0, n - 2), subRob(nums, 1, n - 1));
}

int main(){
  vector<int> nums = {2, 5, 4, 6, 8, 5, 1, 4, 7};
  cout << rob(nums) << endl;
}
