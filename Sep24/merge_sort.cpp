#include <iostream>
#include <vector>

void merge(std::vector<int>& v, int start, int middle, int end){
    std::vector<int> w(end-start+1);
    int index1 = start;
    int index2 = middle+1;
    int counter = 0;
    while (counter <end-start+1){
        if (v[index1]<=v[index2] && index1<=middle){
            w[counter] = v[index1];
            index1++;
        }
        else if (v[index2]<=v[index1] && index2<=end){
            w[counter] = v[index2];
            index2++;
        }
        else if (index2>end){
            w[counter]=v[index1];
            index1++;
        }
        else{
            w[counter]=v[index2];
            index2++;
        }
        counter++;
    }
    
    for (auto i =start; i<end+1; ++i){
        v[i] = w[i-start];
        
    }
    
        
}
    
void m_sort(std::vector<int> & v, int start, int end){
    if (start<end){
        
        int m = (end+start)/2;
        
        m_sort(v, start,m);
        m_sort(v,m+1,end);
        merge(v,start,m,end);
    }
}


int main(){
    std::vector<int> v = {1,4,7,2,5,9};
    merge(v,0,2,5);
    for (auto a:v){
        std::cout << a << " ";
    }
    std::vector<int> w = {1,7,10,3,2,5,11,0,18,9};
    m_sort(w,0,w.size()-1);
    for (auto a:w){
        std::cout << a << " ";
    }
    return 0;
}