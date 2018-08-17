#include "huff.h"
#include <iostream>
#include <bitset>
#include <cstddef>
#include <charconv>


const size_t bitsetsize_ = 8;


/* Failed method *//*
  tried to get bitset to accept a parameter to determine how many bits we get returned
  It did not work, bitset wants a const number at compile-time

/*template<typename T>
void binaryof(size_t how_many_bits, T t)
{
	std::bitset<how_many_bits> a(t);
	std::cout << a << std::endl;
}*/


template<typename T>
void binaryof(T t) {
	auto a = std::bitset<bitsetsize_>(t);
	std::cout << a << std::endl;
}


int byteToInt(unsigned char binary_literal)
{
	std::byte myByte{ binary_literal }; // making an std::byte and initializing with binary literal parameter
	return std::to_integer<int>(myByte); // return actual integer value of bin literal provided
}


char byteToChar(unsigned char binary_literal)
{
	std::byte myByte{ binary_literal };
	return std::to_integer<unsigned char>(myByte);
}

// Adapted from Marc Gregoire's blog post on C++17: std::byte
void PrintByte(const std::byte& aByte)
{
	std::cout << std::to_integer<int>(aByte) << std::endl;
}


huff::huff()
{
}


huff::~huff()
{
}


int huff::putBit(unsigned int bit)
{
	return 1;
}


int huff::putByte(unsigned char byte)
{
	return 1;
}


int main()
{
	std::byte myByte{ 00000010 }; // making an std::byte and initializing with bin rep of 2
	std::cout << std::to_integer<int>(myByte) << std::endl; // output is 8

	std::byte myByteTwo{ 0b00000010 }; // making an std::byte and initializing with bin rep of 2 using binary literal
	std::cout << std::to_integer<int>(myByteTwo) << std::endl; // output is 2!

	binaryof(8); // using 8 bits output is 00001000

	// std::byte myByteTwo{ 00001000 }; // making an std::byte and initializing with bin rep of 8
	// COMPILE ERROR (narrowing conversion from 'int' to 'unsigned char')
	// std::cout << std::to_integer<int>(myByteTwo) << std::endl; // compile error. 

	binaryof(1048576); // using 32 bits output is 00000000000100000000000000000000

	std::cout << byteToInt(0b00000010) << std::endl; // output is 2
	std::cout << byteToInt(0b11111111) << std::endl; // output is 255
	std::cout << byteToInt(0b10000000) << std::endl; // output is 

	myByteTwo <<= 2; // A 2-bit left shift
	PrintByte(myByteTwo); // output is 8

	std::byte myByteThree{ 50 };
	PrintByte(myByteThree); // output is 50
	binaryof(50); // output is 00110010

	binaryof('a'); // output is 01100001
	unsigned char a = 'a';
	std::cout << "char a is set to: " << a << std::endl; // output is a
	std::cout << "incrementing a" << std::endl;
	++a;
	std::cout << "char a is now: " << a << std::endl; // output is b

	for (int i = 0; i < 28; ++i)
	{
		char ch = 'a';
		binaryof(ch += i);
	}

	std::cout << byteToChar(0b01100001) << std::endl;
	binaryof(97); // output is 01100001


	std::byte myByteFour{ 0b00000010 }; // making an std::byte and initializing with bin rep of 2 using binary literal
	std::cout << std::to_integer<int>(myByteFour) << std::endl; // output is 2!

	return 0;
}