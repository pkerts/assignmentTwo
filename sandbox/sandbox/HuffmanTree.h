#pragma once
#include <memory>
#include <vector>


class HuffmanTree
{
private:
	struct TreeNode {
		int priority_;
		unsigned char data_;
		TreeNode(int priority, unsigned char data) :priority_(priority), data_(data) {}
	};
	std::unique_ptr<TreeNode> root_;
	std::unique_ptr<int> hey;
	int addhelper(std::unique_ptr<TreeNode> const &ptr, int priority, unsigned char data);
public:
	void add(int priority, unsigned char data);
};