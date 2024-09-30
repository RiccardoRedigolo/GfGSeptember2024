#define date_conversion_hpp_
#ifndef date_conversion_hpp_

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>





template<typename type>
bool rev_lex(std::vector<type> v1, std::vector<type> v2){
  if (v1.size()!=v2.size()){
    throw std::invalid_argument("The two vectors need to have the same dimension");
  }
  else{
    for (auto  i=v1.size()-1; i>=0;--i){
      if (v1[i]<v2[i]){
	return true;
      }
      else if (v1[i]>v2[i]){
	return false;
      }
    }
  }
  return false;
}


int number_of_days(int month, int year);


bool is_valid(std::vector<int> date);


std::vector<int> date_to_num(std::string date);




class Date{
public:
  Date(std::string & date) : string_v(date){
    v_version = date_to_num(date);
  }

  Date(std::vector<int> & date) : v_version(date) {
    if (is_valid(date)){
      string_v= std::to_string(date[0])+"/"+std::to_string(date[1])+"/"+std::to_string(date[2]);
    }
    else{
      throw std::invalid_argument("The inserted date is invalid");
    }
  }

  bool operator <(Date& other){
    return rev_lex<int>(this->v_version,other.v_version);
  }

  
private:
  std::vector<int> v_version;
  std::string string_v;
};


int time_diff(std::vector<int> date1, std::vector<int> date2){
  return 1;
}





std::string compute_week_day(std::string date){
  std::vector<int> data = date_to_num(date);
  
  return "nope";
}

#endif
