#include <vector>
#include <iostream>



long long trappingWater(std::vector<int> &arr) {
  int boundary1 = arr[0];
  int boundary2 = arr[arr.size()-1];
  int index1 =0;
  int index2 = arr.size()-1;
  long long result =0;
  long long partial =0;
  bool backwards = false;
  int index = 1;
  while(index1<index2) {
    backwards = (arr[index2]<=arr[index1]);
    if (backwards) {
      if (index1 == index2-index){
	result += partial;
	index2-=index;
	partial =0;
	index = 1;
      }
      else if (arr[index2-index]>=arr[index2]){
	result += partial;
	index2-=index;
	partial =0;
	index = 1;
      }
      else {
	partial += arr[index2]-arr[index2-index];
	index++;
      }
    }
    else {
      if (index1 == index2-index){
	result += partial;
	index1+=index;
	partial =0;
	index = 1;
      }
      else if (arr[index1+index]>=arr[index1]){
	result += partial;
	index1+=index;
	partial =0;
	index = 1;
      }
      else {
	partial += arr[index1]-arr[index1+index];
	index++;
      }
                
    }
  }
  return result;
}


int main(){
  std::vector<int> v = {3, 4, 4, 6, 0, 6, 6, 1, 8, 4, 9, 6};
  std::cout << trappingWater(v);
}
