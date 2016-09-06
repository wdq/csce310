#include "csce310hw001pt01.h"
#include <string.h>
#include <stdio.h>

using namespace std;

unsigned long long int numberOfDigits( unsigned long long int digits ){
	char chars[32]; // Should be way bigger than any unsigned int input.
	sprintf(chars, "%ld", digits);
	return strlen(chars);
}