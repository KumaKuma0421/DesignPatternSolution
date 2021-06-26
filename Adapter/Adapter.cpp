//
// Adapter.cpp
//

#include "Adapter.h"

using namespace GoF_Adapter;

Adapter::Adapter()
{
    _hLibrary = nullptr;
    _GetProfile = nullptr;
    _WriteProfile = nullptr;
}

Adapter::~Adapter()
{
    if (_hLibrary) ::FreeLibrary(_hLibrary);
}

BOOL Adapter::Init()
{
    BOOL ret = false;

    _hLibrary = ::LoadLibrary("Kernel32.dll");
    if (_hLibrary)
    {
        _GetProfile =
            (GetProfile)::GetProcAddress(
                _hLibrary, "GetPrivateProfileStringA");
        _WriteProfile =
            (WriteProfile)::GetProcAddress(
                _hLibrary, "WritePrivateProfileStringA");

        ret = TRUE;
    }

    return ret;
}

BOOL Adapter::Exit()
{
    return ::FreeLibrary(_hLibrary);
}
BOOL Adapter::GetProfileString(
    const char* section, const char* keyword, char* buffer, size_t size)
{
    DWORD dwRet = _GetProfile(section, keyword, nullptr, buffer, size, ".\\Profile.ini");
    return dwRet > 0 ? TRUE : FALSE;
};

BOOL Adapter::SetProfileString(
    const char* section, const char* keyword, const char* buffer)
{
    return _WriteProfile(section, keyword, buffer, ".\\Profile.ini");
};
