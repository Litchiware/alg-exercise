#include <iostream>
using namespace std;

bool isMatch(string s, string p) {
  int m = s.size(), n = p.size();
  if(n == 0)
    return m == 0;
  if(n == 1)
    return m == 1 && (p[0] == '.' || p[0] == s[0]);
  if(p[1] != '*')
    return m >= 1 && (p[0] == '.' || p[0] == s[0]) && isMatch(s.substr(1), p.substr(1));
  if(m == 0)
    return isMatch(s, p.substr(2));
  return isMatch(s, p.substr(2)) || ((p[0] == '.' || p[0] == s[0]) && isMatch(s.substr(1), p));
}

int main(){
  cout << isMatch("aa", "a") << endl;
  cout << isMatch("aa", "aa") << endl;
  cout << isMatch("aaa", "aa") << endl;
  cout << isMatch("aa", "a*") << endl;
  cout << isMatch("aa", ".*") << endl;
  cout << isMatch("ab", ".*") << endl;
  cout << isMatch("aab", "c*a*b") << endl;
  cout << isMatch("ab", ".*c") << endl;
  cout << isMatch("a", "ab*") << endl;
  cout << isMatch("", "c*c*") << endl;
}
