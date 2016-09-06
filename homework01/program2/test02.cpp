#include "csce310hw001pt02.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main( int argc , char* argv[] ){
  int permutations;
  string word;
  cin >> permutations;
  cin >> word;
  try{
    printPermutations( word , permutations );
  }
  catch( exception e ){
    cerr << "ERROR" << endl;
  }
}
