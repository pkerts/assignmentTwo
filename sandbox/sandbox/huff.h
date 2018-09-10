#pragma once
#include <vector>
#include <bitset>
#include <cstddef>


class huff
{
private:
	static const std::size_t bytesize = CHAR_BIT;
	constexpr int bytesizetwo();
	char buffer[8];
	std::vector<std::byte> bytevector_;
	char buffertwo[bytesize];
	int count;
	// std::bitset<>* bac;
public:
	huff();
	~huff();

	int putBit(std::bitset<bytesize> bb);
	int putByte(char* byte);
	void getBit();

	template<typename T, std::size_t N>
	void getByte(T(&)[N]);

	int flush();
	void write();

	template<typename T, std::size_t N>
	void PrintArray(T(&)[N]);
};

