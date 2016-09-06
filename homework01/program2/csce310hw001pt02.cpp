#include "csce310hw001pt02.h"
#include <string>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;


// Algorithm: Johnson Trotter (n)
// Input: A positive integer n
// Output: A list of all permutations of {1.....n}
//
// initialize the first permutation with 12...n
// while the last permutation has a mobile element do
//    find its largest mobile element k
//    swap k with the adjacent element k's arrow points to
//    reverse the direction of all the elements that are larger than k
//    add the new permutation to the list
//
// ex: n = 3
// 123 132 312 321 231 213
// 
// I'm assuming that the numbers can be associated with indexes in
// some sort of char array. 
//
// Provided sample test:
// Input: word = ptvx, permutations = 5
// Output: ptvx, ptxv, pxtv, xptv, xpvt
//         1234, 1243, 1423, 4123, 4132
//
// So it does appear that the number n in the algorithm is associated
// with each char. The permutations number in the input is just how many 
// results should be printed out. 
//
// Actually it looks like it may be a little more complicated than I first thought.
// The direction is important, not just the number associated with each char.
// I will need to store the object in this format:
//    Letter: char
//    Associated number: int
//    Associated direction: bool (left = false, right = true)


class PermutationChar
{
	public:
		char Letter;
		int Index;
		bool Direction;
};

void printPermutations( string word , int permutations )
{

	// Create an array of permutation char objects.
	// This is "initialize the first permutation with 12...n"
	PermutationChar permutationArray[word.size()];
	for(int i = 0; i < word.size(); i++) {
		PermutationChar permutationChar;
		permutationChar.Letter = word[i];
		permutationChar.Index = i;
		permutationChar.Direction = false;
		permutationArray[i] = permutationChar;
	}

	// "while the last permutation has a mobile element do"
	for( int p = 0; p < permutations; p++ ){
		//cout << word << endl;

		// Print out the current permutation.
		for(int i = 0; i < word.size(); i++) {
			printf("%c", permutationArray[i].Letter);
		}
		printf("\n");

		// Find the next permutation.

		// "find its largest mobile element k"
		int maxMobileArrayIndex = -1;
		int maxMobileIndex = -1;
		for(int i = 0; i < word.size(); i++) {

			// Get the index and direction of the current element,
			// and the elements on each side of it.
			int previousIndex = -1;
			bool previousDirection = false;
			if(i != 0) {
				previousIndex = permutationArray[i - 1].Index;
				previousDirection = permutationArray[i - 1].Direction;
			}
			int currentIndex = permutationArray[i].Index;
			bool currentDirection = permutationArray[i].Direction;
			int nextIndex = -1;
			bool nextDirection = false;
			if(i != word.size() - 1) {
				nextIndex = permutationArray[i + 1].Index;
				nextDirection = permutationArray[i + 1].Direction;
			}

			// an element is mobile if:
			// a its arrow points to a smaller index next to it

			// Check the element on the left:
			// If the previous element exists (-1 is treated as a null),
			// and the previous index is less than the current element,
			// and the current direction points left,
			// then it's a mobile point.
			if(previousIndex != -1) {
				if((currentIndex > previousIndex) && (currentDirection == false)) {
					if(maxMobileIndex < currentIndex) {
						// Save the mobile point if it is greater than
						// the previously stored mobile point
						maxMobileArrayIndex = i;
						maxMobileIndex = currentIndex;						
					}
				}
			}

			// Check the element on the right: 
			// If the next element exists (-1 is treated as a null),
			// and the next index is less than the current element,
			// and the current direction points right,
			// then it's a mobile point.
			if(nextIndex != -1) {
				if((currentIndex > nextIndex) && (currentDirection == true)) {
					if(maxMobileIndex < currentIndex) {
						// Save the mobile point if it is greater than
						// the previously stored mobile point
						maxMobileArrayIndex = i;
						maxMobileIndex = currentIndex;						
					}
				}
			}
		}

		// "swap k with the adjacent element k's arrow points to"
		PermutationChar maxMobilePermutationChar = permutationArray[maxMobileArrayIndex];
		int indexOfElementToSwapWith = maxMobilePermutationChar.Direction ? maxMobileArrayIndex + 1 : maxMobileArrayIndex - 1;
		PermutationChar permutationCharToSwapWith = permutationArray[indexOfElementToSwapWith];

		permutationArray[indexOfElementToSwapWith] = maxMobilePermutationChar;
		permutationArray[maxMobileArrayIndex] = permutationCharToSwapWith;


		//  "reverse the direction of all the elements that are larger than k"
		for(int i = 0; i < word.size(); i++) {
			if(permutationArray[i].Index > maxMobileIndex) {
				permutationArray[i].Direction = !permutationArray[i].Direction;
			}
		}

		// Quit if there aren't any more mobile elements.
		if(maxMobileArrayIndex == -1 && maxMobileIndex == -1) {
			return;
		}


	}
 	return;
}


