#include <iostream>
#include <sstream>
#include "../utils.h"
using namespace std;

ListNode* reverseList(ListNode* head){
  ListNode* pre = NULL;
  ListNode* next = NULL;
  while(head != NULL){
    next = head->next;
    head->next = pre;
    pre = head;
    head = next;
  }
  return pre;
}

bool isPalindrome(ListNode* head) {
  if(head == NULL || head->next == NULL)
    return true;
  ListNode* low = head;
  ListNode* fast = head;
  while(fast->next != NULL && fast->next->next != NULL){
    low = low->next;
    fast = fast->next->next;
  }
  ListNode* secondHalf = reverseList(low->next);
  while(secondHalf != NULL){
    if(head->val != secondHalf->val)
      return false;
    head = head->next;
    secondHalf = secondHalf->next;
  }
  return true;
}

int main(){
  ListNode* head = NULL;
  int vals[] = {6, 5, 4, 3, 4, 5, 6};
  for(int val : vals){
    ListNode* newHead = new ListNode(val*val);
    newHead->next = head;
    head = newHead;
  }
  cout << listToString(head) << endl;
  cout << isPalindrome(head) << endl;
}
