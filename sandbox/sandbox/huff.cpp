#include "huff.h"
#include <iostream>
#include <bitset>
#include <cstddef>
#include <charconv>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>


huff::huff() : count(0)
{
}


huff::~huff()
{
	flush();
}


void huff::write()
{
	for (const auto i : bytevector_)
	{
		std::bitset<8> bb{ (unsigned long long)std::to_integer<int>(i) };
		putBit(bb);
	}
}

int huff::putBit(std::bitset<bytesize> bb)
{
	auto a = bb._Getword(0);
	auto b = bb._Getword(1);
	auto c = bb._Getword(2);
	auto d = bb._Getword(3);
	auto e = bb._Getword(4);
	auto f = bb._Getword(5);
	auto g = bb._Getword(6);
	auto h = bb._Getword(7);
	auto i = bb._Getword(8);
	std::bitset<1200> bc{ 72 };

	return 0;
}


int huff::putByte(char* byte)
{
	std::cerr << byte;
	return 0;
}

template<typename T, std::size_t N>
void huff::PrintArray(T (&)[N])
{
	std::cerr << "here comes array \n";
}

void huff::getBit()
{
	count = 0;

	while (std::cin.get(buffer[count]))
	{
		if (++count == bytesize)
		{
			std::bitset<8> char_yy(buffer, 8, '0', '1');
			std::byte bb{ (unsigned char)char_yy.to_ulong() };
			bytevector_.emplace_back(bb);
			count = 0;
			getByte(buffer);
			char* bf{ buffer };
			count = 0;
		}

	}
	if (count)
	{
		flush();
		getByte(buffer);
	}
}


template<typename T, std::size_t N>
void huff::getByte(T(&)[N])
{
	// auto a = *T;
	count = 0;
	// std::bitset<8> char_ssb(T, 8, '0', '1');
	// std::byte bb{ (unsigned char)T.to_ulong() };
	// bytevector_.emplace_back(bb);

	// for (int i = 0; i < bytesize; ++i)
		// std::cerr << buffer[i];
	// bytevector_.emplace_back();
}


int huff::flush()
{
	if (count = 0)
	{
		while (count != bytesize)
		{
			buffer[count] = '0';
			++count;
		}
	}
	while (count != bytesize) buffer[count++] = '0';
	count = 0;
	return count;
}


//void printsplats(int v, int max)
//{
//	int j = (v * 50) / max + ((((v * 50) < 0) ^ (max > 0)) && ((v * 50)%max));
//	for (int i = 0; i < j; ++i)
//		std::cerr << "/";
//}
//
//void printmapgraph(std::map<char, int> m)
//{
//	using pair_type = decltype(m)::value_type;
//	auto x = std::max_element(m.begin(), m.end(),
//		[](const pair_type & p1, const pair_type & p2) {
//		return p1.second < p2.second; });
//	auto max = x->second;
//	for (const auto& kv : m)
//	{
//		std::cerr << "(" << (int)kv.first << ")" << " " << kv.first;
//		std::cerr << ": ";
//		printsplats(kv.second, max);
//		std::cerr << std::endl;
//	}
//}


//int main()
//{
//
//	huff h;
//	h.getBit();
//
//	// h.write();
//	char ch[]{ "" };
//
//	// std::cerr << charcount;
//	// ch[1] = 0;
//	std::map <char, int> m1;
//	std::ifstream file("pg20197.txt");
//	std::istreambuf_iterator<char> end;
//	for (std::istreambuf_iterator<char> loop(file); loop != end; ++loop)
//	{
//		++m1[*loop]; // prefer prefix increment out of habbit
//	}
//	printmapgraph(m1);
//	return 0;
//}