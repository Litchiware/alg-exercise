#include <iostream>
#include "../utils.h"
using namespace std;

ListNode* insertionSortList(ListNode* head) {
  if(head == NULL)
    return head;
  ListNode* prev = head;
  ListNode* curr = head->next;
  while(curr){
    if(curr->val < head->val){
      prev->next = curr->next;
      curr->next = head;
      head = curr;
      curr = prev->next;
      continue;
    }
    else{
      ListNode* p = head;
      while(p->next != curr && p->next->val <= curr->val) p = p->next;
      if(p->next != curr){
        prev->next = curr->next;
        curr->next = p->next;
        p->next = curr;
        curr = prev->next;
        continue;
      }
    }
    prev = prev->next;
    curr = curr->next;
  }
  return head;
}

int main(){
  ListNode* head = makeList(vector<int>{10, 8, 3});
  cout << listToString(head) << endl;
  head = insertionSortList(head);
  cout << listToString(head) << endl;
  head = makeList(vector<int>{2, 1});
  cout << listToString(head) << endl;
  head = insertionSortList(head);
  cout << listToString(head) << endl;
}
