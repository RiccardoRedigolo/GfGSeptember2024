#include <iostream>
#include <vector>


int main(){
  bool f = false;
  bool t = true;
  std::vector<int> v = {1,2};
  std::cout << v[f] << " " << v[t] << std::endl;
  return 0;
}
