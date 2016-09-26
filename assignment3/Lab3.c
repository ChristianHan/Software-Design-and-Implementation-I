#include <stdio.h>




/*
 * return 1 if the ASCII interpretation of 
 * c is an upper case letter.  
 * return 0 otherwise
 */
int isUpperCase(char c) {
	if (c >= 'A' && c <= 'Z') {
		return 1; 
	} else {
		return 0; 
	}
}

/*
 * return 1 if the ASCII interpretation of
 * c is a lower case letter.
 * return 0 otherwise
 */
int isLowerCase(char c) {
	if (c >= 'a' && c <= 'z') {
		return 1;
	} else {
		return 0;
	}
}

/*
 * return 1 c is an Alphabet.  
 * return 0 otherwise
 */
int isAlphabet(char c){
	return isUpperCase(c) || isLowerCase(c);
}

/*
 * if the ASCII interpretation of c is a letter, then
 * return a number between 0 and 25 indicating which letter of 
 * the alphabet c represents.  For example, if c is the ASCII
 * encoding for 'A', then we should return 0.  If c is the
 * ASCII encoding for 'e', then we should return 4.
 * if the ASCII interpretation of c is not a letter, then
 * return -1.
 */
int ASCII2Int(char c) {
	if (isUpperCase(c)) {
		return c - 'A';
	} else if (isLowerCase(c)) {
		return c - 'a';
	} else { 
		return -1;
	}
}

/*
* assumes i is between 0 and 25 inclusive
*/
char int2UpperCase(int i){
	char c = 'A'+i;
	return c;
}

/*
* assumes i is between 0 and 25 inclusive
*/
char int2LowerCase(int i){
	char c = 'a'+i;
	return c;
}

/*
* This function takes in a message and computes the frequencies of all the alphabets
*/
void buildHistogram(char message[], int messageLength, int arrayHistogram[]) // do really need to pass these two arguments ?
{
	int result;
	int i = 0; // i used for indexing
			
	while (i < messageLength) 
	{

		result = ASCII2Int(message[i]);
	
		if (result >= 0 && result <= 25)
			{
				arrayHistogram[result]++;
				i++;
			}
	
		else
			{
				i++;
			}
	}

	return;
}

/*
* This function computes the maximum value in an array and returns the index location\
* for which the maximum value occured
*/



/*
 * Encrypt the string s using the rotation cypher
 * Each letter in s should be shifted "shift" letters to the 
 * right.  For example, if "shift" is 2, then "a zebra" should be
 * changed to "c bgdtc".  Note that when shifting past the end
 * of the alphabet, we wrap around again to a.
 *
 * Only change the letters in s.  Do not change spaces, punctuation
 * or numbers in s.  
 * For full credit, you should keep upper case letters as 
 * upper case, and leave lower case letters as lower case.  So, if
 * s had been the string "a ZeBra", you should change s to be
 * "c BgDtc".
 */
void encrypt(char message[], int messageLength, int shift)
{
	int i = 0;// used for indexing

	while (i < messageLength)
	{
		if (isAlphabet(message[i]) == 1)
		{
			if (isUpperCase(message[i]) == 1)
			{
				message[i] = ((message[i] - 65 + shift) % 26) + 65;
			}
		
			else // (isLowerCase(message[i]) == 1)
			{
				message[i] = ((message[i] - 97 + shift) % 26) + 97;
			}	
		}
	
		i++;
	}
}
		
	/*
	 * return a number between 0 and 25 indicating which letter
	 * of the alphabet is most common in the string s
	 */
	int mostFrequentLetter(char message[], int messageLength)
	{
		
		int arrayHistogram[26] = { 0 };
		buildHistogram(message, messageLength, arrayHistogram); 
				
		int maxPosition=0;
		int index = 1;
		int maxValue;
		
		
		while (index < 26)
		{
			if (arrayHistogram[maxPosition] < arrayHistogram[index])
			{
				maxPosition = index;
				maxValue = arrayHistogram[maxPosition];
			}
			else
			{
				maxValue = arrayHistogram[maxPosition];
			}

			index = index + 1;
		}

		int a = 0; // used to index

		while (a < messageLength)
		{
			if (isAlphabet(message[a]) == 1)
			{
				int num_of_occurances = arrayHistogram[ASCII2Int(message[a])];
					if (num_of_occurances == maxValue)
					{
						maxPosition = ASCII2Int(message[a]);
						break;
					}
			}
				a = a + 1;
		}

		return maxPosition;
	}

			
	/*
	* Build the histogram and get the index of most frequent alphabet
	*/


	void decrypt(char cypher[], int cypherLength, int common)
	{
		int encryption = mostFrequentLetter(cypher, cypherLength);
		int shift = encryption - common;

		int i = 0; // i used for indexing
		while (i < cypherLength)
		{

			if (isAlphabet(cypher[i]) == 1)
			{
				if (isUpperCase(cypher[i]) == 1)
				{
					cypher[i] = ((cypher[i] - 65 - shift + 26) % 26) + 65;
				}

				else // (isLowerCase(message[i]) == 1)
				{
					cypher[i] = ((cypher[i] - 97 - shift + 26) % 26) + 97;
				}
			}

			i++;
		}
	}

	




