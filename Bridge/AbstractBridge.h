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
        AbstractBridge();
        virtual ~AbstractBridge();

        virtual bool InitInstance() = 0;
        virtual bool ExitInstance() = 0;

        virtual bool ReadRowTest() = 0;

    protected:
        FileOperationImpl* _impl;
    };

    class UnixFileOperation : public AbstractBridge
    {
    public:
        UnixFileOperation();
        ~UnixFileOperation();

        bool InitInstance()
        {
            _impl = new UnixFileOperationImpl();
            return true;
        };
        bool ExitInstance()
        {
            delete _impl;
            return true;
        };

        bool ReadRowTest();
    };
}