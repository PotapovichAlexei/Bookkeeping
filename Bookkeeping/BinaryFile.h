#pragma once
#include "Header.h"

template<typename T>
class BinaryFile : public File
{
private:
	fstream FileStream;
public:
	BinaryFile(const string = "");
	bool openToInput();
	bool openToOutput();
	bool openToAdd();
	void rewindFile();
	void inputToFile(T& Object);
	void outputToFile(T& Object);
	bool endFile();
	~BinaryFile();
};
