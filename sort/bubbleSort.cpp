#include <iostream>
#include <algorithm>
#include "../utils.h"

void bubbleSort(int a[], int n){
  for(int i = 0; i < n - 1; i ++){
    for(int j = 0; j < n - 1 - i; j ++){
      if(a[j] > a[j+1]){
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}

void bubbleSort1(int a[], int n){
  int i = n - 1;
  while(i > 0){
    int pos = 0;
    for(int j = 0; j < i; j ++){
      if(a[j] > a[j+1]){
        pos = j;
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
    i = pos;
  }
}

void bubbleSort2(int a[], int n){
  int low = 0;
  int high = n - 1;
  while(low < high){
    for(int i = low; i < high; i ++){
      if(a[i] > a[i+1]){
        int temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
      }
    }
    high --;
    for(int i = high; i > low; i --){
      if(a[i] < a[i-1]){
        int temp = a[i];
        a[i] = a[i-1];
        a[i-1] = temp;
      }
    }
    low ++;
  }
}

int main(){
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::random_shuffle(a, a + 10);
  std::cout << "orignal: " << arrayToString(a, 10) << std::endl;
  bubbleSort2(a, 10);
  std::cout << "sorted: " << arrayToString(a, 10) << std::endl;
}
