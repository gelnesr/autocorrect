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

//Finds how many words are in the file
int wordsInFile(const string filename){
  ifstream fin;
  fin.open(filename);
  string line;
  int c = 0;
  while(getline(fin, line)){
    string word;
    istringstream is(line);
    is >> word;
    c++;
  }
  return c;
}

//Checks the vector with the file with correct output
int checkFileVector(const string file, Str& possible){
  ifstream file_test;
  file_test.open(file);
  string line;
  int c = 0;
  int num = wordsInFile(file);
  int size = possible.size();
  //If the number of words in the file isn't equal to the number of words in the vector, then test failed
  if(num != size){
    return 0;
  }
  while(getline(file_test, line)){
    string word;
    istringstream is(line);
    is >> word;
    if(possible.at(c) != word)
      return 0;
    c++;
  }
  return 1;
}

int test_edits(const string word, const string file){
  Str possible;
  edits(word, possible);
  int check = checkFileVector(file, possible);
  if(check == 0){
    cout << "Failed Test Edits" << endl;
  }
  return check;
}

int test_transpositions(const string word, const string file){
  Str possible;
  transpositions(word, possible);
  int check = checkFileVector(file, possible);
  if(check == 0){
    cout << "Failed Transposition" << endl;
  }
  return check;
}

int test_insertions(const string word, const string file){
  Str possible;
  insertions(word, possible);
  int check = checkFileVector(file, possible);
  if(check == 0){
    cout << "Failed Insertions" << endl;
  }
  return check;
}

int test_deletions(const string word, const string file){
  Str possible;
  deletions(word, possible);
  int check = checkFileVector(file, possible);
  if(check == 0){
    cout << "Failed Deletions" << endl;
  }
  return check;
}

int test_substitutions(const string word, const string file){
  Str possible;
  substitutions(word, possible);
  int check = checkFileVector(file, possible);
  if(check == 0){
    cout << "Failed Substitution" << endl;
  }
  return check;
 
}

int test_correct(const string word, const string actual, StrIntMap& matches, StrIntMap& dict, Str& possible){
  
  string r = correct(word, matches, dict, possible);
  if(r == actual)
    return 1;
  else{
    cout << "Failed Correct" << endl;
    return 0;
  }
}

int test_known(StrIntMap& matches, string actual){
  if(!((*matches.begin()).first == actual)){
    cout << "Failed Known" << endl;
    return 0;
  }
  return 1;
}

int main(){

  ifstream in_file;
  in_file.open("data/gutenberg.txt");
  string line;
  StrIntMap dict;
  Str vector;

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
    Str possible;
    string test_S_file = "tests/substitutions_" + word + ".txt";
    string test_T_file = "tests/transpositions_" + word + ".txt";
    string test_I_file = "tests/insertions_" + word + ".txt";
    string test_D_file = "tests/deletions_" + word + ".txt";
    string test_E_file = "tests/edits_"+ word + ".txt";
    
    if(test_substitutions(word, test_S_file) == 0){
      return 1;
    }
    else if(test_transpositions(word, test_T_file) == 0){
      return 1;
    }
    else if(test_insertions(word, test_I_file) == 0){
      return 1;
    }
    else if(test_deletions(word, test_D_file) ==0){
      return 1;
    }
    else if(test_edits(word, test_E_file) ==  0){
      return 1;
    }

    //Make Dict                                                                                                                
    StrIntMap map_dict;
    map_dict["appropriately"] = 5;
    map_dict["had"] = 7383;
    map_dict["crowd"] = 225;
    map_dict["beloved"] = 19;
    map_dict["shadow"] = 58;

    Str c_possible;
    StrIntMap matches;
    string actual = "shadow";
    int c_test = test_correct("shhadow", actual, matches, map_dict, c_possible);
    if(c_test == 0){
      return 1;
    }
    else if( test_known( matches, actual) ==0){
      return 1;
    }
    cout << "All Tests Successful" << endl;
    cin >> word;
  }
  return 0;

}
