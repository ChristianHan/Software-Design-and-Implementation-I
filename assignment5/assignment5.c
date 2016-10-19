/*
 * assignment5.c
 * SpellCheck
 */

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
#include <stdlib.h>

/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
 *
 * Many students find it helpful to declare global variables (often arrays). You are welcome to use
 * globals if you find them helfpul. Global variables are by no means necessary for this project.
 */

/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
 * exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
 * You are expected to use reasonable programming style. I strongly encourage you to avoid big functions
 * (while there are always exceptions, a good rule of thumb is about 15 lines in a function).
 * So, plan on implementing spellCheck by writing two or three other "support functions" that
 * help make the actual spell checking easier for you.
 * There are no explicit restictions on using functions from the C standard library. However,
 * for this project you should avoid using functionality from the C++ standard libary. You will
 * almost certainly find it easiest to just write everything you need from scratch!
 */

//TODO:
void spellCheck(char article[], char dictionary[]) {


	int start = 0; //  (start) is used to bump article pointer
	int end = 0;//   (end) is used to bump start pointer
	int n = 0;
	int j = 0;

	//char let1 = article[start];
	//char let2 = article[end];

	while (article[start] != 0) {
		if ((article[start] >= 'a' && article[start] <= 'z') || (article[start] >= 'A' && article[start] <= 'Z')) {//used to see if the pointer of the current array is a letter
			end = end + 1;
			while ((article[end] >= 'a' && article[end] <= 'z') || (article[end] >= 'A' && article[end] <= 'Z')) {
				end = end + 1;
			}
			if ((end - start) >= 2) { //used to weed out any string with less than 2 letters. 
				j = (end - start);
				for (n = 0; n < j; n = (n + 1)) {
					printf("%c", article[start]);
					start = start + 1;
				}
				printf("\n");
				if (article[end] != 0) {
					start = start + 1;
					end = end + 1;
				}
			}
			else {
				end = end + 1;
				start = end;

			}

		}
		else {
			start = start + 1;
		}
	}
}












