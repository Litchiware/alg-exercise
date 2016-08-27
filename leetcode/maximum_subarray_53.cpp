#include <vector>
#include <iostream>
using namespace std;

int maxSubArray(vector<int>& nums) {
  int n = nums.size();
  vector<int> res(n+1);
  int maxSum = INT_MIN;
  for(int i = 1; i <= n; i++){
    res[i] = res[i-1] > 0 ? res[i-1] + nums[i-1] : nums[i-1];
    if(res[i] > maxSum)
      maxSum = res[i];
  }
  return maxSum;
}

int main(){
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  cout << maxSubArray(nums) << endl;
}
