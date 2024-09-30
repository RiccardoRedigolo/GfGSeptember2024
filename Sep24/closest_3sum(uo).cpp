#include <iostream>
#include <vector>
#include <algorithm> 

int closest_3sum(std::vector<int>& v, int sum) {
  std::sort(v.begin(),v.end());
  int solution = v[0]+v[v.size()-2]+v[v.size()-1];
  int diff = std::abs(sum-solution);
  for (auto j=0; j<v.size()-2; ++j) {
    int i = v.size()-1-j;
    int centre = i;
    int left = 0;
    int right = i-1;
    while (left<right) {
      int curr_sum = v[left]+v[centre]+v[right];
      if ((diff >std::abs(sum-curr_sum))){
	diff = std::abs(sum-curr_sum);
	solution = curr_sum;
      }
      else if (diff==std::abs(sum-curr_sum) && solution < curr_sum){
          solution = curr_sum;
      }
      else if (sum-curr_sum<0) {
	right--;
      }
      else {
	left++;
      }
    }
  }
  return solution;
}


int main() {
  std::vector<int> v = {5,2,5,7};
  std::sort(v.begin(),v.end());
  int sum = 13;
  std::cout << closest_3sum(v,sum);
  return 0;
}
