#include <stdio.h>


void parenthesis(int position, int n, int start, int end);

void generateAllMatchedParens(int n) {
	if (n > 0) {
		parenthesis(0, n, 0, 0);
	}
	return;
}

void parenthesis(int position, int n, int start, int end)
	{
		static char string[10000];

		if (end == n)
		{
			printf("%s \n", string);
			return;
		}
		else
		{
			if (start > end) {
				string[position] = ')';
				parenthesis(position + 1, n, start, end + 1);
			}
			if (start < n) {
				string[position] = '(';
				parenthesis(position + 1, n, start + 1, end);
			}
		}
	}

	//Function needs to generate all matched parens as described in the assignment

void generateAllPalindromicDecompositions(char str[]){
	
}


