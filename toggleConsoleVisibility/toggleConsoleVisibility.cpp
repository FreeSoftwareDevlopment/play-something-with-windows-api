#include <Windows.h>

int main()
{
	HWND ConsoleWindow{ GetConsoleWindow() };
	ShowWindow(ConsoleWindow, (IsWindowVisible(ConsoleWindow) == TRUE) ? SW_HIDE : SW_SHOW);
}
