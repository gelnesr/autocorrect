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
#include <algorithm>

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

string alpha = "abcdefghijklmnopqrstuvwxyz"; 

void insertions(const string word, Str& possible){
  int str_l = word.length();
  int alpha_l = alpha.length();
  string word_copy(word);

  for(int i=0; i < alpha_l; i++){
    for(int j = 0; j<= str_l; j++){
      char c = alpha[i];
      word_copy.insert(j, 1,c); 
      possible.push_back(word_copy);
      word_copy=word;
    }
  }
}

void deletions(const string word, Str& possible){
  int str_l = word.length();
  string word_copy(word);
  for(int i =0; i< str_l; i++){
    word_copy.erase(i, 1);
    possible.push_back(word_copy);
    word_copy = word;
  }  
}

void transpositions(const string word, Str& possible){
  int str_l = word.length();
  string word_copy(word);
  for(int i = 0; i < str_l - 1; i++){
    char temp = word_copy[i];
    word_copy[i] = word_copy[i+1];
    word_copy[i+1] = temp;
    possible.push_back(word_copy);
    word_copy = word;
  }
}

void substitutions(const string word, Str& possible){
  int str_l = word.length();
  int alpha_l = alpha.length();
  string word_copy(word);

  for(int i=0; i < alpha_l; i++){
    for(int j = 0; j< str_l; j++){
      char temp = alpha[i];
      word_copy[j] = temp;
      possible.push_back(word_copy);
      word_copy = word;
    }
  }  
}

void edits(const string word, Str &possible){
  
  //insertion
  insertions(word, possible);

  //deletion
  deletions(word, possible);

  //transposition
  transpositions(word, possible);

  //substitutions
  substitutions(word, possible);
  
}
