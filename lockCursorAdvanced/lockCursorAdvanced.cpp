#include "includes.h"
#include "ccp.h"

void visibilityChange() {
	HWND ConsoleWindow{ GetConsoleWindow() };
	ShowWindow(ConsoleWindow, (IsWindowVisible(ConsoleWindow) == TRUE) ? SW_HIDE : SW_SHOW);
}

int main()
{
	cursorPos* current;
	retGP<BOOL, cursorPos*> x{ getCurrentCursorPos() };
	if (x.a == TRUE) {
		current = x.b;
		std::cout << "Lock Cursor\n<c> Sharkbyteprojects\nhttps://github.com/sharkbyteprojects\n" << "Press Escape to unlock Mouse and close this!\nPress F1 to toggle Lock\nPress F2 to Change Console Visibility" << std::endl;
		bool stateofThing{ false }, prevstateofthing{ false }, stateofThingB{ false }, prevstateofthingB{ false }, enabled{ true };
		do {
			stateofThingB = (GetKeyState(VK_F1) & 0x8000);
			if (stateofThingB != prevstateofthingB && stateofThingB) {
				enabled = !enabled;
				if (enabled) {
					current = getCurrentCursorPos().b;
				}
			}
			if (enabled) {
				SetCursorPos(current->x, current->y);
			}
			std::this_thread::sleep_for(std::chrono::microseconds(1));
			stateofThing = (GetKeyState(VK_F2) & 0x8000);
			if (stateofThing != prevstateofthing && stateofThing) {
				visibilityChange();
			}
			prevstateofthing = stateofThing;
			prevstateofthingB = stateofThingB;
		} while (
			!(GetKeyState(VK_ESCAPE) & 0x8000)
			);
	}
	return 0;
}
