//
// Adapter.h
//

#pragma once

#include <Windows.h>
#include <WinBase.h>
#include <libloaderapi.h>

namespace GoF_Adapter
{
    typedef DWORD(WINAPI* GetProfile)(
        LPCSTR lpAppName,
        LPCSTR lpKeyName,
        LPCSTR lpDefault,
        LPSTR  lpReturnedString,
        DWORD  nSize,
        LPCSTR lpFileName);

    typedef BOOL(WINAPI* WriteProfile)(
        LPCSTR lpAppName,
        LPCSTR lpKeyName,
        LPCSTR lpString,
        LPCSTR lpFileName);

    class Adapter
    {
    public:
        Adapter();
        virtual ~Adapter();

        BOOL Init();
        BOOL Exit();
        BOOL GetProfileString(
            const char* section, const char* keyword, char* buffer, size_t size);
        BOOL SetProfileString(
            const char* section, const char* keyword, const char* buffer);

    private:
        // Adaptee parts
        HMODULE _hLibrary;
        GetProfile _GetProfile;
        WriteProfile _WriteProfile;
    };
}