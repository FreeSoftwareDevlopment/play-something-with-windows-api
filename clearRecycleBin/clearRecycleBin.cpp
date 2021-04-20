#include <Windows.h>
#include <iostream>

int main()
{
	std::cout << "Cl Rec Bin" << std::endl;
	SHEmptyRecycleBinA(NULL, NULL, SHERB_NOCONFIRMATION);
	return 0;
}