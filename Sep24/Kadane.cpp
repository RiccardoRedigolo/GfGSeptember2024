#include <iostream>
#include <vector>



std::vector<int> Kadane(std::vector<int> v) {
  std::vector<int> table(v.size());
  table[0] = v[0];
  int current_min=0;
  int min_index = -1;
  int best_end_index = 0;
  int current_sum = v[0];
  for (auto i=1; i<v.size(); ++i) {
    table[i] = table[i-1]+v[i];
    if (table[i-1] < current_min) {
      current_min = table[i-1];
      if (current_sum < table[i]-current_min) {
	best_end_index = i;
	min_index = i-1;
	current_sum = table[i]-current_min;
      }
    }
    else if (current_sum < table[i]-current_min) {
      best_end_index = i;
      current_sum = table[i]-current_min;
    }
    std::cout << current_sum << std::endl;
    
  }
  std::vector<int> solution(best_end_index-min_index);
  for (auto k=min_index+1; k<best_end_index+1; ++k) {
    solution[k-min_index-1] = v[k];
  }
  return solution;
}




int main() {
  std::vector<int> v = {90, 64, -76, 65, 1, 93, -99, -76, -87, 88, 63, -79, 85, -15, 4 ,-32, 69, -22};
  std::vector<int> w = Kadane(v);
  int sum =0;
  for (auto a:w) {
    sum += a;
    std::cout << a << std::endl;
  }
  std::cout << sum << std::endl;
}
