#include "date_conversion.hpp"

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>




int number_of_days(int month, int year){
  if (month >12 || month <1){
    throw std::invalid_argument("The month must be between 1 and 12");
  }
  std::vector<int> trenta = {4,6,9};
  if (month ==2){
    if (year%4){
      return 28;
    }
    return 29;
  }
  else if (std::find(trenta.begin(),trenta.end(),month)!=trenta.end()){
    return 30;
  }
  return 31;
}



bool is_valid(std::vector<int> date){
  if (date[0] > 31 || date[0]<1 || date[1]<1 || date[1]>12){
    return false;
  }
  try {
    if (date[0]<=number_of_days(date[1],date[2])){
      return true;
    }
    else{
      return false;
    }
  }
  catch(std::invalid_argument & e){
    return false;
  }
  return false;
}



std::vector<int> date_to_num(std::string date){
  int counter = 0;
  std::string tmp = "";
  std::vector<int> result(3);
  for (char a: date){
    if (counter >3){
      throw std::invalid_argument("The inserted date is invalid. Valid format: \"dd/mm/yyyy\"");
    }
    else if (a=='/'){
      try{
	int checker = std::stoi(tmp);
	if (checker >0 && checker <32){
	  result[counter]=checker;
	  tmp = "";
	  counter ++;
	}
	else{
	  throw std::invalid_argument("The inserted date is invalid. Valid format: \"dd/mm/yyyy\" ");
	}
      }
      catch (const std::invalid_argument &e){
	throw std::invalid_argument("The inserted date is invalid. Valid format: \"dd/mm/yyyy\"");
      }
    }
    else{
      tmp += a;
    }
  }
  
  try{
    int checker = std::stoi(tmp);
    result[counter]=checker;
    tmp = "";
    counter ++;
  }
  catch (const std::invalid_argument &e){
    throw std::invalid_argument("The inserted date is invalid. Valid format: \"dd/mm/yyyy\"");
  }
  if (counter !=3){
    throw std::invalid_argument("The inserted date is invalid. Valid format: \"dd/mm/yyyy\"");
  }
  if (!is_valid(result)){
    throw std::invalid_argument("The inserted date is invalid. Valid format: \"dd/mm/yyyy\"");
  }
  return result;
}


int main(){
  std::string s = "12/1/2024";
  std::vector<int> v = date_to_num(s);
  for (auto a:v){
    std::cout << a << " ";
  }
  std::cout << std::endl;
  return 0;
}
