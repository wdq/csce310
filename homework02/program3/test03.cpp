#include "csce310hw002pt03.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main( int argc , char* argv[] ){
  vector<int> number;
  int num;
  while( cin >> num ){
    number.push_back( num );
  }

  printf( "%f comparisons are needed.\n" , averageComparisons( number ) );
}
