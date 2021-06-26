//
// Strategy.cpp
//

#include "Strategy.h"

using namespace Sample;

Material* IceCreamMaker::Make()
{
    return new Material(ICE_CREAM, "�A�C�X���i�J", 180, 10);
}

Material* MentosMaker::Make()
{
    return new Material(MENTOS, "�����g�X", 100, 10);
}

Material* CocaColaMaker::Make()
{
    return new Material(COCA_COLA, "�R�J�E�R�[��", 130, 10);
}