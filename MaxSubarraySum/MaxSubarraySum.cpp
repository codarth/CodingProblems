#include <iostream>
#include <algorithm>

/*
// O(n^2) 
void FindMaxSubarraySum(int* arr, int len)
{
	int startIndex = 0, endIndex = 0;
	int largestSeen = -999999;
	int currentSum = 0;

	for (int i = startIndex; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			currentSum += arr[j];
			//std::cout << currentSum << " ";
			largestSeen = std::max(currentSum, largestSeen);
			if (currentSum == largestSeen)
			{
				startIndex = i;
				endIndex = j;
			}
		}
		//std::cout << "\nlargest seen: " << largestSeen << ", start: " << startIndex << " end: " << endIndex << "\n";
		currentSum = 0;
	}

	for (int i = startIndex; i <= endIndex; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << "\n";
}
*/


int FindMinSubarraySum(int* arr, int len)
{
	int smallestSeen = 0;
	int minToHere = 0;

	for (int i = 0; i < len; i++)
	{
		minToHere = std::min(arr[i], minToHere + arr[i]);
		smallestSeen = std::min(smallestSeen, minToHere);
	}

	return smallestSeen;
}

// O(n)
int FindMaxSubarraySum(int* arr, int len)
{
	int largestSeen = 0;
	int maxToHere = 0;

	for (int i = 0; i < len; i++)
	{
		maxToHere = std::max(arr[i], maxToHere + arr[i]);
		largestSeen = std::max(largestSeen, maxToHere);
	}
	
	return largestSeen;
}

// wrap Round
int WrapAroundMax(int* arr, int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}

	int arrSum = sum - FindMinSubarraySum(arr, len);

	return std::max(FindMaxSubarraySum(arr, len), arrSum);
}

int main()
{
	int arr[] = { 3, -8, 2, 4, 5, -10 }; //11
	size_t len = sizeof(arr) / sizeof(arr[0]);
	std::cout << FindMaxSubarraySum(arr, len) << "\n";  
	
	int arr2[] = { 3, 8, -2, -4, -5, 10 }; //21
	size_t len2 = sizeof(arr2) / sizeof(arr2[0]);
	std::cout << WrapAroundMax(arr2, len2) << "\n";

	return 0;
}
