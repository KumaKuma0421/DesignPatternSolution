//
// Composite.h
//

#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace GoF_Composite
{
	class Composite
	{
	public:
		Composite () : Composite (-1, "") {};
		Composite (int id, std::string name)
		{
			this->id = id;
			this->name = name;
		};
		virtual ~Composite () {};

		virtual void Print ();

		int id;
		std::string name;
	};

	class Leaf : public Composite
	{
	public:
		Leaf () :Leaf (-1, "") {};
		Leaf (int id, std::string name) : Composite (id, name) {};

		virtual ~Leaf () {};
	};

	class Node : public Composite
	{
	public:
		Node () :Node (-1, "") {};
		Node (int id, std::string name) : Composite (id, name) {};

		virtual ~Node () {};

		void Add (Node* node) { _nodes.push_back (node); };
		void Add (Leaf* leaf) { _leafs.push_back (leaf); };

		Node* GetNodes (size_t index);
		Leaf* GetLeafs (size_t index);

	private:
		std::vector<Node*> _nodes;
		std::vector<Leaf*> _leafs;
	};
}