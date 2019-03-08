#include <map>
#include <array>
#include <iostream>

////Brute Force
//bool AddsToK(std::array<int, 4> list, int k)
//{
//	for (int i = 0; i < list.size(); i++)
//	{
//		//std::cout <<std::endl<< list[i] << std::endl;;
//		for (int j = i+1; j < list.size(); j++)
//		{
//			//std::cout << list[j]<<", ";
//			if (list[i] + list[j] == k)
//				return true;
//		}
//	}
//	return false;
//}

// Optimal
bool AddsToK(std::array<int, 4> list, int k)
{
	std::map<int, int>table;
	table[list[0]] = k - list[0];

	for (int i = 1; i < list.size(); i++)
	{
		std::map<int, int>::iterator it = table.find(k - list[i]);
		if (it != table.end())
			return true;
		table[list[i]] = k - list[i];
	}
	return false;
}

int main()
{
	std::array<int, 4> list{ 10,15,3,7 }; // true
	//std::array<int, 4> list{ 3,11,18,7 };	// false
	int k = 17;
	auto size = list.size();

	AddsToK(list, k) ? std::cout << "\ntrue\n" : std::cout << "\nfalse\n";

	return 0;
}