/*
Given an array of integers, find the first missing 
positive integer in linear time and constant space.
In other words, find the lowest positive integer 
that does not exist in the array.The array can 
contain duplicates and negative numbers as well.

For example, 
the input[3, 4, -1, 1] should give 2. 
The input[1, 2, 0] should give 3.

You can modify the input array in - place.
*/
#include <iostream>
#include <unordered_map>

int MissingPositive(int* arr, int size) // Find a way to do it with out the map
{
	int largestNum = INT_MIN;


	///Find the largest number
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > largestNum)
		{
			largestNum = arr[i];
		}
	}
	/// if all elements are negative
	if (largestNum < 1) return 1;


	/// if only one element in arr
	if (size == 1)
	{
		if (arr[0] == 1) // if element is 1
			return 2;
		else
			return 1;
	}

	std::unordered_map<int, int> map;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0) // positive only
		{
			map.emplace(arr[i], i);
		}
	}

	for (int i = 1; i < size; i++)
	{
		std::unordered_map<int, int>::const_iterator num = map.find(i);
		if (num == map.end())
		{
			return i;
		}
	}

	return largestNum + 1;
}

int main()
{
	int arr[] = { 3,4,-1,1,2,6,2,-5};
	int missing = MissingPositive(arr, sizeof(arr) / sizeof(arr[0]));
	std::cout << "Missing number: " << missing << "\n";



	return 0;
}