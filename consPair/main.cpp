/*
cons(a, b) constructs a pair, and car(pair) and cdr(pair) 
returns the first and last element of that pair. For example, 
car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
	def pair(f):
		return f(a, b)
	return pair
Implement car and cdr.

///////////////
Not sure is this is what is wanted, but here is my solution
*/
#include <utility>
#include <iostream>

std::pair<int,int> cons(int a, int b)
{
	std::pair<int, int> p;
	p.first = a;
	p.second = b;

	return p;
}

int car(std::pair<int, int> p)
{
	return p.first;
}

int cdr(std::pair<int, int> p)
{
	return p.second;
}

int main()
{
	std::pair<int, int> p = cons(3, 4);

	std::cout << car(p) << std::endl;
	std::cout << cdr(p) << std::endl;

	return 0;
}