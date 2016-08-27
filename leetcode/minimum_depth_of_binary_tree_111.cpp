#include "../treeUtils.h"
#include <iostream>
using namespace std;

int minDepth(TreeNode* root) {
  if(root == NULL)
    return 0;
  if(root->left == NULL && root->right != NULL)
    return minDepth(root->right) + 1;
  if(root->right == NULL && root->left != NULL)
    return minDepth(root->left) + 1;
  int leftDepth = minDepth(root->left) + 1;
  int rightDepth = minDepth(root->right) + 1;
  return leftDepth < rightDepth ? leftDepth : rightDepth;
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
  cout << minDepth(root) << endl;
}
