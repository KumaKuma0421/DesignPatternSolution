//
// Composite.cpp
//

#include "Composite.h"

using namespace GoF_Composite;

void Composite::Print ()
{
	std::cout << id << ":" << name << std::endl;
}

Node* Node::GetNodes (size_t index)
{
	if (index < _nodes.size ()) return _nodes[index];
	else return nullptr;
}

Leaf* Node::GetLeafs (size_t index)
{
	if (index < _leafs.size ()) return _leafs[index];
	else return nullptr;
}