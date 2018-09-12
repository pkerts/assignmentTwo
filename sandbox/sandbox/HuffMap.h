#pragma once
#include <map>

class HuffMap
{
private:
	std::map<char, int> m1;
public:
	int mapmaker(std::string filename);
	void printsplats(int v, int max);
	void printmapgraph(std::string filename);
};