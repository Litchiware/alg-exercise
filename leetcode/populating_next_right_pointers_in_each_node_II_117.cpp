#include <iostream>
using namespace std;

struct TreeLinkNode{
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode* root){
  while(root && !root->left && !root->right)
    root = root->next;
  if(!root)
    return;
  TreeLinkNode* first;
  if(root->left)
    first = root->left;
  else
    first = root->right;
  TreeLinkNode* curr = first;
  while(curr){
    while(root && (!root->left || root->left == curr) && (!root->right || root->right == curr))
      root = root->next;
    if(!root){
      connect(first);
      return;
    }
    if(root->left && root->left != curr)
      curr->next = root->left;
    else{
      curr->next = root->right;
      root = root->next;
    }
    curr = curr->next;
  }
}

int main(){
  TreeLinkNode* root = new TreeLinkNode(1);
  root->left = new TreeLinkNode(2);
  root->right = new TreeLinkNode(3);
  root->left->left = new TreeLinkNode(4);
  root->left->right = new TreeLinkNode(5);
  root->right->left = new TreeLinkNode(6);
  root->right->right = new TreeLinkNode(7);
  root->left->right->left = new TreeLinkNode(8);
  root->right->right->right = new TreeLinkNode(9);
  connect(root);
  cout << root->val << endl;
  cout << root->left->val << " " << root->left->next->val << endl;
  cout << root->left->left->val << " " << root->left->left->next->val << " " << root->left->left->next->next->val << " " << root->left->left->next->next->next->val << endl;
  cout << root->left->right->left->val << " " << root->left->right->left->next->val << endl;
}
