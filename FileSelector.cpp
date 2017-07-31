#include "FileSelector.h"

FileSelector::FileSelector()
	: txtBuilder(new TextFileBuilder("my_file")),
	htmlBuilder(new HTMLFileBuilder("my_file"))
{}


FileSelector::~FileSelector()
{
	delete txtBuilder;
	delete htmlBuilder;
}


void FileSelector::process(FILE_TYPE type, string text)
{
	switch (type)
	{
	case TEXT: fileDirector.setBuilder(txtBuilder);  break;
	case HTML: fileDirector.setBuilder(htmlBuilder); break;
	}

	fileDirector.construct(text);
}