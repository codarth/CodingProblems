#include <iostream>

int* FindSmallerToRight(int* arr, int len)
{
	int count = 0;

	std::cout << "len: " << len << "\n";

	int* result = new int[len];

	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[i])
			{
				count++;
			}
		}
		result[i] = count;
		count = 0;
	}

	return result;
}

int main()
{
	int arr[] = { 3, 4, 9, 6, 1, };
	int len = sizeof(arr) / sizeof(arr[0]);

	int* result = FindSmallerToRight(arr, len);
	for (int i = 0; i < len; i++)
		std::cout << result[i];


	return 0;
}