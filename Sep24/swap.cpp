#include <iostream>

void swap(int & a, int & b){
  int* temp;
  temp = &a;
  a=b;
  b=*temp;
  delete temp;
}


int main(){
  int a =10;
  int b = 29;
  swap(a,b);
  std::cout << "a:" << a << " b: " << b << std::endl;
}
