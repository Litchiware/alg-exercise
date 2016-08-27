#include <vector>
#include <iostream>
using namespace std;

class NumArray {
public:
  vector<int> sums;
  NumArray(vector<int> &nums) {
    sums = vector<int>(nums);
    for(int i = 1; i < nums.size(); i++){
      sums[i] = sums[i-1] + nums[i];
    }
  }
  int sumRange(int i, int j) {
    if(i == 0)
      return sums[j];
    return sums[j] - sums[i-1];
  }
};

int main(){
  vector<int> nums = {-2, 0, 3, -5, 2, -1};
  NumArray na = NumArray(nums);
  cout << na.sumRange(0, 2) << endl;
  cout << na.sumRange(2, 5) << endl;
  cout << na.sumRange(0, 5) << endl;
}
