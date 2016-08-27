#include <vector>
#include <iostream>
#include <queue>
#include "../utils.h"
using namespace std;

struct Compare{
  bool operator()(ListNode* l1, ListNode* l2){
    return l1->val > l2->val;
  }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists){
  priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
  for(ListNode* list : lists)
    if(list)
      pq.push(list);
  ListNode* head = new ListNode(0);
  ListNode* curr = head;
  while(!pq.empty()){
    curr->next = pq.top();
    curr = curr->next;
    pq.pop();
    if(curr->next)
      pq.push(curr->next);
  }
  curr->next = NULL;
  return head->next;
}

int main(){
  vector<ListNode*> lists = {
    makeList({2, 5, 7}),
    makeList({1, 4, 8, 9})
  };
  cout << listToString(lists[0]) << endl;
  cout << listToString(lists[1]) << endl;
  cout << listToString(mergeKLists(lists)) << endl;
}
