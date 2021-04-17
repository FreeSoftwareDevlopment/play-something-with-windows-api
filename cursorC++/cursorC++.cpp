#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include <string>

class coordinates {
public:
	int x{ -1 };
	int y{ -1 };
	int tick{ -1 };
};

int main()
{
	std::cout << "Mouse Log\n<c> Sharkbyteprojects\nhttps://github.com/sharkbyteprojects\n" << std::endl;
	coordinates prevc;
	POINT currentcursorpos;
	int tick{ 0 };
	bool stateofThing{ false }, prevstateofthing{ false };
	HWND ConsoleWindow;
	HANDLE fh = CreateFileA(".\mouselog.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	char buffer[200];
	int btw{ 0 };
	std::string mstr{ "" };
	do {
		ConsoleWindow = GetConsoleWindow();
		if (GetCursorPos(&currentcursorpos) == TRUE) {
			coordinates cx;
			cx.x = currentcursorpos.x;
			cx.y = currentcursorpos.y;
			cx.tick = tick++;
			if (cx.x != prevc.x && cx.y != prevc.y) {
				coordinates& vcc = cx;
				{
					mstr = "";
#pragma region createString
					mstr.append("X: ");
					mstr.append(std::to_string(vcc.x));
					mstr.append("\tY: ");
					mstr.append(std::to_string(vcc.y));
					mstr.append("\tTick: ");
					mstr.append(std::to_string(vcc.tick));
					mstr.append("\n");
#pragma endregion
#pragma region convert string
					btw = mstr.length();
					strcpy_s(buffer, sizeof(buffer) - 1, mstr.c_str());
#pragma endregion
				}
				if (WriteFile(fh, buffer, btw, NULL, NULL) == FALSE) {
					std::cerr << "Error: " << GetLastError() << std::endl;
				}
				std::cout << "X: " << currentcursorpos.x << "\tY: " << currentcursorpos.y << std::endl;
				prevc = cx;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		stateofThing = (GetKeyState(VK_F1) & 0x8000);
		if (stateofThing != prevstateofthing && stateofThing) {
			ShowWindow(ConsoleWindow, (IsWindowVisible(ConsoleWindow) == TRUE) ? SW_HIDE : SW_SHOW);
		}
		prevstateofthing = stateofThing;
	} while (
		!(GetKeyState(VK_ESCAPE) & 0x8000)
		);
	return 0;
}