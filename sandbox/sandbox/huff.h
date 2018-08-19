#pragma once
#include <vector>
#include <bitset>

class huff
{
private:
	static const int bytesize = CHAR_BIT;
	char buffer[bytesize];
	std::bitset<bytesize> buffers;
	std::vector<std::byte> bytevector_;
	int count;
public:
	huff();
	~huff();

	int putBit(unsigned int bit);
	int putByte(unsigned char byte);
	void getBit();
	void getByte(char* buffer);
	void flush();
	void write();
};

