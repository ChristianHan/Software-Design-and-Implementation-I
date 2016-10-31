#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>



//Initialize the starting point of the array
void init_heap(char heap[]){ 
	
	int64_t* start = (int64_t*) &heap[0];
	int64_t* end = (int64_t*) &heap[9992];

	*start = 2496;
	*end = 2496;

}

//Allocate requested memory
char *my_malloc(char heap[], int numbytes) {
	printf("My malloc called\n");

	int64_t* start;
	int64_t* top;
	int64_t* end;

	int *p = (int64_t*)&heap[9992];

	end = (int64_t*)&heap[9992];

	int numwords;
	int actualbytes;

	if ((numbytes % 4) == 0) {
		numwords = (numbytes / 4);
	}

	else {
		numwords = (numbytes / 4);
		numwords = numwords + 1;
	}

	actualbytes = numwords * 4; //used to figure out how many bytes ACTUALLY need to be allocated.
	int num_subtract = (actualbytes + 8) / 8;


	while ((*end) < 0) {

		if (((*end) % 2) != 0) {
			float oddnum_subtract = (((float)abs((*end)) * 4) + 8.0) / 8.0;
			end = end - (int)(oddnum_subtract * 2.0);
			end = end - 2;
			p = (int*)end;
		}
		else {
			int subtract = ((abs((*end)) * 4) + 8) / 8;
			end = end - subtract;
			end = end - 1;
			p = (int*)end;
		}
	}

	if (((*end) > 0) && (((*end) - (numwords + 5)) >= 0)) { // (split case)

		int split_word = ((*end) - numwords - 4);

		*end = -numwords;

		if ((numwords % 2) != 0) {
			float oddnum_subtract = ((float)actualbytes + 8.0) / 8.0;
			p = p - (int)(oddnum_subtract * 2.0);

			int64_t *ptr = (int64_t *)p;
			*ptr = -numwords;

			p = p - 2;
			*p = split_word;
			p = p + 4;
			char* temp = (char *)p;
			p = p - split_word - 6;
			*p = split_word;
			return temp;

		}
		else {
			end = end - num_subtract;
			*end = -numwords;
			end = end - 1;
			*end = split_word;
			end = end + 2;
			int64_t* temp2 = end;
			end = end - split_word - 2;
			*end = split_word;
			return (char*)temp2;
		}

	}

	if (((*end) > 0) && (((*end) - (numwords + 5)) < 0)) { //return pointer case (n - (n+4))

		*end = -(*end);

		if (((*end) % 2) != 0) {
			float oddnum_subtract = (((float)abs((*end)) * 4) + 8.0) / 8.0;
			p = p - (int)(oddnum_subtract * 2.0);
			*p = -(*p);
			p = p + 2;
			return (char*)p;
		}
		else {
			int64_t subtract = ((abs((*end)) * 4) + 8) / 8;
			end = end - subtract;
			*end = -(*end);
			end = end + 1;
			return (char*)end;
		}

	}

	if (((*end) > 0) && (numwords > (*end))) {

		printf("Sorry nothing is available!\n");
		return NULL;
	}
}
//Deallocate requested memory
void my_free(char slab[], char *p) {

	p = p - 8;
	int64_t* t = (int64_t*)p;
	int64_t words = *t;

	*t = words * (-1);

	p = p + 8 + (4 * words * (-1));
	t = (int64_t*)p;
	*t = words * (-1);
	

}
