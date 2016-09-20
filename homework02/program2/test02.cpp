#include "csce310hw002pt02.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main( int argc , char* argv[] ){
  int sum;
  vector<int> number;
  cin >> sum;
  int num;
  while( cin >> num ){
    number.push_back( num );
  }

  if( sumToN( number , sum ) ){
    cout << "There are two numbers." << endl;
  }
  else{
    cout << "There are not two numbers." << endl;
  }
}
