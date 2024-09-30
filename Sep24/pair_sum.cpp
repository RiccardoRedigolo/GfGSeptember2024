#include <iostream>
#include <vector>
#include <algorithm> 
#include <unordered_set>

std::vector<int> closest_2sum(std::vector<int> ordered_v, int sum) {
  int i= 0;
  int j= ordered_v.size()-1;
  std::vector<int> solution = {ordered_v[i],ordered_v[j]};
  int diff = std::abs(sum-solution[0]-solution[1]);
  while (i<j) {
    if (diff > std::abs(sum-ordered_v[i]-ordered_v[j])){
      diff = std::abs(sum-ordered_v[i]-ordered_v[j]);
      solution = {ordered_v[i],ordered_v[j]};
    }
    else if (sum-ordered_v[i]-ordered_v[j]<0) {
      j--;
    }
    else {
      i++;
    }
  }
  return solution;
}
  



int main(){
  std::vector<int> v = {1,14,-12,7,19,87,137283,191,2};
  std::sort(v.begin(),v.end());
  int sum = 18;
  if (closest_2sum(v,sum)) {
    std::cout << "YEEEEEEE" << std::endl;
  }
  return 0;
}
  
  
