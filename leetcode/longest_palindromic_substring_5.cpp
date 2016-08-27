#include <iostream>
using namespace std;

string longestPalindrome1(string s) {
  int n = s.size();
  bool isPalindrome[n][n];
  int maxLen = 0;
  string subStr;
  for(int l = 0; l < n; l++){
    for(int i = 0; i < n-l; i++){
      int j = i + l;
      isPalindrome[i][j] = s[i] == s[j] && (j - i <= 2 || isPalindrome[i+1][j-1]);
      if(isPalindrome[i][j] && j - i + 1 > maxLen){
        maxLen = j - i + 1;
        subStr = s.substr(i, maxLen);
      }
    }
  }
  return subStr;
}

string helper(const string& s, int i, int j){
  while(i >= 0 && j < s.size() && s[i] == s[j]){
    i --;
    j ++;
  }
  return s.substr(i+1, j-1-i);
}

string longestPalindrome2(string s){
  int n = s.size();
  string subStr;
  for(int i = 0; i < n; i ++){
    string tmp = helper(s, i, i);
    if(tmp.size() > subStr.size())
      subStr = tmp;
    tmp = helper(s, i, i + 1);
    if(tmp.size() > subStr.size())
      subStr = tmp;
  }
  return subStr;
}

int main(){
  string s = "babcbabcbaccba";
  cout << longestPalindrome1(s) << endl;
  cout << longestPalindrome2(s) << endl;
}
