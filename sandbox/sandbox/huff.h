#pragma once
#include <vector>

class huff
{
private:
	static const int bytesize = sizeof(char);
	char buffer[bytesize];
	std::vector<char> bytevector_;
	int count;
public:
	huff();
	~huff();

	int putBit(unsigned int bit);
	int putByte(unsigned char byte);
	void getBit();
	void getByte(unsigned char buffer);
	void flush();
	void write();
};

