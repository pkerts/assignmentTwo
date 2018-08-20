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


int huff::putBit(unsigned int bit)
{
	buffertwo[count] = bit;
	if (++count == bytesize)
	{
		putByte(buffertwo);
		count = 0;
		return count;
	}
}


int huff::putByte(char* byte)
{
	std::cout << byte;
	return flushtwo();
}

void huff::getBit()
{
	count = 0;

	while (std::cin.get(buffer[count]))
	{
		if (++count == bytesize)
		{
			getByte(buffer);
			count = 0;
		}

	}
	if (count)
	{
		flush();
		getByte(buffer);
	}
}

void huff::getByte(char* buff)
{
	count = 0;
	for (int i = 0; i < bytesize; ++i)
		putBit(buff[i]);

	// for (int i = 0; i < bytesize; ++i)
		// std::cout << buffer[i];
	// bytevector_.emplace_back();
}

//
//void huff::write()
//{
//	/*for (auto i : bytevector_)
//	{
//		putByte(bytevector_[i]);
//	}*/
//	for (auto i : bytevector_)
//	{
//		std::cout << "hello";
//	}
//}

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

int huff::flushtwo()
{
	if (count = 0)
	{
		while (count != bytesize)
		{
			buffertwo[count] = '0';
			++count;
		}
	}
	while (count != bytesize) buffertwo[count++] = '0';
	count = 0;
	return count;
}

void printsplats(int v, int max)
{
	int j = (v * 50) / max + ((((v * 50) < 0) ^ (max > 0)) && ((v * 50)%max));
	for (int i = 0; i < j; ++i)
		std::cout << "/";
}

void printmapgraph(std::map<char, int> m)
{
	using pair_type = decltype(m)::value_type;
	auto x = std::max_element(m.begin(), m.end(),
		[](const pair_type & p1, const pair_type & p2) {
		return p1.second < p2.second; });
	auto max = x->second;
	for (const auto& [ k, v ] : m)
	{
		std::cout << k << ": ";
		printsplats(v, max);
		std::cout << std::endl;
	}
}

int main()
{

	// std::byte yes{ 0b10000000 };
	// std::cout << std::bitset<8>(std::to_integer<int>(yes)) << std::endl;
	// auto a = std::bitset<8>(std::to_integer<int>(yes));
	// std::cout << a[7] << std::endl;
	// a[7].flip();
	// std::cout << a[7] << std::endl;
	// a.set(7);
	// std::cout << a[7] << std::endl;
	// a.set(7);
	// std::cout << a[7] << std::endl;
	// huff h;
	// h.getBit();
	
	// std::bitset<8> charry{ 0b00011000 };
	// std::cout << charry.to_ulong();

	// h.write();

	std::map <char, int> m1;
	std::ifstream file("pg20197.txt");
	std::istreambuf_iterator<char> end;

	for (std::istreambuf_iterator<char> loop(file); loop != end; ++loop)
	{
		++m1[*loop]; // prefer prefix increment out of habbit
	}

	printmapgraph(m1);

	return 0;
}