#pragma once
#include <bitset>

template<typename T>
class binary
{
private:
	const size_t bitsetsize_ = 32;
public:
	binary();
	~binary();

	template<typename T>
	std::bitset<bitsetsize_> binaryof(int x) {
		auto a = std::bitset<8>(x);
		return a;
	}

	std::bitset<bitsetsize_> binaryof(char ch) {
		auto a = std::bitset<8>(ch);
		return a;
	}


};