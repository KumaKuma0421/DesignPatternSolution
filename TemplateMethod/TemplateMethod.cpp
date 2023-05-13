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
	std::cout << "初期化を行います。" << std::endl;
	return true;
}

bool TemplateAction::Start ()
{
	std::cout << "処理を開始します。" << std::endl;
	return true;
}

bool TemplateAction::Stop ()
{
	std::cout << "処理を終了します。" << std::endl;
	return true;
}

bool TemplateAction::Exit ()
{
	std::cout << "片付けます" << std::endl;
	return true;
}
