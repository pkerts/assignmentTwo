#include "Heap.h"
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <cctype>

const int NUM_SECONDS = 5;

template<typename Priority, typename Data>
Heap<Priority, Data>::Heap()
{
}

template<typename Priority, typename Data>
Heap<Priority, Data>::~Heap()
{
}





template<typename Priority, typename Data>
void Heap<Priority, Data>::push(Priority priority, Data data)
{
	Node n = { priority, data };
	veep_.emplace_back(n);
}

//template<typename Priority, typename Data>
//typename Heap<Priority, Data>::Node* Heap<Priority, Data>::pop()
//{
//	return nullptr;
//}

template<typename Priority, typename Data>
bool Heap<Priority, Data>::is_empty()
{
	return veep_.empty();
}


template<typename Priority, typename Data>
void Heap<Priority, Data>::maximum()
{
	std::cout << veep_.max_size();
}


void printsplats(int v, int max)
{
	int j = (v * 50) / max + ((((v * 50) < 0) ^ (max > 0)) && ((v * 50) % max));
	for (int i = 0; i < j; ++i)
		std::cerr << "/";
}


void printmapgraph(std::map<char, int> m)
{
	using pair_type = decltype(m)::value_type;
	auto x = std::max_element(m.begin(), m.end(),
		[](const pair_type & p1, const pair_type & p2) {
		return p1.second < p2.second; });
	auto max = x->second;
	for (const auto& kv : m)
	{
		std::cerr << "(" << std::hex << std::uppercase << std::showbase << (int)kv.first << ")"; 
		if (isprint(kv.first))
			std::cerr << " " << kv.first;
		std::cerr << ": ";
		printsplats(kv.second, max);
		std::cerr << std::endl;
	}
}


int main()
{
	Heap<int, unsigned char> h;

	std::map <char, int> m1; // Create map
	std::ifstream file("pg20197.txt"); // Input file
	std::istreambuf_iterator<char> end; // Iterator
	for (std::istreambuf_iterator<char> loop(file); loop != end; ++loop)
	{
		++m1[*loop]; // prefer prefix increment out of habbit
	}
	printmapgraph(m1);

	unsigned char yup = '\n';
	if (isprint(yup))
		std::cout << yup;

 	return 0;
}