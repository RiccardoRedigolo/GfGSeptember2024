#include <vector>
#include <iostream>

bool ispar(std::string x)
{
  std::vector<char> open_queue(x.size());
  open_queue[0] = 'a';
  int open_index = 0;
  for (char a:x) {
    if (a == '{') {
      open_queue[open_index] = '{';
      open_index++;
    }
    else if (a == '}') {
      if (open_queue[open_index-1] != '{') {
	return false;
      }
      open_index--;
    }
    else if (a == '[') {
      open_queue[open_index] = '[';
      open_index++;
                
    }
    else if (a == ']') {
      if (open_queue[open_index-1] != '[') {
	return false;
      }
      open_index--;
    }
    else if (a == '(') {
      open_queue[open_index] = '(';
      open_index++;
    }
    else if (a == ')') {
      if (open_queue[open_index-1] != '(') {
	return false;
      }
      open_index--;
    }
  }
  if (open_index !=0) {
    return false;
  }
  return true;
}



int main(){
  std::string s = "{([])[(])}";
  std::cout << ispar(s) << std::endl;
  return 0;
}
