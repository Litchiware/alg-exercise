#include <vector>
#include "../treeUtils.h"
#include "../utils.h"
#include <iostream>
using namespace std;

vector<int> pathSumRecursive(TreeNode* root, int sum, vector<vector<int>>& pathes) {
  if(root == NULL)
    return vector<int>();
  if(root->left == NULL && root->right == NULL){
    if(root->val == sum){
      pathes.push_back(vector<int>(1, root->val));
      return vector<int>(1, pathes.size() - 1);
    }
    return vector<int>();
  }
  if(root->left == NULL and root->right != NULL){
    vector<int> inds = pathSumRecursive(root->right, sum - root->val, pathes);
    int sz = inds.size();
    for(int j = 0; j < sz; j++){
      pathes[inds[j]].insert(pathes[inds[j]].begin(), root->val);
    }
    return inds;
  }
  if(root->left != NULL and root->right == NULL){
    vector<int> inds = pathSumRecursive(root->left, sum - root->val, pathes);
    int sz = inds.size();
    for(int j = 0; j < sz; j++){
      pathes[inds[j]].insert(pathes[inds[j]].begin(), root->val);
    }
    return inds;
  }
  vector<int> leftInds = pathSumRecursive(root->left, sum - root->val, pathes);
  int sz = leftInds.size();
  for(int j = 0; j < sz; j++)
    pathes[leftInds[j]].insert(pathes[leftInds[j]].begin(), root->val);

  vector<int> rightInds = pathSumRecursive(root->right, sum - root->val, pathes);
  sz = rightInds.size();
  for(int j = 0; j < sz; j++)
    pathes[rightInds[j]].insert(pathes[rightInds[j]].begin(), root->val);
  leftInds.insert(leftInds.end(), rightInds.begin(), rightInds.end());
  return leftInds;
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
  vector<vector<int>> pathes;
  pathSumRecursive(root, sum, pathes);
  return pathes;
}

int main(){
  TreeNode* root = new TreeNode(7);
  root->left = new TreeNode(8);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->right->right = new TreeNode(4);
  print_t(root);
  vector<vector<int>> pathes = pathSum(root, 20);
  cout << vectorVectorToString(pathes) << endl;
}
