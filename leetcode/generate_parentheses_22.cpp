#include <vector>
#include <iostream>
#include "../utils.h"
using namespace std;

void validParenthesis(int left, int right, int sum, string& s, vector<string>& res){
  if(left == sum && right == sum){
    res.push_back(string(s));
    return;
  }
  if(left < sum){
    s.push_back('(');
    validParenthesis(left + 1, right, sum, s, res);
    s.pop_back();
  }
  if(left <= sum && right < left){
    s.push_back(')');
    validParenthesis(left, right + 1, sum, s, res);
    s.pop_back();
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> res;   
  string s;
  validParenthesis(0, 0, n, s, res);
  return res;
}

int main(){
  vector<string> res = generateParenthesis(3);
  cout << vectorToString(res) << endl;
}
