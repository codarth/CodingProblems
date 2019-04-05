/*
You run an e-commerce website and want to record the last N order 
ids in a log. Implement a data structure to accomplish this, with 
the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is 
guaranteed to be smaller than or equal to N.

You should be as efficient with time and space as possible.
*/

#include <unordered_set>
#include <iostream>

class LogDataStructure
{
public:
	void Record(int orderID);

	int GetLast(int i);

private:
	std::unordered_set<int> log;
};

void LogDataStructure::Record(int orderID)
{
	log.insert(orderID);
}

int LogDataStructure::GetLast(int i)
{
	std::unordered_set<int>::const_iterator r = log.find(i);

	if (r == log.end()) return -1;
	return *r;
}



int main()
{
	LogDataStructure Log;

	Log.Record(101);
	Log.Record(22561461);

	std::cout << Log.GetLast(101) << std::endl;
	std::cout << Log.GetLast(102) << std::endl;
	std::cout << Log.GetLast(22561461) << std::endl;

	return 0;
}