#include <vector>
#include <iostream>
#include "../treeUtils.h"
using namespace std;

TreeNode* clone(TreeNode* tree){
  if(tree == NULL)
    return NULL;
  TreeNode* newTree = new TreeNode(tree->val);
  newTree->left = clone(tree->left);
  newTree->right = clone(tree->right);
  return newTree;
}

vector<TreeNode*> bstree(int s, int e){
  vector<TreeNode*> res;
  for(int i = s; i <= e; i++){
    vector<TreeNode*> leftTrees;
    vector<TreeNode*> rightTrees;
    if(i > s && i < e){
      leftTrees = bstree(s, i-1);
      rightTrees = bstree(i+1, e);
    }
    else if(i > s && i == e){
      leftTrees = bstree(s, i-1);
      rightTrees = {NULL};
    }
    else if(i == s && i < e){
      leftTrees = {NULL};
      rightTrees = bstree(i+1, e);
    }
    else{
      leftTrees = {NULL};
      rightTrees = {NULL};
    }
    for(auto leftTree : leftTrees){
      for(auto rightTree : rightTrees){
        TreeNode* tree = new TreeNode(i);
        tree->left = clone(leftTree);
        tree->right = clone(rightTree);
        res.push_back(tree);
      }
    }
  }
  return res;
}

vector<TreeNode*> generateTrees(int n) {
  return bstree(1, n);
}

int main(){
  for(auto tree : generateTrees(3))
    print_t(tree);
}
