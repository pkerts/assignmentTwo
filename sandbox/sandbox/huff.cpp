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
			std::bitset<8> char_yy(buffer, 8, '0', '1');
			std::cerr << (char)char_yy.to_ulong();
			std::cerr << (int)char_yy.to_ulong();
			std::byte bb{ (unsigned char)char_yy.to_ulong() };
			std::cerr << "heres byte bb: " << (int)bb << std::endl;
			std::byte b{ 'H' };
			std::cerr << "here's byte b: " << (char)b << std::endl;
			std::byte c{ 0b01001000 };
			std::cerr << "here's byte c: " << (char)c << std::endl;
			std::cerr << buffer << std::flush << std::endl;
			// bytevector_.emplace_back((std::byte)buffer);
			// print(inptr);
			// std::cerr << buffer << std::endl;
			// getByte(buffer);
			/*for (int i = 0; i < bytesize; ++i)
				std::cout << (buffer[i]);*/
			// std::bitset<8> butthead{buffer};
			// unsigned long i = butthead.to_ulong();
			// unsigned char c = static_cast<unsigned char>(i);
			// std::cout << c;
			count = 0;
		}

	}
	if (count)
	{
		flush();
		std::bitset<8> char_yy(buffer, 8, '0', '1');
		std::cout << (char)char_yy.to_ulong() << std::endl;
		/*for (int i = 0; i < bytesize; ++i)
			std::cout << (buffer[i]);*/
		// std::bitset<8> beavis{buffer};
		// unsigned long f = beavis.to_ulong();
		// unsigned char j = static_cast<unsigned char>(f);
		// std::cout << j;
		// getByte(buffer);
	}
}

//void huff::print(const unsigned long *const v)
//{
//	long yup = v[0];
//	long yes = v[1];
//	unsigned long ok = 0x30;
//	char c = 0xFF;
//	std::bitset<8> char_bs(yup); // templated argument is the size in bits
//	std::bitset<8> char_ss(yes);
//	std::bitset<8> char_yy(buffer, 8, '0', '1');
//	std::cerr << (char)char_yy.to_ulong() << std::endl;
//	std::cerr << char_bs.to_string() << std::endl;
//	std::cerr << char_ss.to_string() << std::endl;
//	std::cerr << "inptr: " << *v << std::endl;
//}

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

void huff::AddToVector(std::byte b)
{
	bytevector_.emplace_back(b);
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
	huff h;
	h.getBit();
	
	/*std::bitset<8> bitter{ 0b01001000 };
	unsigned long f = bitter.to_ulong();
	std::cout << f << std::endl;
	unsigned char j = static_cast<unsigned char>(f);
	std::cout << "here's j: " << j << std::endl;*/

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