#include <iostream>
#include <algorithm>
#include "../utils.h"

void selectSort(int a[], int n){
  for(int i = 0; i < n; i ++){
    int min = i;
    for(int j = i + 1; j < n; j ++){
      if(a[j] < a[min])
        min = j;
    }
    int temp = a[i];
    a[i] = a[min];
    a[min] = temp;
  }
}

int main(){
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::random_shuffle(a, a + 10);
  std::cout << "orignal: " << arrayToString(a, 10) << std::endl;
  selectSort(a, 10);
  std::cout << "sorted: " << arrayToString(a, 10) << std::endl;
}
