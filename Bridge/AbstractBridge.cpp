//
// AbstractBridge.cpp
//

#include "AbstractBridge.h"

using namespace GoF_Bridge;

AbstractBridge::AbstractBridge()
{
    _impl = nullptr;
}

AbstractBridge::~AbstractBridge()
{
    if (!_impl) delete _impl;
}

UnixFileOperation::UnixFileOperation()
{

}

UnixFileOperation::~UnixFileOperation()
{

}

bool UnixFileOperation::ReadRowTest()
{
    bool ret;
    char* fileName = (char*)".\\sample_text.txt";
    const size_t size = 1024;
    char buffer[size];
    int read;

    ret = _impl->Open(fileName);
    if (!ret)
    {
        printf("can't find file '%s'\n", fileName);
        return false;
    }

    for(int i = 0; i < 1000; i++)
    {
        sprintf_s(buffer, "%d %s\n", i, "sample");
        _impl->Write(buffer, strlen(buffer));
    }

    _impl->Flush();
    _impl->SetPos(FilePos::Begin, 0);

    while ((read = _impl->Read(buffer, size)) != -1)
    {
        printf("%s", buffer);
    }

    ret = _impl->Close();
    if (!ret)
    {
        printf("file close failed. '%s'\n", fileName);
        return false;
    }

    return true;
}