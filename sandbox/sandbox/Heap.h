#pragma once
#include <vector>

template<typename Priority, typename Data>
class Heap
{
private:
	struct HeapNode {
		Priority priority_;
		Data data_;
	};
	std::vector<HeapNode> veep_;
public:
	Heap();
	~Heap();
	void push(Priority priority, Data data);
	// Node* pop();
	bool is_empty();
	void maximum();
	void HeapSort();
	int parent(int i);
	HeapNode pop();
};

