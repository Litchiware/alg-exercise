#include <iostream>
using namespace std;
int length(int x11, int x12, int x21, int x22){
  if(x11 >= x22 || x12 < x21)
    return 0;
  return (x12 < x22 ? x12 : x22) - (x11 > x21 ? x11 : x21);
}

int overlapArea(int A, int B, int C, int D, int E, int F, int G, int H){
  int width = length(A, C, E, G);
  int height = length(B, D, F, H);
  return width * height;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
  return (D - B) * (C - A) + (G - E) * (H - F) - overlapArea(A, B, C, D, E, F, G, H);
}

int main(){
  int A = -1500000001;
  int B = 0;
  int C = -1500000000;
  int D = 1;
  int E = 1500000000;
  int F = 0;
  int G = 1500000001;
  int H = 1;
  cout << computeArea(A, B, C, D, E, F, G, H) << endl;
}
