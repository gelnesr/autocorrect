//Gina El Nesr                                                                                                                   
//gelnesr1                                                                                                                       
//2021                                                                                                                           
//Computer Science + Molecular and Cellular Biology                                                                              
//Intermediate Programming at JHU for Fall 2017                                                                                  
//Section 03  
#ifndef CORRECT_H
#define CORRECT_H

#include <iostream>
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

typedef map<string, int> StrIntMap;
typedef vector<string> Str;

string correct(string word, StrIntMap& matches, StrIntMap& dict, Str& possible);
string find_max(const StrIntMap matches);
void known(Str& possible, StrIntMap& dict, StrIntMap& matches);
#endif
