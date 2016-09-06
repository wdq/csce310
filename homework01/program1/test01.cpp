#include "csce310hw001pt01.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main( int argc , char* argv[] ){
  unsigned long long int number;
  cin >> number;
  try{
    printf( "%llu contains %llu digit(s).\n" , number , numberOfDigits( number ) );
  }
  catch( exception e ){
    cerr << "ERROR" << endl;
  }
}
