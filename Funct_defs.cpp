#include <iostream>
#include <string>
#include <windows.h>
#include <wchar.h>
#include "Funct_decls.h"


void take_me_here() {
	std::wstring location;
	std::wcin >> location;
	std::wstring google_maps_url = L"https://www.google.com/maps/place/";
	std::wstring full_url = google_maps_url + location;
	const wchar_t* pointer_url = full_url.c_str();
	std::cout << pointer_url << "\n";


	HWND hwnd = GetDesktopWindow();
	ShellExecute(hwnd, L"open", pointer_url, NULL, NULL, NULL);
}