#ifndef _HTMLFILEBUILDER_
#define _HTMLFILEBUILDER_


#include "FileBuilder.h"
#include <sstream>

// concrete File Builder, override editText(string) method
class HTMLFileBuilder : public FileBuilder { 

public:
	inline HTMLFileBuilder(string fileName);
	virtual inline string editText(string text);
	virtual inline void closeFile();
};


HTMLFileBuilder::HTMLFileBuilder(string fileName)
	: FileBuilder(fileName.append(".html"))
{
	FileBuilder::buildText("<HTML>\n<BODY>\n");
}


string HTMLFileBuilder::editText(string text) {

	stringstream ss;
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == '\n')
			ss << "<br>";
		else if (text[i] == '\t')
			ss << "&emsp;&emsp;";
		else
			ss << text[i];
	}
	return ss.str();
}


void HTMLFileBuilder::closeFile()
{
	FileBuilder::buildText("\n</BODY>\n</HTML>");
	FileBuilder::closeFile();
}


#endif // _HTMLFILEBUILDER_