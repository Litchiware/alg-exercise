#include <iostream>
#include "../treeUtils.h"
using namespace std;

bool isBalancedRecursive(TreeNode* root, int& depth){
  if(root == NULL){
    return true;
  }
  int leftDepth = depth + 1;
  int rightDepth = depth + 1;
  bool leftBalanced = isBalancedRecursive(root->left, leftDepth);
  bool rightBalanced = isBalancedRecursive(root->right, rightDepth);
  depth = leftDepth > rightDepth ? leftDepth : rightDepth;
  if(leftBalanced && rightBalanced && depth - leftDepth <= 1 && depth - rightDepth <= 1)
    return true;
  return false;
}

bool isBalanced(TreeNode* root) {
  int depth = 0;
  return isBalancedRecursive(root, depth);
}

int main(){
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->right->right = new TreeNode(7);
  print_t(root);
  cout << isBalanced(root) << endl;
}
