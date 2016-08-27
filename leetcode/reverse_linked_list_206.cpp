#include <vector>
#include <iostream>
#include "../utils.h"

ListNode* reverseList(ListNode* head) {
  ListNode* reversed = NULL;
  ListNode* tmp = NULL;
  while(head){
    tmp = head->next;
    head->next = reversed;
    reversed = head;
    head = tmp;
  }
  return reversed;
}

int main(){
  vector<int> nums = {1, 2, 3};
  ListNode* head = makeList(nums);
  cout << listToString(head) << " :" << listToString(reverseList(head)) << endl;
}
