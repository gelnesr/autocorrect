//Gina El Nesr                                                                                                                    
//gelnesr1                                                                                                                       
//2021                                                                                                                           
//Computer Science + Molecular and Cellular Biology                                                                              
//Intermediate Programming at JHU for Fall 2017                                                                                  
//Section 03  
#ifndef EDITS_H
#define EDITS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>

using std::vector;
using std::string;

typedef vector<string> Str;

void insertions(const string word, Str& possible);
void edits(const string word, Str& possible);
void deletions(const string word, Str& possible);
void transpositions(const string word, Str& possible);
void substitutions(const string word, Str& possible);
#endif
