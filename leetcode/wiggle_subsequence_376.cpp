#include <vector>
#include <iostream>
using namespace std;

int wiggleMaxLength(vector<int>& nums){
  int n = nums.size();
  if(n <= 1)
    return n;
  vector<int> res(nums.size());
  res[0] = 1;
  int p = 0, q = 0;
  for(int i = 1; i < n; i ++){
    int t = q;
    if(nums[i] > nums[p]){
      res[i] = res[p] + 1;
      q = i;
    }
    if(nums[i] < nums[t] && res[i] < res[t] + 1){
      res[i] = res[t] + 1;
      p = i;
      q = t;
    }
  }
  return max(res[p], res[q]);
}

int main(){
  vector<int> input = {1,7,4,9,2,5};
  cout << wiggleMaxLength(input) << endl;
  input = {1,17,5,10,13,15,10,5,16,8};
  cout << wiggleMaxLength(input) << endl;
  input = {1,2,3,4,5,6,7,8,9};
  cout << wiggleMaxLength(input) << endl;
}
