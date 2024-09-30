#include <iostream>
#include <vector>



std::vector<std::string> laurea_mat = {"laurea di primo livello in scienze matematiche", "laurea", "laurea matematica","laurea triennale"};

int main(){
  std::string s;
  std::string reply="s";
  bool found = false;
  while (reply == "s"){
    std::cout << "Prego inserire ricerca:" << std::endl;
    std::cin >> s;
    for (std::string a:laurea_mat) {
      if (a==s) {
	std::cout << "Trovato:" << " laurea di primo livello in scienze matematiche" << std::endl;
	found = true;
      }
    }
    if (!found){
      std::cout << "La ricerca ha dato esito negativo" << std::endl;
    }
    std::cout << "Vuole fare altre ricerche?[s/n]" << std::endl;
    std::cin >> reply;
  }
}
  
