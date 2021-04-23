#include <iostream>
#include <Windows.h>
#include <Wininet.h>

char* getdata(char*);

int main(int argc, char* argv[])
{
	if (argc == 1) {
		std::cout << "OOOOOPS! This Application need as args the network Address to download!" << std::endl;
		return -1;
	}
	for (int currentval{ 1 }; currentval < argc; currentval++) {
		char* urls = argv[currentval];
		std::cout << "Content of " << urls << ": " << getdata(urls) << "\n" << std::endl;
	}
	return 0;
}

char* getdata(char* urls, int* recieveddatalength) {
	int torecieve{ 300 };
	char* recievedata{ new char[torecieve + 1] };
	HANDLE inets = InternetOpenA("sharkbyte net client", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, NULL);
	if (inets == NULL) {
		std::cerr << "Internet Open Err" << std::endl;
		return new char[] {""};
	}
	HANDLE validhandle = InternetOpenUrlA(inets, urls, NULL, NULL, INTERNET_FLAG_SECURE, NULL);
	if (validhandle == NULL) {
		std::cerr << "Open Url Err" << std::endl;
		return new char[] {""};
	}
	InternetReadFile(validhandle, recievedata, torecieve, (LPDWORD)recieveddatalength);
	return recievedata;
}

char* getdata(char* urls) {
	int zerovalue{ 0 };
	return getdata(urls, &zerovalue);
}