#include <vector>
#include <iostream>
#include "../treeUtils.h"
using namespace std;

TreeNode* sortedArrayToBST(vector<int>& nums) {
  int sz = nums.size();
  if(sz == 0)
    return NULL;
  int mid = sz / 2;
  TreeNode* root = new TreeNode(nums[mid]);
  if(mid > 0){
    vector<int> leftHalf(nums.begin(), nums.begin() + mid);
    root->left = sortedArrayToBST(leftHalf);
  }
  if(mid + 1 < sz){
    vector<int> rightHalf(nums.begin() + mid + 1, nums.end());
    root->right = sortedArrayToBST(rightHalf);
  }
  return root;
}

int main(){
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  TreeNode* root = sortedArrayToBST(vec);
  print_t(root);
}
