#include <iostream>
#include <vector> 

std::string grow_odd(std::string s, int i){
  std::string odd_s;
  int left = 1;
  while (i+left<s.size() && i-left >=0){
    std::string l;
    std::string r;
    l= s[i-left];
    r = s[i+left];
    if (l==r){
      left++;
    }
    else{
      break;
    }
  }
  return s.substr(i - left + 1, 2 * left - 1);
}

std::string grow_even(std::string s, int i){
  if (i<1 || s[i]!=s[i-1]){
    return "";
  }
  std::string even_s;
  int left = 1;
  while (i+left<s.size() && i-left >0){
    std::string l;
    std::string r;
    l= s[i-left-1];
    r = s[i+left];
    if (l==r){
      left++;
    }
    else{
      break;
    }
  }
  return s.substr(i - left, 2 * left);
}



std::string longestPalin (std::string s){
  std::string solution;
  solution += s[0];
  int max_l = solution.size();
  for (auto i=1; i<s.size();++i) {
    std::string tmp;
    std::string even_s= grow_even(s,i);
    std::string odd_s = grow_odd(s,i);
    if (even_s.size()>=odd_s.size()){
      tmp = even_s;
    }
    else{
      tmp = odd_s;
    }
    if (tmp.size()>max_l){
      max_l=tmp.size();
      solution = tmp;
    }
  }
  return solution;
}


int main(){
  std::string s = "abcdedcfghhgf";
  std::cout << longestPalin(s) << std::endl;
}
