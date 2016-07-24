#include <iostream>
#include <algorithm>
#include "../utils.h"

void insertSort(int a[], int n){
  for(int i = 1; i < n; i ++){
    if(a[i] < a[i-1]){
      int j = i - 1;
      int x = a[i];
      while(x < a[j]){
        a[j+1] = a[j];
        j--;
      }
      a[j+1] = x;
    }
  }
}

int main(){
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::random_shuffle(a, a + 10);
  std::cout << "original: " << arrayToString(a, 10) << std::endl;
  insertSort(a, 10);
  std::cout << "sorted: " << arrayToString(a, 10) << std::endl;
  return 0;
}
