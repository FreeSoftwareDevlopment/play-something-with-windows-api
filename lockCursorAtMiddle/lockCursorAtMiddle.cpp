#include <Windows.h>
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
	POINT currentcursorpos;
	if (GetCursorPos(&currentcursorpos) == TRUE) {
		std::cout << "Lock Cursor\n<c> Sharkbyteprojects\nhttps://github.com/sharkbyteprojects\n" << "Press Escape to unlock Mouse!" << std::endl;
		do {
			SetCursorPos(currentcursorpos.x, currentcursorpos.y);
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		} while (
			!(GetKeyState(VK_ESCAPE) & 0x8000)
			);
	}
	return 0;
}