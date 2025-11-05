#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}


/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string pass){
  string lower_copy = pass;
  string upper_copy = pass;
  
  for(int i = 0; i < lower_copy.length(); i++){
    lower_copy[i] = tolower(lower_copy[i]);
  }
  
  for(int i = 0; i < upper_copy.length(); i++){
    upper_copy[i] = toupper(upper_copy[i]);
  }
  
  if(pass == lower_copy || pass == upper_copy){
    return false;
  }
  
  return true;
}
