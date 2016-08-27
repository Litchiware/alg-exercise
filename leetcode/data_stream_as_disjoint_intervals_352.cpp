#include <vector>
#include <sstream>
#include <iostream>
#include <set>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

string intervalToString(const Interval& i){
  string s;
  return s + "[" + to_string(i.start) + ", " + to_string(i.end) + "]";
}

string intervalsToString(const vector<Interval>& vi){
  ostringstream ss;
  ss << "[";
  bool first = true;
  for(auto i : vi){
    if(!first)
      ss << ", ";
    ss << intervalToString(i);
    first = false;
  }
  ss << "]";
  return ss.str();
}

class SummaryRanges {
public:
    /** Initialize your data structure here. */
  void addNum(int val) {
    Interval in = Interval(val, val);
    auto it = st.lower_bound(in);
    if(it != st.begin() && (--it)->end + 1 < val)
      it++;
    while(it != st.end() && val + 1 >= it->start && val - 1 <= it->end){
      in.start = min(in.start, it->start);
      in.end = max(in.end, it->end);
      it = st.erase(it);
    }
    st.insert(it, in);
  }
  vector<Interval> getIntervals() {
    vector<Interval> result;
    for(auto val : st)
      result.push_back(val);
    return result;
  }

private:
  struct Cmp{
    bool operator()(const Interval& a, const Interval& b){
      return a.start < b.start;
    }
  };
  set<Interval, Cmp> st;
};

int main(){
  SummaryRanges obj = SummaryRanges();
  vector<Interval> intervals;
  obj.addNum(1);
  intervals = obj.getIntervals();
  cout << intervalsToString(intervals) << endl;
  obj.addNum(3);
  intervals = obj.getIntervals();
  cout << intervalsToString(intervals) << endl;
  obj.addNum(7);
  intervals = obj.getIntervals();
  cout << intervalsToString(intervals) << endl;
  obj.addNum(2);
  intervals = obj.getIntervals();
  cout << intervalsToString(intervals) << endl;
  obj.addNum(6);
  intervals = obj.getIntervals();
  cout << intervalsToString(intervals) << endl;
}
