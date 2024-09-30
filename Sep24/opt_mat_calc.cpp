#include <iostream>
#include <vector>



//matrices is a vector of N+1 integers such that the i-th matrix is matrices[i-1]xmatrices[i]
int min_operations(std::vector<int> matrices){
  int N = matrices.size()-1;
  std::vector<std::vector<int>> table(N,std::vector<int>(N));
  for (auto a =0;a<N;++a){
    table[0][a]=0;
  }
  for (auto i=1; i<N; ++i){
    for (auto j=0; j<N-i+1;++j){
      int left = matrices[j]*matrices[j+1]*matrices[i+j+1]+table[i-1][j+1];
      int right = matrices[j]*matrices[i+j]*matrices[i+j+1]+table[i-1][j];
      table[i][j] = std::min(left,right);
      for (auto k=1;k<i;++k){
	int tmp = table[k][j]+table[i-k-1][j+k+1]+matrices[j]*matrices[j+k+1]*matrices[i+j+1];
	if (tmp < table[i][j]){
	  table[i][j] = tmp;
	}
      }
    }
  }
  return table[N-1][0];
}


int main(){
  std::vector<int> matrices = {2,40,2,40,5};
  std::cout << min_operations(matrices);
  return 0;
}
