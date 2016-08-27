#include <vector>
#include <iostream>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
  int n = nums.size();
  if(n == 0)
    return 0;
  vector<int> res = vector<int>(n);
  for(int i = 0; i < n; i ++){
    int maxLength = 1;
    for(int j = 0; j < i; j ++){
      if(nums[j] < nums[i])
        maxLength = max(maxLength, res[j] + 1);
    }
    res[i] = maxLength;
  }
  return *max_element(res.begin(), res.end());
}

int main(){
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  cout << lengthOfLIS(nums) << endl;
}
