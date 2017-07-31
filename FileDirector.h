#ifndef FILE_DIRECTOR
#define FILE_DERECTOR


#include "FileBuilder.h"


class FileDirector { // the director in the builder pattern

public:
	inline void setBuilder(FileBuilder* fbuilder);
	inline void construct(string text);

private:
	FileBuilder* fileBuilder;
};


void FileDirector::setBuilder(FileBuilder* fbuilder)
{
	fileBuilder = fbuilder;
}


void FileDirector::construct(string text)
{
	string res = fileBuilder->editText(text);
	fileBuilder->buildText(res);
	fileBuilder->closeFile();
}


#endif