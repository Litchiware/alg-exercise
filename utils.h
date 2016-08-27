#include <sstream>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* makeList(const vector<int>& vec){
  ListNode* head = NULL;
  for(int i = vec.size() - 1; i >= 0; i--){
    ListNode* newHead = new ListNode(vec[i]);
    newHead->next = head;
    head = newHead;
  }
  return head;
}

string listToString(ListNode* head){
  stringstream ss;
  bool first = true;
  while(head != NULL){
    if(!first)
      ss << "->";
    ss << head->val;
    head = head->next;
    first = false;
  }
  return ss.str();
}

template <typename T> string vectorToString(const vector<T>& vec){
  ostringstream ss;
  ss << '[';
  bool first = true;
  for (T const & element : vec) {
      if (!first) {
          ss << ", ";
      }
      ss << element;
      first = false;
  }
  ss << ']';
  return ss.str();
}

template <typename T> string vectorVectorToString(const vector<vector<T>>& vec){
  ostringstream ss;
  ss << '[';
  bool first = true;
  for (vector<T> element : vec) {
      if (!first) {
          ss << ",\n ";
      }
      ss << vectorToString(element);
      first = false;
  }
  ss << ']';
  return ss.str();
}

template <typename T> string setToString(const set<T>& s){
  ostringstream ss;
  ss << '{';
  bool first = true;
  for (T const & element : s) {
      if (!first) {
          ss << ", ";
      }
      ss << element;
      first = false;
  }
  ss << '}';
  return ss.str();
}

template <typename T1, typename T2> string mapSetToString(const map<T1, set<T2>>& mp){
  ostringstream ss;
  ss << "{";
  bool first = true;
  for(auto it = mp.begin(); it != mp.end(); it++){
    if(!first)
      ss << ",\n ";
    ss << it->first << ": " << setToString(it->second);
    first = false;
  }
  ss << "}";
  return ss.str();
}
