#include <array>
#include <iostream>

int* MultiOther(int* arr, int len)
{
	int* left = (int*)malloc(sizeof(int) * len);
	int* right = (int*)malloc(sizeof(int) * len);
	int* newArr = (int*)malloc(sizeof(int) * len);

	left[0] = 1;
	right[len - 1] = 1;

	for (int i = 1; i < len; i++)
	{
		left[i] = arr[i - 1] * left[i - 1];
	}
	for (int i = len - 2; i >= 0; i--)
	{
		right[i] = arr[i + 1] * right[i + 1];
	}

	for (int i = 0; i < len; i++)
	{
		newArr[i] = left[i] * right[i];
	}

	return newArr;
}

int main()
{
	int arr[] = { 5, 3, 2, 1 };
	size_t len = sizeof(arr) / sizeof(arr[0]);

	int* newArr = MultiOther(arr, len);

	for (size_t i = 0; i < len; i++)
	{
		std::cout << newArr[i] << ' ';
	}

	return 0;
}