#include <iostream>
#include <vector>


long long Hanoi_solver(int n, int tow1=1, int tow2=3, int tow3=2){
    int counter =0;
    if (n==1){
        std::cout << "move disk " << n << " from rod " << tow1 <<" to rod " << tow2 << std::endl;
        counter++;
        return counter;
    }
    else{
        counter += Hanoi_solver(n-1,tow1,tow3,tow2);
        std::cout << "move disk " << n << " from rod " << tow1 <<" to rod " << tow2 << std::endl;
        counter++;
        counter+= Hanoi_solver(n-1,tow3,tow2,tow1);
    }
    return counter;
}


int main(){
    std::cout << Hanoi_solver(18) << std::endl;
}