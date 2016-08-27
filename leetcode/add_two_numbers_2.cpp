#include <vector>
#include <iostream>
#include "../utils.h"
using namespace std;

ListNode* addTwoNumbersRecursive(ListNode* l1, ListNode* l2, int carry) {
  if(l1 == NULL && l2 == NULL && !carry)
    return NULL;
  ListNode* node = new ListNode(carry);
  if(l1){
    node->val += l1->val;
    l1 = l1->next;
  }
  if(l2){
    node->val += l2->val;
    l2 = l2->next;
  }
  carry = node->val / 10;
  node->val = node->val % 10;
  node->next = addTwoNumbersRecursive(l1, l2, carry);
  return node;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
  return addTwoNumbersRecursive(l1, l2, 0);
}

int main(){
  vector<int> num1 = {2, 4, 3};
  ListNode* l1 = makeList(num1);
  vector<int> num2 = {5, 6, 4};
  ListNode* l2 = makeList(num2);
  cout << listToString(addTwoNumbers(l1, l2)) << endl;;
}
