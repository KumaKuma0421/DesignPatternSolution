//
// Strategy.cpp
//

#include "Strategy.h"

using namespace Sample;

Material* IceCreamMaker::Make()
{
    return new Material(ICE_CREAM, "アイスモナカ", 180, 10);
}

Material* MentosMaker::Make()
{
    return new Material(MENTOS, "メントス", 100, 10);
}

Material* CocaColaMaker::Make()
{
    return new Material(COCA_COLA, "コカ・コーラ", 130, 10);
}