#include <iostream>
#include <algorithm>
#include "../utils.h"

void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int a[], int low, int high){
  int pivotKey = a[low];
  while(low < high){
    while(low < high && a[high] >= pivotKey)
      high --;
    swap(a + low, a + high);
    while(low < high && a[low] <= pivotKey)
      low ++;
    swap(a + low, a + high);
  }
  return low;
}

void quickSortRecursive(int a[], int low, int high){
  if(low < high){
    int pivotLoc = partition(a, low, high);
    quickSortRecursive(a, low, pivotLoc - 1);
    quickSortRecursive(a, pivotLoc + 1, high);
  }
}

void quickSort(int a[], int n){
  quickSortRecursive(a, 0, n - 1);
}

int main(){
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::random_shuffle(a, a + 10);
  std::cout << "orignal: " << arrayToString(a, 10) << std::endl;
  quickSort(a, 10);
  std::cout << "sorted: " << arrayToString(a, 10) << std::endl;
}
