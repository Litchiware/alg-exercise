#include <vector>
#include <iostream>
#include "../utils.h"
using namespace std;

int maxProduct(vector<int>& nums) {
  int n = nums.size();
  vector<int> positive(n+1), negative(n+1);
  positive[0] = 1, negative[0] = 1;
  int res = INT_MIN;
  for(int i = 1; i <= n; i ++){
    if(nums[i-1] > 0){
      positive[i] = max(positive[i-1] * nums[i-1], nums[i-1]);
      negative[i] = min(negative[i-1] * nums[i-1], nums[i-1]);
    }
    else{
      positive[i] = max(negative[i-1] * nums[i-1], nums[i-1]);
      negative[i] = min(positive[i-1] * nums[i-1], nums[i-1]);
    }
    if(positive[i] > res){
      res = positive[i];
    }
  }
  return res;
}

int main(){
  vector<int> nums = {2,3,-2,4};
  cout << maxProduct(nums) << endl;
  nums = {-2, 3, -4};
  cout << maxProduct(nums) << endl;
}
