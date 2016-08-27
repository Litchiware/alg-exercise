#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
  if(numRows == 1) return s;
  vector<string> strs(numRows);
  int i = 0, offset = 1;
  for(char ch : s){
    strs[i].push_back(ch);
    if(i + offset == numRows || i + offset == -1)
      offset = -offset;
    i += offset;
  }
  string res;
  for(string& str : strs)
    res += str;
  return res;
}

int main(){
  cout << convert("", 1) << endl;
  cout << convert("PAYPALISHIRING", 3) << endl;
  cout << convert("ABC", 2) << endl;
  cout << convert("ABCD", 2) << endl;
  cout << convert("ABCDE", 4) << endl;
  cout << convert("ABCDEF", 4) << endl;
}
