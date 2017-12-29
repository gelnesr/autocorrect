//Gina El Nesr         
//gelnesr1               
//2021                    
//Computer Science + Biology                                         
//Intermediate Programming at JHU for Fall 2017        
//Section 03


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include "edits.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::getline;
using std::vector;
using std::map;
using std::cin;
using std::make_pair;

typedef map<string, int> StrIntMap;
typedef vector<string> Str;

string find_max(const StrIntMap matches){
  int currentMax = 0;
  string arg_max;
  for(auto it = matches.cbegin(); it != matches.cend(); ++it ){
    if (it->second > currentMax) {
      arg_max = it->first;
      currentMax = it->second;
    }
  }
  return arg_max;
}

void known(Str& possible, StrIntMap& dict, StrIntMap& matches){
  for(auto i = possible.begin(); i != possible.end(); i++){
    string find = *i;
    if(dict.find(find) != dict.end()){
      matches.insert(make_pair(find, dict[find]));
    }
  }
}

string correct(const string word, StrIntMap& matches, StrIntMap& dict, Str& possible){
  if(dict.find(word) != dict.end()){
    return word;
  }
  else{
    edits(word, possible);
    known(possible, dict, matches);
    if(!matches.empty()){
      string correct(find_max(matches));
      return correct;
    }
    else{
      Str temp = possible;
      for(auto i = temp.begin(); i != temp.end(); i++){
	string find = *i;
	edits(find, possible);
      }
      known(possible, dict, matches);
      if(!matches.empty()){
	string correct(find_max(matches));
	return correct;
      }
    }
  }
  string empty = "";
  return empty;
}
