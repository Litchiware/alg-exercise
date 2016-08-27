#include <iostream>
using namespace std;

int countNumbersWithUniqueDigits(int n) {
  if(n == 0)
    return 1;
  int res = 10;
  int count = 9;
  int availableNumber = 9;
  for(int i = 2; i <= min(n, 9); i ++){
    count = count * availableNumber;
    res += count;
    availableNumber --;
  }
  return res;
}

int main(){
  cout << countNumbersWithUniqueDigits(2) << endl;
}
