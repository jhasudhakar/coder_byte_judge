#include <iostream>
#include <string>
using namespace std;

string CodelandUsernameValidation(string str) {
  
  // code goes here  
  if(str.size() <4 || str.size()>25)
    return "false";

   if(!((str[0] >= 'A' && str[0] <= 'Z') || 
    (str[0] >= 'a' && str[0] <= 'z')))
    {
      return "false";
    }

    if(str[str.size()-1] == '_')
      return "false";
    for(unsigned int i=0; i<str.size(); i++)
    {
      int invalid_count = 0;

      if(!((str[i] >= 'A' && str[i] <= 'Z') || 
           (str[i] >= 'a' && str[i] <= 'z')))
      {
        invalid_count++;
      }
      if(!(str[i] >='0' && str[i] <= '9'))
        invalid_count++;

      if(str[i] != '_')
        invalid_count++;
      if(invalid_count == 3)
        return "false";
    }
    return "true";
}

int main(void) { 
   
  // keep this function call here
  cout << CodelandUsernameValidation(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}