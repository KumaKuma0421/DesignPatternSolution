//
// Main.cpp
//

#include <iostream>
#include "Composite.h"

using namespace GoF_Composite;

void search (Node* node);

int main (int argc, char** argv)
{
	int nodeCounter = 0;
	int leafCounter = 0;

	Node rootNode (nodeCounter++, "root node");
	Leaf rootLeaf1 (leafCounter++, "root leaf1");
	Leaf rootLeaf2 (leafCounter++, "root leaf2");

	rootNode.Add (&rootLeaf1);
	rootNode.Add (&rootLeaf2);

	Node firstNode (nodeCounter++, "1st node");
	Leaf firstLeaf1 (leafCounter++, "1st node 1st leaf");
	Leaf firstLeaf2 (leafCounter++, "1st node 2nd leaf");

	firstNode.Add (&firstLeaf1);
	firstNode.Add (&firstLeaf2);

	rootNode.Add (&firstNode);

	Node secondNode (nodeCounter++, "2nd node");
	Leaf secondLeaf1 (leafCounter++, "2nd node 1st leaf");
	Leaf secondLeaf2 (leafCounter++, "2nd node 2nd leaf");

	secondNode.Add (&secondLeaf1);
	secondNode.Add (&secondLeaf2);

	firstNode.Add (&secondNode);

	search (&rootNode);

	std::cout << "Done." << std::endl;
}

void search (Node* node)
{
	size_t leafIndex = 0;
	Leaf* leaf = nullptr;
	while ((leaf = node->GetLeafs (leafIndex++)) != nullptr)
	{
		leaf->Print ();
	}

	size_t nodeIndex = 0;
	Node* childNode = nullptr;
	while ((childNode = node->GetNodes (nodeIndex++)) != nullptr)
	{
		childNode->Print ();

		search (childNode);
	}
}