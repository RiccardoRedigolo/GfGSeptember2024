#include <iostream>


int wtf(std::string s) {
    int solution = 0;
    int counter = 0;
    bool negative = false;
    for (char a : s) {
        if (counter == 0 && a == '-') {
            negative = true;
            counter++;
        }
        else if (counter == 0 && a == '+') {
            counter++;
            continue;
        }
        else {
            counter++;
            if ('0' <= a && a <= '9') {
                solution = solution * 10 + (a - '0'); // Convert char to integer
            }
            else {
                return -1; // Invalid character found
            }
        }
    }
    
    if (negative) {
        solution = -solution;
    }
    
    return solution;
}


int main(){
  std::cout << wtf("abc") << std::endl;
  return 0;
}
