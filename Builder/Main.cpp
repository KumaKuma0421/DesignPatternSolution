//
// Main.cpp
//

#include <iostream>
#include <string>
#include "Builder.h"

using namespace GoF_Builder;

void get_metal_product ()
{
	// MetalBuilderによって(Metal)Productを
	// 頑張って作ってもらいます。
	Builder* builder = new MetalBuilder();

	// できたProductを使います。
	Product* product = builder->BuildProduct ();
	std::cout << product->GetName () << std::endl;
	std::cout << product->GetSpec () << std::endl;
	
	delete product;
	delete builder;
}

void get_wood_product ()
{
	// WoodBuilderによって(Wood)Productを
	// 頑張って作ってもらいます。
	Builder* builder = new WoodBuilder();

	// できたProductを使います。
	Product* product = builder->BuildProduct ();
	std::cout << product->GetName () << std::endl;
	std::cout << product->GetSpec () << std::endl;

	delete product;
	delete builder;
}

int main (int argc, char** argv)
{
	get_metal_product ();
	get_wood_product ();

	std::cout << "Done." << std::endl;
}