//
// AbstractBridgeImpl.cpp
//

#include "AbstractBridgeImpl.h"

using namespace GoF_Bridge;

WindowsFileOperationImpl::WindowsFileOperationImpl()
{
    _hFile = nullptr;
}

WindowsFileOperationImpl::~WindowsFileOperationImpl()
{
    if (_hFile) ::CloseHandle(_hFile);
}

bool WindowsFileOperationImpl::Open(char* fileName)
{
    DWORD dwDesiredAccess = GENERIC_ALL;
    DWORD dwShareMode = 0;
    LPSECURITY_ATTRIBUTES lpSecurityAttributes = nullptr;
    DWORD dwCreationDisposition = CREATE_ALWAYS;
    DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL;
    HANDLE hTemplateFile = nullptr;

    _hFile = ::CreateFile(
        fileName,
        dwDesiredAccess,
        dwShareMode,
        lpSecurityAttributes,
        dwCreationDisposition,
        dwFlagsAndAttributes,
        hTemplateFile);

    return _hFile == INVALID_HANDLE_VALUE ? false : true;
}

int WindowsFileOperationImpl::Read(char* buffer, size_t size)
{
    DWORD dwNumberOfBytesRead;
    BOOL ret;

    ret = ::ReadFile(
        _hFile,
        buffer,
        size,
        &dwNumberOfBytesRead,
        nullptr);

    return ret == TRUE ? dwNumberOfBytesRead : -1;
}

bool WindowsFileOperationImpl::Write(char* buffer, size_t size)
{
    DWORD write;
    BOOL ret;

    ret = ::WriteFile(
        _hFile,
        buffer,
        size,
        &write,
        nullptr);

    return ret == TRUE ? true : false;
}

bool WindowsFileOperationImpl::SetPos(FilePos pos, long offset)
{
    return true;
}

bool WindowsFileOperationImpl::Flush()
{
    BOOL ret;

    ret = ::FlushFileBuffers(_hFile);

    return ret == TRUE ? true : false;
}

bool WindowsFileOperationImpl::Close()
{
    return ::CloseHandle(_hFile);
}

// --------------------------------------------------------

UnixFileOperationImpl::UnixFileOperationImpl()
{
    _fp = nullptr;
}

UnixFileOperationImpl::~UnixFileOperationImpl()
{
}

// @sa https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-s-wfopen-s?redirectedfrom=MSDN&view=msvc-160
bool UnixFileOperationImpl::Open(char* fileName)
{
    errno_t err = fopen_s(&_fp, fileName, "w+");

    return err == 0 ? true : false;
}

int UnixFileOperationImpl::Read(char* buffer, size_t size)
{
    char* ret;

    ret = fgets(buffer, size, _fp);

    return ret == nullptr ? -1 : strlen(buffer);
}

bool UnixFileOperationImpl::Write(char* buffer, size_t size)
{
    int ret;

    ret = fputs(buffer, _fp);

    return ret > 0 ? true : false;
}

bool UnixFileOperationImpl::SetPos(FilePos pos, long offset)
{
    int ret;

    ret = fseek(_fp, offset, (int)pos);

    return ret == 0 ? true : false;
}

bool UnixFileOperationImpl::Flush()
{
    int ret;

    ret = fflush(_fp);

    return ret == 0 ? true : false;
}

bool UnixFileOperationImpl::Close()
{
    errno_t err = fclose(_fp);

    return err == 0 ? true : false;
}