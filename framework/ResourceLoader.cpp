#include "pch-il2cpp.h"

#include "ResourceLoader.h"


bool LoadRCDATAToString(int resId, std::string& out) {
    HMODULE hModule = GetModuleHandleW(L"version.dll");
    HRSRC hRes = FindResourceW(hModule, MAKEINTRESOURCEW(resId), RT_RCDATA);
    if (!hRes) return false;
    HGLOBAL hGlobal = LoadResource(hModule, hRes);
    if (!hGlobal) return false;
    const void* data = LockResource(hGlobal);
    DWORD size = SizeofResource(hModule, hRes);
    if (!data || size == 0) return false;
    out.assign(static_cast<const char*>(data), static_cast<const char*>(data) + size);
    return true;
}