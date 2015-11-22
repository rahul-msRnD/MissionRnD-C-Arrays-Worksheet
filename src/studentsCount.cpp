
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

int interpolationSearch(int array[], int size, int key) {
	int guess = 0;
	double t;
	int minIndex = 0;
	int maxIndex = size - 1;
	while (array[guess] != key || (key>array[guess - 1] && key<array[guess]))
	{
		t = ((double)key - array[minIndex]) / ((double)array[maxIndex] - array[minIndex]);
		guess = minIndex + t * (maxIndex - minIndex);
		if (array[guess] < key)
			minIndex = guess + 1;
		if (array[guess] > key)
			maxIndex = guess - 1;
		if (array[minIndex] > key || array[maxIndex] < key)
			return guess*size;
	}
	return guess;
}

void *studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount)
{
	if (Arr == NULL || len<0) return NULL;

	if (Arr[0] == Arr[len - 1])
	{
		if (len>1 || (len == 1 && score == Arr[0]))
		{
			*lessCount = 0;
			*moreCount = 0;
		}
		if (score > Arr[0])
		{
			*lessCount = 1;
			*moreCount = 0;
		}
		if (score < Arr[0])
		{
			*lessCount = 0;
			*moreCount = 1;
		}
	}
	else
	{
		int k = interpolationSearch(Arr, len, score);
		if (k < len)
		{
			*lessCount = k;
			*moreCount = len - k - 1;
		}
		else
		{
			k = k / len;
			*lessCount = k ;
			*moreCount = len - k ;
		}

	}
}
