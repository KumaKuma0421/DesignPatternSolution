//
// Main.cpp
//

#include <iostream>
#include "Material.h"
#include "Shop.h"

using namespace Sample;

int main (int argc, char** argv)
{
	VirtualShop* shop = VirtualShop::Instance ();

	shop->Prepare ();

	shop->Stock (ICE_CREAM);
	shop->Stock ("抹茶");
	shop->Stock (COCA_COLA);

	shop->Pickup (ICE_CREAM);
	shop->Pickup (ICE_CREAM);
	shop->Pickup ("抹茶");
	shop->Pickup (MENTOS);
	shop->Pickup (COCA_COLA);

	shop->Check ();

	std::cout << "Done." << std::endl;
}