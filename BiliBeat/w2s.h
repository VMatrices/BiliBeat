#pragma once
#include"stdafx.h"

static string w2s(wchar_t* wz)
{
		std::string szDst;
		wchar_t * wText = wz;
		DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE);
		char *psText;
		psText = new char[dwNum];
		WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE);
		szDst = psText;
		delete[]psText;
		return szDst;
}

static wchar_t* s2w(std::string str)
{
		std::string temp = str;
		int len = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)temp.c_str(), -1, NULL, 0);
		wchar_t * wsz = new wchar_t[len + 1];
		memset(wsz, 0, len * 2 + 2);
		MultiByteToWideChar(CP_ACP, 0, (LPCSTR)temp.c_str(), -1, (LPWSTR)wsz, len);
		return wsz;
}