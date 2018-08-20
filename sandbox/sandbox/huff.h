#pragma once
#include <vector>
#include <bitset>
#include <cstddef>

class huff
{
private:
	static const int bytesize = CHAR_BIT;
	char buffer[bytesize] = {0};
	std::vector<std::byte> bytevector_;
	char buffertwo[bytesize];
	int count;
public:
	huff();
	~huff();

	int putBit(unsigned int bit);
	int putByte(char* byte);
	void getBit();
	void getByte(char* buffer);
	int flush();
	int flushtwo();
	void write();
	void get();
	void print(const unsigned long *const v);
	void AddToVector(std::byte b);
};

