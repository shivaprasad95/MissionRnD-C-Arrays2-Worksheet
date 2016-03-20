/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

int isEqual(char *dob1, char *dob2);


#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	struct transaction *array;
	array = (struct transaction *)malloc(4*sizeof(struct transaction));
	int count = 0, temp,k=0;

	if (A == NULL || B == NULL) //to check if A or B is NULL
		return NULL;


	for (int i = 0; i < ALen; i++) {
		for (int j = i; j < BLen; j++) {

			temp = isEqual(A[i].date, B[j].date);   //returns 1 if dates are equal , -1 if date is invalid

			if (temp == 1) {
				array[k++] = A[i];
				count++;

			}
			
			if (temp == -1)
				return NULL;
		}
	}

	if (count == 0) //if no common date found,return NULL
		return NULL;

	return array;

}

int isEqual(char *dob1, char *dob2)
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
	if (a == x&&b == y&&c == z)
		return 1;
	else
		return 0;
}