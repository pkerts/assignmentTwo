#pragma once
#include <vector>
#include <bitset>

class huff
{
private:
	static const int bytesize = CHAR_BIT;
	char buffer[bytesize];
	int count;
public:
	huff();
	~huff();

	int putBit(unsigned int bit);
	int putByte(unsigned char byte);
	void getBit();
	void getByte(char* buffer);
	int flush();
	void write();
};

