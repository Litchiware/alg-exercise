#include <vector>
#include <queue>
#include <iostream>
#include "../treeUtils.h"
#include "../utils.h"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
  queue<TreeNode*> q;
  vector<vector<int>> res;
  int nCurrentLevel = 0, nNextLevel = 0;
  if(root){
    q.push(root);
    nCurrentLevel += 1;
  }
  while(nCurrentLevel){
    res.push_back(vector<int>());
    while(nCurrentLevel){
      TreeNode* node = q.front();
      q.pop();
      nCurrentLevel -= 1;
      res.back().push_back(node->val);
      if(node->left){
        q.push(node->left);
        nNextLevel += 1;
      }
      if(node->right){
        q.push(node->right);
        nNextLevel += 1;
      }
    }
    if(!nCurrentLevel)
      swap(nCurrentLevel, nNextLevel);
  }
  return res;
}

int main(){
  TreeNode* tree = new TreeNode(3);
  tree->left = new TreeNode(9);
  tree->right = new TreeNode(20);
  tree->right->left = new TreeNode(15);
  tree->right->right = new TreeNode(7);
  vector<vector<int>> res = levelOrder(tree);
  cout << vectorVectorToString(res) << endl;
}
