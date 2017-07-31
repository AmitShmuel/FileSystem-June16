#ifndef _FILEBUILDER_
#define _FILEBUILDER_


#include <iostream>
#include <fstream>
using namespace std;


class FileBuilder { // abstract builder, inherited classes must override editText(string) method

public:
	inline FileBuilder(string fileName);
	inline void buildText(string text);
	virtual inline string editText(string text) = 0;
	virtual inline void closeFile();

private:
	ofstream out;
};


FileBuilder::FileBuilder(string fileName)
{
	out.open(fileName.data(), ios::out);
}


void FileBuilder::buildText(string text)
{
	out << text.data();
}


void FileBuilder::closeFile()
{
	out.close();
}



#endif // _FILEBUILDER_