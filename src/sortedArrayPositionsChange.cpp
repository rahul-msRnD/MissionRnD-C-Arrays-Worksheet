/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len <= 0)return NULL;
	int i = len - 1;
	while (i > 0)
	{
		if (Arr[i] < Arr[i - 1])
		{
			int j = i - 1;
			while (j >= 0 && Arr[i] < Arr[j])
				j--;
			swap(&Arr[i], &Arr[j + 1]);
			break;
		}
		i--;
	}
}