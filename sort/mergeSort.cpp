#include <iostream>
#include <algorithm>
#include "../utils.h"

void mergeSortRecursive(int a[], int reg[], int start, int end){
  if(start >= end)
    return;
  int mid = start + (end - start) / 2;
  int start1 = start;
  int end1 = mid;
  int start2 = mid + 1;
  int end2 = end;
  mergeSortRecursive(a, reg, start1, end1);
  mergeSortRecursive(a, reg, start2, end2);
  int k = start;
  while(start1 <= end1 && start2 <= end2)
    reg[k++] = a[start1] <= a[start2] ? a[start1++] : a[start2++];
  while(start1 <= end1)
    reg[k++] = a[start1++];
  while(start2 <= end2)
    reg[k++] = a[start2++];
  for(k = start; k <= end; k ++)
    a[k] = reg[k];
}

void naturalMergeSortRecursive(int a[], int reg[], int start, int end){
  if(start >= end)
    return;
  int mid = start;
  while(mid < end && a[mid] <= a[mid+1])
    mid ++;
  if(mid == end)
    return;
  int start1 = start;
  int end1 = mid;
  int start2 = mid + 1;
  int end2 = end;
  naturalMergeSortRecursive(a, reg, start1, end1);
  naturalMergeSortRecursive(a, reg, start2, end2);
  int k = start;
  while(start1 <= end1 && start2 <= end2)
    reg[k++] = a[start1] <= a[start2] ? a[start1++] : a[start2++];
  while(start1 <= end1)
    reg[k++] = a[start1++];
  while(start2 <= end2)
    reg[k++] = a[start2++];
  for(k = start; k <= end; k ++)
    a[k] = reg[k];
}

void mergeSort(int a[], int n){
  int reg[n];
  naturalMergeSortRecursive(a, reg, 0, n - 1);
}

int main(){
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::random_shuffle(a, a + 10);
  std::cout << "orignal: " << arrayToString(a, 10) << std::endl;
  mergeSort(a, 10);
  std::cout << "sorted: " << arrayToString(a, 10) << std::endl;
}
