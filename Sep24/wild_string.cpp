#include <iostream>
#include <algorithm>
#include <vector>


bool match(std::string wild, std::string pattern)
    {
        std::vector<std::vector<bool>> table(wild.size(),std::vector<bool>(pattern.size()));
        for (auto i=0; i<pattern.size(); ++i){
            char a = wild[0];
            if (a=='*'){
                table[0][i] = true;
            }
            else if (a=='?' && i==0){
                table[0][i] = true;
                break;
            }
            else if(a==pattern[0]){
                table[0][i] = true;
                break;
            }
            
        }
        for (auto i=1; i<wild.size();++i){
            char a = wild[i];
            if (a == '*'){
                if (std::find(table[i-1].begin(),table[i-1].end(),true)!=table[i-1].end()){
                    for (auto j=0; j<pattern.size();++j){
                        table[i][j]=true;
                    }
                }
            }
            else{
                for (auto j=0; j<pattern.size();++j){
                    if (a=='?' && table[i-1][j-1]){
                        table[i][j] = true;
                    }
                    else if(a==pattern[j] && table[i-1][j-1]){
                        table[i][j] = true;
                    }
                    
                }
                
                
                
            }
            
        }
        return table[wild.size()-1][pattern.size()-1];
    }


int main(){
    std::string s = "**geeks";
    std::string w = "geeks";
    if (match(s,w)){
        std::cout <<  "Yes" << std::endl;
    }
    else{
        std::cout << "No" << std::endl;
    }
    return 0;

}