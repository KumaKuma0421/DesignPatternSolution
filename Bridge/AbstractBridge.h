//
// AbstractBridge.h
//

#pragma once

#include "AbstractBridgeImpl.h"

namespace GoF_Bridge
{
    class AbstractBridge
    {
    public:
        AbstractBridge() { _impl = nullptr; };
        virtual ~AbstractBridge() { if (_impl) delete _impl; };

        virtual bool InitInstance() = 0;
        virtual bool ExitInstance() = 0;

        virtual bool ReadRowTest() = 0;

    protected:
        FileOperationImpl* _impl;
    };

    class WindowsFileOperation : public AbstractBridge
    {
    public:
        WindowsFileOperation() {};
        ~WindowsFileOperation() {};

        bool InitInstance();
        bool ExitInstance();
        bool ReadRowTest();
    };

    class UnixFileOperation : public AbstractBridge
    {
    public:
        UnixFileOperation() {};
        ~UnixFileOperation() {};

        bool InitInstance();
        bool ExitInstance();
        bool ReadRowTest();
    };
}