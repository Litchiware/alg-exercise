#include <iostream>
using namespace std;

struct TreeLinkNode{
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
  if(!root || !root->left)
    return;
  if(root->right)
    root->left->next = root->right;
  if(root->next && root->next->left)
    root->right->next = root->next->left;
  connect(root->left);
  connect(root->right);
}

int main(){
  TreeLinkNode* root = new TreeLinkNode(1);
  root->left = new TreeLinkNode(2);
  root->right = new TreeLinkNode(3);
  root->left->left = new TreeLinkNode(4);
  root->left->right = new TreeLinkNode(5);
  root->right->left = new TreeLinkNode(6);
  root->right->right = new TreeLinkNode(7);
  connect(root);
  cout << root->val << endl;
  cout << root->left->val << " " << root->left->next->val << endl;
  cout << root->left->left->val << " " << root->left->left->next->val << " " << root->left->left->next->next->val << " " << root->left->left->next->next->next->val << endl;
}
