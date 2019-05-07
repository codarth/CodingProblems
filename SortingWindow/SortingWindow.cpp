/*
Daily Coding problem Book 1.2
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Given an array of integers that are out of order, determine 
the bounds of the smallest window that must be sorted in order
for the entire array to be sorted. For example, given 
[3, 7, 5, 6, 9], you should return (1, 3).
*/

#include <iostream>
#include <algorithm>

void FindSortingWindow(int* arr, int len)
{
	int left = 0, right = len;
	int maxseen = -9999999;
	int minseen = 9999999;

	// Get the right window index
	for (int i = 0; i < len; i++)
	{
		maxseen = std::max(arr[i], maxseen);
		if (arr[i] < maxseen)
		{
			right = i;
		}
	}
	
	// Get the left window index
	for (int i = len - 1; i >=0; i--)
	{
		minseen = std::min(arr[i], minseen);
		if (arr[i] > minseen)
		{
			left = i;
		}
	}

	std::cout << "(" << left << ", " << right << ")\n";
}

int main()
{
	int arr[] = { 1, 3, 7, 5, 6, 9 }; // (2, 4)
	size_t len = sizeof(arr) / sizeof(arr[0]);

	FindSortingWindow(arr, len);

	return 0;
}