#include <vector>
#include <iostream>
#include "../utils.h"
using namespace std;

vector<int> countBits(int num) {
  vector<int> v(num + 1);
  v[0] = 0;
  int max = 0;
  int idx = 0;
  for(int i = 1; i <= num; i++){
    v[i] = 1 + v[idx];
    if(v[i] > max){
      max = v[i];
      idx = 0;
      continue;
    }
    idx ++;
  }
  return v;
}

int main(){
  vector<int> nBits = countBits(20);
  cout << vectorToString(nBits) << endl;
}
