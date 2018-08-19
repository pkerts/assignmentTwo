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
	flush();
}


int huff::putBit(unsigned int bit)
{
	buffer[count] = bit;
	if (++count == bytesize)
	{
		putByte(reinterpret_cast<unsigned char>(buffer));
		count = 0;
		return count;
	}
}


int huff::putByte(unsigned char byte)
{
	std::cout << byte;
	return flush();
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
	for (int i = bytesize - 1; i >= 0; --i)
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
	
	std::bitset<8> charry{ 0b00011000 };
	std::cout << charry.to_ulong();

	// h.write();

	return 0;
}