#include "../utils.h"
#include <iostream>
using namespace std;

bool hasCycle(ListNode *head) {
  ListNode* walker = head;
  ListNode* runner = head;
  while(runner != NULL && walker->next != NULL && runner->next != NULL && runner->next->next != NULL){
    walker = walker->next;
    runner = runner->next->next;
    if(walker == runner || runner->next == walker)
      return true;
  }
  return false;
}

int main(){
  ListNode* head = NULL;
  cout << hasCycle(head) << endl;
  head = new ListNode(1);
  cout << hasCycle(head) << endl;
}
