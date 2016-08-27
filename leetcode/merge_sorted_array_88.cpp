#include <vector>
#include <algorithm>
#include <iostream>
#include "../utils.h"
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int r1 = m - 1, r2 = n - 1, r = m + n - 1;
  while(r1 >= 0 && r2 >= 0)
    nums1[r--] = nums1[r1] > nums2[r2] ? nums1[r1--] : nums2[r2--];
  while(r1 >= 0 && r2 >= 0)
    nums1[r--] = nums1[r1] > nums2[r2] ? nums1[r1--] : nums2[r2--];
  while(r2 >= 0)
    nums1[r--] = nums2[r2--];
}

int main(){
  vector<int> v1{-1, 0, 0, 3, 3, 3, 0, 0, 0};
  vector<int> v2{1, 2, 2};
  merge(v1, 6, v2, 3);
  cout << vectorToString(v1) << endl;
  cout << vectorToString(v2) << endl;
}
