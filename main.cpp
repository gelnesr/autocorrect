//Gina El Nesr                                                                         
//gelnesr1                                                                             
//2021                                                                                 
//Computer Science + Molecular and Cellular Biology                                   
//Intermediate Programming at JHU for Fall 2017                                        
//Section 03                                                                           

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include "edits.h"
#include "correct.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::getline;
using std::vector;
using std::map; 
using std::cin;

typedef map<string, int> StrIntMap;
typedef vector<string> Str;

int main(){
  
  ifstream in_file;
  in_file.open("data/gutenberg.txt");
  
  string line;
  
  StrIntMap dict;
  
  while(getline(in_file,line)){
    string word;
    istringstream is(line);
    int num = 0;
    is >> word;
    is >> num;
    dict[word] = num;
  }
  string word;
  cin >> word;
  
  while(word != "quit"){
    StrIntMap matches;
    Str possible;
    string ans = correct(word, matches, dict, possible);
    if(ans == ""){
      cout << "No correction found" << endl;
    }
    else{
      cout << "Did you mean " << ans << "?" << endl;
    }
      cin >>word;
  }
  
  return 0;
}
