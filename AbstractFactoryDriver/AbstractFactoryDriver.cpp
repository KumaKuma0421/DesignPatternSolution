//
// Main.cpp
//

#include <iostream>
#include <memory>
#include "AbstractFactory.h"

using namespace GoF_AbstractFactory;

void run_product (std::string& target)
{
	// 仮想コンストラクタ
	// 新しいオブジェクトを、その具体的な型を知ることなく生成する機構
	
	// ここでは、文字列によるオブジェクトの生成を実現している。通常、C++ではこれはできない。
	// 内部では、new()によって生成されているので、実現できている訳ではないが、
	// この"AbstractDriver"から見れば、あたかも文字列からオブジェクトを生成しているように
	// 振舞うことができる。
	std::unique_ptr<AbstractFactory> factory1(AbstractFactory::CreateFactory (target.c_str()));
	std::unique_ptr<StorageProduct> storage1(factory1->CreateStorageProduct ());
	std::unique_ptr<DisplayProduct> display1(factory1->CreateDisplayProduct ());
	std::unique_ptr<ControlProduct> control1(factory1->CreateControlProduct ());

	std::string response;

	control1->Start ();
	response = response = storage1->Load ();
	std::cout << response << std::endl;
	display1->Show ("This is created by factory1.");
	storage1->Store ("Store by storage1.");
	control1->Stop ();
}

int main (int argc, char** argv)
{
	FUNCTION_BEGIN ();

	std::string target;

	target = "Batch";
	run_product (target);

	target = "Realtime";
	run_product (target);

	FUNCTION_END ();
	return 0;
}