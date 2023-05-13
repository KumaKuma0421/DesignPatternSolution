//
// Template.cpp
//

#include <iostream>
#include "TemplateMethod.h"

using namespace GoF_TempateMethod;

bool Template::Action ()
{
	bool ret;
	do
	{
		ret = Init ();
		if (!ret) break;

		ret = Start ();
		if (!ret) break;

		ret = Stop ();
		if (!ret) break;

		ret = Exit ();
		if (!ret) break;
	} while (false);

	return ret;
}

bool TemplateAction::Init ()
{
	std::cout << "���������s���܂��B" << std::endl;
	return true;
}

bool TemplateAction::Start ()
{
	std::cout << "�������J�n���܂��B" << std::endl;
	return true;
}

bool TemplateAction::Stop ()
{
	std::cout << "�������I�����܂��B" << std::endl;
	return true;
}

bool TemplateAction::Exit ()
{
	std::cout << "�Еt���܂�" << std::endl;
	return true;
}
