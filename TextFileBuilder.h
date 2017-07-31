#ifndef _TEXTFILEBUILDER_
#define _TEXTFILEBUILDER_


#include "FileBuilder.h"

// concrete File Builder, override editText(string) method
class TextFileBuilder : public FileBuilder {

public:
	inline TextFileBuilder(string fileName);
	virtual inline string editText(string text);
};


TextFileBuilder::TextFileBuilder(string fileName)
	: FileBuilder(fileName.append(".txt"))
{}


string TextFileBuilder::editText(string text) { return text; }


#endif // _TEXTFILEBUILDER_