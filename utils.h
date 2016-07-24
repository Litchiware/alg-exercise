#include <sstream>

std::string arrayToString(int a[], int n){
  std::stringstream ss;
  ss << "[";
  const char* sep = "";
  for(int i = 0; i < n; i ++){
    ss << sep << a[i];
    sep = ", ";
  }
  ss << "]";
  return ss.str();
}

