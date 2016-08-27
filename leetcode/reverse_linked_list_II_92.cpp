#include <vector>
#include <iostream>
#include "../utils.h"

ListNode* reverseBetween(ListNode* head, int m, int n) {
  ListNode* prev = new ListNode(0);
  prev->next = head;
  head = prev;
  for(int i = 1; i < m; i++) prev = prev->next;
  ListNode* curr = prev->next;
  ListNode* h = curr;
  ListNode* tmp;
  for(int i = m; i <= n; i++){
    tmp = curr->next;
    curr->next = prev->next;
    prev->next = curr;
    curr = tmp;
  }
  h->next = curr;
  return head->next;
}

int main(){
  vector<int> nums = {1, 2, 3, 4, 5};
  ListNode* head = makeList(nums);
  cout << listToString(head) << " :" << listToString(reverseBetween(head, 2, 4)) << endl;
  nums = {3, 5};
  head = makeList(nums);
  cout << listToString(head) << " :" << listToString(reverseBetween(head, 1, 2)) << endl;
  head = makeList(nums);
  cout << listToString(head) << " :" << listToString(reverseBetween(head, 2, 2)) << endl;
}
