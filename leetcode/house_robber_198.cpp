#include <vector>
#include <iostream>
using namespace std;

int rob(vector<int>& nums) {
  int moneyWhenRobbable = 0, moneyWhenNotRobbable = 0, tmp;
  for(int num : nums){
    tmp = moneyWhenRobbable;
    moneyWhenRobbable = max(moneyWhenRobbable, moneyWhenNotRobbable);
    moneyWhenNotRobbable = tmp + num;
  }
  return max(moneyWhenRobbable, moneyWhenNotRobbable);
}

int main(){
  vector<int> nums = {2, 5, 4, 6, 8, 5, 1, 4, 7};
  cout << rob(nums) << endl;
}
