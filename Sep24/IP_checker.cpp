#include <iostream>
#include <stdexcept>


bool IP_checker(std::string str){
  std::string tmp="";
  int counter = 0;
  for (char a: str){
    if (counter >4){
      return false;
    }
    else if (tmp[0]=='0' && tmp.size()>1){
      return false;
    }
    else if (a=='.'){
      try{
	int checker = std::stoi(tmp);
	if (checker >-1 && checker <256){
	  tmp = "";
	  counter ++;
	}
	else{
	  return false;
	}
      }
      catch (const std::invalid_argument &e){
	return false;
      }
    }
    else{
      tmp += a;
    }
  }
  try{
    int checker = std::stoi(tmp);
    if (checker >-1 && checker <256){
      tmp = "";
      counter ++;
    }
    else{
      return false;
    }
  }
  catch (const std::invalid_argument &e){
    return false;
  }
    
  if (counter !=4){
    return false;
  }
  else if (tmp[0]=='0' && tmp.size()>1){
    return false;
  }
  return true;
  // code here
}


int main(){
  std::cout << IP_checker("101.101.01.121");
}
