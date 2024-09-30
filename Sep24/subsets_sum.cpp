#include <iostream>
#include <vector>


std::vector<std::vector<int>> subsets_sum(std::vector<int>& v, int sum) {
  std::vector<std::vector<bool>> table(v.size(),std::vector<bool>(sum));
  for (auto i=0; i<v.size(); ++i) {
    for (auto j = 0; j<sum; ++j) {
      if (i==0) {
	table[i][j] = (v[0]==j+1);
	
      }
      else {
	table[i][j] = (table[i-1][j] || table[i-1][j-v[i]] || v[i]==j+1);
      }
      std::cout << table[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::vector<std::vector<int>> solution;
  for (auto i=0; i<v.size(); ++i) {
    if (table[v.size()-1-i][sum-1]==false) {
      return solution;
    }
    else{
      std::vector<int> path;
      int curr_sum = sum;
      int curr_index = v.size()-i-1;
      while (curr_index >-1) {
	if (curr_sum-v[curr_index]==0) {
	  path.push_back(curr_index);
	  solution.push_back(path);
	  break;
	}
	else if (curr_index ==0) {
	  break;
	}
	else if (table[curr_index-1][curr_sum-1-v[curr_index]]) {
	  curr_sum -= v[curr_index];
	  path.push_back(curr_index);
	  curr_index--;
	}
	else if (curr_index == v.size()-i-1){
	  break;
	}
	else {
	  curr_index --;
	}
      }
    }
  }
  std::vector<int> no_sol = {-1};
  solution.push_back(v);
  return solution;
}



int main(){
  std::vector<int> v = {7,2,4,12,8,1};
  int sum = 35;
  std::vector<std::vector<int>> sol = subsets_sum(v,sum);
  for (auto i=0; i<sol.size();++i) {
    for (auto j=0; j<sol[i].size(); ++j) {
      std::cout << sol[i][j] << " ";
    }
    std::cout << "\n";
  }
  return 0;
}
      
      
    
      
