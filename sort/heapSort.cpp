#include <iostream>
#include <algorithm>
#include "../utils.h"

void heapAdjust(int h[], int s, int length){
  int child = 2 * s + 1;
  while(child < length){
    if(child + 1 < length && h[child+1] > h[child])
      child ++;
    if(h[child] > h[s]){
      int temp = h[child];
      h[child] = h[s];
      h[s] = temp;
      s = child;
      child = 2 * s + 1;
    }
    else
      break;
  }
}

void heapBuild(int h[], int length){
  for(int i = (length - 1) / 2; i >= 0; i --){
    heapAdjust(h, i, length);
  }
}

void heapSort(int h[], int length){
  while(length > 1){
    heapBuild(h, length);
    int temp = h[0];
    h[0] = h[length-1];
    h[length-1] = temp;
    length --;
  }
}

int main(){
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::random_shuffle(a, a + 10);
  std::cout << "orignal: " << arrayToString(a, 10) << std::endl;
  heapSort(a, 10);
  std::cout << "sorted: " << arrayToString(a, 10) << std::endl;
}
