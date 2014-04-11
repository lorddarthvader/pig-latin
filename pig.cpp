#include <iostream>
#include <vector>
#include <sstream>
#include <string.h>

std::vector<std::string> split(std::string& rawstring) 
{
  std::string tmp;
  std::vector<std::string>array;
  std::stringstream ss(rawstring);
  while(std::getline(ss, tmp, ' '))
    array.push_back(tmp);
  return array;
}

bool upper(std::string str) 
{
  int x = 0;
  for(int i = 0; i < str.length(); i++) 
    {
      if(isupper(str[i]))
	x += 1;
    }
  return (x==str.length()) ? true : false;
}

std::string tupper(std::string lower) 
{
  std::string upper_case = "";
  for(int i = 0; i < lower.length(); i++)
    upper_case += toupper(lower[i]);
  return upper_case;
}

std::string convert(std::string usrin) 
{
  bool fcap = false;
  if(isupper(usrin[0]))
    fcap = true;
  std::string end = "ay";
  if(upper(usrin))
    end = "AY";
  bool vowel = false;
  char vowels[] = {'a', 'e', 'i', 'o', 'u'};
  std::string letters[] = {"th", "ch", "sh", "ph", "wh", "qu"};
  std::string pig = "";
  for(int i = 0; i < 5; i++)
    {
      if(tolower(usrin[0])==vowels[i]) 
	{
	  vowel = true;
	  break;
	}
    }
  std::string newstr = "";
  for(int i = 0; i < 2; i++)
    newstr += tolower(usrin[i]);
  for(int i = 0; i < 6; i++) 
    {
      if(newstr == letters[i]) 
	{
	  for(int x = 2; x < usrin.length(); x++) 
	    pig += usrin[x];
	  if(upper(usrin))
	    newstr = tupper(newstr);
	  if(fcap)
	    pig[0] = toupper(pig[0]);
	  return pig + newstr + end;
	  break;
	}
    }
  if(!vowel) 
    {
      for(int i = 1; i < usrin.length(); i++)
	pig += usrin[i];
      if(fcap)
	pig[0] = toupper(pig[0]);
      return pig + usrin[0] + end;
    } 
  else 
    {
      std::string vend = "way";
      if(upper(usrin))
	vend = "WAY";
      return usrin + vend;
    }
}

int main() 
{
  std::string str;
  while(std::getline(std::cin, str)) 
    {
      std::vector<std::string>arr = split(str);
      std::string p_latin = "";
      for(int i = 0; i < arr.size(); i++)
	p_latin += convert(arr[i]) + " ";
      std::cout << p_latin << std::endl;
    }
}


