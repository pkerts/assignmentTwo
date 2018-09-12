#include "Heap.h"
#include "HuffmanTree.h"
#include "HuffMap.h"
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <memory>

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
	HeapNode n { priority, data };
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
typename Heap<Priority, Data>::HeapNode Heap<Priority, Data>::pop()
{
	assert(!veep_.empty());
	HeapNode front = { veep_[0] };
	veep_.erase(veep_.begin());
	HeapSort();
	return front;
}


void HuffmanTree::add(int priority, unsigned char data)
{
	if (!root_)
	{
		root_ = std::make_unique<TreeNode>(priority, data);
	}
	else
	{
		addhelper(root_, priority, data);
	}
}


int HuffmanTree::addhelper(std::unique_ptr<TreeNode> const &ptr, int priority, unsigned char data)
{
	return 0;
}

int HuffMap::mapmaker(std::string filename)
{
	std::ifstream file(filename); // Input file
	if (file.good())
	{
		std::istreambuf_iterator<char> end; // Iterator
		for (std::istreambuf_iterator<char> loop(file); loop != end; ++loop)
		{
			++m1[*loop]; // prefer prefix increment out of habbit
		}
	}
	else
	{
		std::cerr << "File could not be opened" << std::endl;
		return 0;
	}
	if (m1.size() > 0)
	{
		return 1;
	}
	std::cerr << "File was opened but either file is empty or could not be parsed" << std::endl;
	return 0;
}


void HuffMap::printsplats(int v, int max)
{
	int j = (v * 50) / max + ((((v * 50) < 0) ^ (max > 0)) && ((v * 50) % max));
	for (int i = 0; i < j; ++i)
		std::cerr << "/";
}


void HuffMap::printmapgraph(std::string filename)
{
	if (mapmaker(filename))
	{
		using pair_type = decltype(m1)::value_type;
		auto x = std::max_element(m1.begin(), m1.end(),
			[](const pair_type & p1, const pair_type & p2) {
			return p1.second < p2.second; });
		auto max = x->second;
		for (const auto& kv : m1)
		{
			std::cerr << "(" << std::hex << std::uppercase << std::showbase << (int)kv.first << ")";
			if (isprint(kv.first))
				std::cerr << " " << kv.first;
			std::cerr << ": ";
			printsplats(kv.second, max);
			std::cerr << std::endl;
		}
	}
}


int main()
{
	Heap<unsigned int, unsigned char> h;

	HuffMap hm;
	hm.printmapgraph("pg20197.txt");

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

	HuffmanTree ht;
	unsigned char b = 'b';
	ht.add(100, b);

	auto f = h.pop();
	std::cout << f.priority_ << " " << f.data_;

	h.HeapSort();

	unsigned char yup = '\n';
	if (isprint(yup))
		std::cout << yup;

 	return 0;
}