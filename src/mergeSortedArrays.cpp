/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
int isOlder1(char *dob1, char *dob2);


#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	if (A == NULL || B == NULL) //if A or B is NULL, return NULL
		return NULL;

	struct transaction *array;
	array = (struct transaction *)malloc((ALen+BLen)* sizeof(struct transaction));
	int m, n, i = 0, j = 0, k = 0;

	while (i < ALen && j < BLen)
	{
		if (isOlder1(A[i].date, B[j].date) == 1) //if A date is elder than B
		{
			array[k] = A[i]; //insert A date
			i++;
		}
		else
		{
			array[k] = B[j]; //if B date is elder than A insert B
			j++;
		}
		k++;
	}
	if (i >= ALen)
	{
		while (j < BLen)
		{
			array[k] = B[j];  //insert remaining dates of B
			j++;
			k++;
		}
	}
	if (j >= BLen)
	{
		while (i < ALen)
		{
			array[k] = A[i]; //insert remaining dates of A
			i++;
			k++;
		}
	}
	return array;
}

int isOlder1(char *dob1, char *dob2)
{
	int d1, m1, y1;
	int d2, m2, y2, y3, y4;
	int i, a, b, c, x, y, z, leap;

	d1 = (int)(dob1[0]) - '0';
	d2 = (int)(dob1[1]) - '0';
	a = d1 * 10 + d2;

	m1 = (int)(dob1[3]) - '0';
	m2 = (int)(dob1[4]) - '0';
	b = m1 * 10 + m2;

	y1 = (int)(dob1[6]) - '0';
	y2 = (int)(dob1[7]) - '0';
	y3 = (int)(dob1[8]) - '0';
	y4 = (int)(dob1[9]) - '0';
	c = y1 * 1000 + y2 * 100 + y3 * 10 + y4;

	// day,month,year of date1 are stored in a,b,c respectively.

	//date validation
	if (a <= 0 || a>31 || b <= 0 || b>12 || c <= 0)
		return -1;
	if (c % 400 == 0)
		leap = 1;
	else if (c % 100 == 0)
		leap = 0;
	else if (c % 4 == 0)
		leap = 1;
	else
		leap = 0;

	if (leap == 0 && b == 2 && a > 28)
		return -1;
	if (leap == 1 && b == 2 && a>29)
		return -1;

	if (b % 2 == 0)
	if (a > 30)
		return -1;


	d1 = (int)(dob2[0]) - '0';
	d2 = (int)(dob2[1]) - '0';
	x = d1 * 10 + d2;

	m1 = (int)(dob2[3]) - '0';
	m2 = (int)(dob2[4]) - '0';
	y = m1 * 10 + m2;

	y1 = (int)(dob2[6]) - '0';
	y2 = (int)(dob2[7]) - '0';
	y3 = (int)(dob2[8]) - '0';
	y4 = (int)(dob2[9]) - '0';
	z = y1 * 1000 + y2 * 100 + y3 * 10 + y4;
	// day,month,year of date2 are stored in x,y,z respectively.

	//date validation
	if (x <= 0 || x>31 || y <= 0 || y>12 || z <= 0)
		return -1;
	if (z % 400 == 0)
		leap = 1;
	else if (z % 100 == 0)
		leap = 0;
	else if (z % 4 == 0)
		leap = 1;
	else
		leap = 0;

	if (leap == 0 && y == 2 && x > 28)
		return -1;
	if (leap == 1 && y == 2 && x>29)
		return -1;

	if (y % 2 == 0)
	if (x > 30)
		return -1;


	//date comparision
	if (c>z)
		return 2;
	else if (c<z)
		return 1;
	else if (b>y)
		return 2;
	else if (b<y)
		return 1;
	else if (a>x)
		return 2;
	else if (a<x)
		return 1;
	else
		return 0;
}