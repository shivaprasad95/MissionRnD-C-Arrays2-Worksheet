/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

int findSingleOccurenceNumber(int *A, int len) {
	
	if (A == 0)   //if A is empty return -1
		return -1;

	int i;
	int temp;
	int count = 0;

	//single for loop

	for (i = 0; i < len; i++)
	{
		if (A[i] != -99 && count == 0)  //-99 is some random negative value
			temp = A[i];

		if (A[i] == temp)
		{
			A[i] = -99;    //if a number is traversed, insert some value to not check it again
			count++;
		}
		if (count == 3)    //if count is 3 traverse the loop again
		{
			i = 0;
			count = 0;
		}
		if (count == 1 && i == len-1) //if we count the number once and reach end of loop return number
			return temp;
	}

	return temp;
}