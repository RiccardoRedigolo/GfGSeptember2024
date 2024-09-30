#include <iostream>
#include <vector>
#include <algorithm> 
#include <unordered_set>

std::vector<int> subarray(std::vector<int> v, int sum) {
  int start = 0;
  int end = 0;
  int current_sum = v[0];
  std::vector<int> solution = {start,end};
  while (end < v.size()) {
    if (current_sum == sum) {
      solution = {start,end};
      return solution;
    }
    else if (current_sum < sum) {
      end++;
      current_sum += v[end];
    }
    else if (end == start) {
      end ++;
      current_sum -= v[start];
      start ++;
      current_sum += v[end];
    }
    else {
      current_sum -= v[start];
      start++;
    }
  }
  std::vector<int> no_sol = {-1,-1};
  return no_sol;
    
}
  



int main(){
  std::vector<int> v = {1,14,12,7,19,87,137283,191,2};
  int sum = 193;
  std::cout << subarray(v,sum)[0] <<" " << subarray(v,sum)[1] << std::endl;
  return 0;
}
  
  
