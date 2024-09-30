#include <iostream>
#include <vector>
#include <algorithm>

int getMinDiff(std::vector<int> &arr, int k) {
  /*std::sort(arr.begin(),arr.end());
    int max_diff = 0;
    int min_num = arr[arr.size()-1]+k;
    if (arr[arr.size()-1]-arr[0]<k) {
    return arr[arr.size()-1]-arr[0];
    }
    for (auto i=0; i<arr.size();++i) {
    if (arr[i]<k){
    min_num = std::min(min_num, arr[i]+k);
    max_diff = arr[i]-arr[0];
    }
    else if (k<=arr[i]-arr[0] && arr[i]-arr[0]<2*k){
    min_num = std::min(min_num, )
    max_diff = std::max(max_diff, -arr[i]+arr[0]+2*k);
    }
    else {
    max_diff = std::max(max_diff, arr[i]-arr[0]-2*k);
    }
    }
    return max_diff;*/
  std::sort(arr.begin(),arr.end());
  int max_diff =0;
  int max_num = arr[0]+k;
  int min_num = arr[0]+k;
  for (auto a: arr) {
    if (a<=k) {
      std::cout << a << std::endl;
      max_diff = std::max(max_num-min_num, max_diff);
      std::cout << max_diff << std::endl;
      max_num = a+k;
    }
    else{
      std::cout << a << std::endl;
      if (a+k-min_num<=std::abs(max_num-a+k)){
	max_num = std::max(a+k,max_num);
	max_diff = std::max(max_diff, a+k-min_num);
      }
      else{
	min_num = std::min(min_num, a-k);
	max_num = std::max(max_num, a-k);
	max_diff=std::max(max_diff, std::abs(max_num-a+k));
      }
      std::cout << max_num << " " << min_num << std::endl;
    }
  }
  return max_num-min_num;
}


int main(){
  std::vector<int> v = {1,5,8,10};
  std::cout <<  getMinDiff(v,2) << std::endl;
}
