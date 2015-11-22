/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

int qfindPivot1(struct student a[], int l, int r)
{
	int x = a[r].score, i = l, j;
	for (j = l; j<r; j++)
	{
		if (a[j].score <= x)
		{
			struct student temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
		}
	}
	struct student temp = a[i];
	a[i] = a[r];
	a[r] = temp;
	return i;
}

struct student kthLargest(struct student a[], int l, int r, int k)
{
	if (k > 0 && k <= r - l + 1)
	{
		int pos = qfindPivot1(a, l, r);
		if (pos == k - 1)
		{
			printf("%d \n", a[pos].score);
			return a[pos];
		}
		if (pos  > k - 1)
			return kthLargest(a, l, pos - 1, k);
		return kthLargest(a, pos + 1, r, k - pos + l - 1);
	}
	//return INT_MAX;
}

struct student **topKStudents(struct student *students, int len, int k) {
	if (k <= 0 || !students) return NULL;
	struct student **topKStudentS = (struct student**)malloc(k* sizeof(struct student));
	int p = 0, i, l = 0;
	if (k>len) k = len;
	struct student *temp = (struct student*)malloc(k*sizeof(struct student));
	for (i = k; i >0; i--)
	{
		temp[l] = kthLargest(students, 0, len, len - i + 1);
		printf("%d \n", temp[l].score);
		topKStudentS[p++] = &temp[l++];
	}
	return topKStudentS;
}