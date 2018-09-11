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
	Node n { priority, data };
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




template<typename Priority, typename Data>
void Heap<Priority, Data>::HeapSort()
{
	auto i = veep_.size() - 1;
	while (i != 0)
	{
		if (veep_[i].priority_ > veep_[parent(i)].priority_)
			std::swap(veep_[i], veep_[parent(i)]);
		--i;
	}
}


template<typename Priority, typename Data>
int Heap<Priority, Data>::parent(int i)
{
	return ((i - 1) / 2);
}

template<typename Priority, typename Data>
typename Heap<Priority, Data>::Node Heap<Priority, Data>::pop()
{
	// assert(!veep_.empty());
	Node front = { veep_[0] };
	veep_.erase(veep_.begin());
	HeapSort();
	return front;
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

	/*for (const auto i : m1)
	{
		h.push(i.second, i.first);
	}*/

	int count = 100;
	for (int i = 97; i < 111; ++i)
	{
		if (i != 99)
		{
			h.push(count, (unsigned char)i);
		}
		count -= 5;
	}

	h.push(90, (unsigned char)'c');


	h.HeapSort();
	h.HeapSort();

	auto f = h.pop();
	std::cout << f.priority_ << " " << f.data_;

	h.HeapSort();

	unsigned char yup = '\n';
	if (isprint(yup))
		std::cout << yup;

 	return 0;
}