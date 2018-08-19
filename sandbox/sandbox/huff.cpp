#include "huff.h"
#include <iostream>
#include <bitset>
#include <cstddef>
#include <charconv>
#include <fstream>
#include <vector>


huff::huff() : count(0)
{
}


huff::~huff()
{
}


int huff::putBit(unsigned int bit)
{
	/*for (auto i : bytevector_)
	{

	}*/
	return 1;
}


int huff::putByte(unsigned char byte)
{
	for (int i = 0; i < bytesize; ++i)
	{
		putBit(byte);
	}
	return 1;
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
	}
}

void huff::getByte(char* buffer)
{
	for (int i = 0; i < bytesize; ++i)
		std::cout << buffer[i];
	// bytevector_.emplace_back();
}


void huff::write()
{
	/*for (auto i : bytevector_)
	{
		putByte(bytevector_[i]);
	}*/
	for (auto i : bytevector_)
	{
		std::cout << "hello";
	}
}

void huff::flush()
{
	
	while (count != bytesize) buffer[count++] = '0';
	getByte(buffer);
}

int main()
{

	std::byte yes{ 0b10000000 };
	// std::cout << std::bitset<8>(std::to_integer<int>(yes)) << std::endl;
	auto a = std::bitset<8>(std::to_integer<int>(yes));
	// std::cout << a[7] << std::endl;
	a[7].flip();
	// std::cout << a[7] << std::endl;
	a.set(7);
	// std::cout << a[7] << std::endl;
	a.set(7);
	// std::cout << a[7] << std::endl;
	huff h;
	h.getBit();
	
	h.write();

	return 0;
}