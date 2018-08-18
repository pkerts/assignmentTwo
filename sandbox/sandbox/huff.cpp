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
	for (auto i : bytevector_)
	{

	}
}


int huff::putByte(unsigned char byte)
{
	
	for (int i = 0; i < bytesize; ++i)
	{
		buffer[i] = 
	}
}

void huff::getBit()
{
	count = 0;

	while (std::cin.get(buffer[count]))
	{
		if (++count == bytesize)
		{
			getByte(*buffer);
			count = 0;
		}

		if (count)
		{
			flush();
		}
	}
}

void huff::getByte(unsigned char buffer)
{
	bytevector_.emplace_back(buffer);
}


void huff::write()
{
	for (auto i : bytevector_)
	{
		putByte(bytevector_[i]);
	}
}

void huff::flush()
{
	
	while (count != bytesize) buffer[count++] = '0';
	getByte(*buffer);
}

int main()
{
	huff h;
	h.getBit();
	

	return 0;
}