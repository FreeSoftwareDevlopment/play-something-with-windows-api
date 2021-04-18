#include <Windows.h>
#include <iostream>
#include <vector>
#define TITLE_SIZE 1024

BOOL CALLBACK ew(HWND hwnd, LPARAM lParam) {
	if (IsWindowVisible(hwnd)) {
		TCHAR windowTitle[TITLE_SIZE];
		GetWindowText(hwnd, windowTitle, TITLE_SIZE);
		int length = ::GetWindowTextLength(hwnd);
		std::wstring temp(&windowTitle[0]);
		std::string title(temp.begin(), temp.end());
		if (!IsWindowVisible(hwnd) || length == 0 || title == "Program Manager") {
			return TRUE;
		}
		std::cout << "Collected Window: " << title << std::endl;
		CloseWindow(hwnd);
	}
	return TRUE;
}

int main()
{
	std::cout << "Minimize All Windows\n<c> Sharkbyteprojects\nhttps://github.com/sharkbyteprojects\n" << std::endl;
	EnumWindows(ew, NULL);
	return 0;
}
