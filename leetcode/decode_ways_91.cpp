#include <iostream>
using namespace std;

int numDecodings(string s) {
  if(s.empty()) return 0;
  char prev = '9';
  int n1 = 1, n2 = 1, num;
  for(char ch : s){
    if(ch == '0' && (prev == '1' || prev == '2')) num = n1;
    else if(prev == '1' || (prev == '2' && ch <= '6')) num = n1 + n2;
    else if(ch == '0') num = 0;
    else num = n2;
    n1 = n2, n2 = num, prev = ch;
  }
  return n2;
}

int main(){
  cout << numDecodings("") << endl;
  cout << numDecodings("0") << endl;
  cout << numDecodings("12") << endl;
}
