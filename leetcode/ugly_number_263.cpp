#include <iostream>
class Solution {
public:
  bool isUgly(int num) {
    if(num == 0)
      return false;
    while(num % 2 == 0)
      num /= 2;
    while(num % 3 == 0)
      num /= 3;
    while(num % 5 == 0)
      num /= 5;
    return num == 1;
  }
};

int main(){
  Solution sol = Solution();
  std::cout << sol.isUgly(1) << std::endl;
  std::cout << sol.isUgly(2) << std::endl;
  std::cout << sol.isUgly(3) << std::endl;
  std::cout << sol.isUgly(5) << std::endl;
  std::cout << sol.isUgly(6) << std::endl;
  std::cout << sol.isUgly(8) << std::endl;
  std::cout << sol.isUgly(14) << std::endl;
}
