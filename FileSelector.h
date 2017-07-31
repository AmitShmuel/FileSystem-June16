#ifndef _FILESELECTOR_
#define _FILESELECTOR_


#include "FileDirector.h"
#include "HtmlFileBuilder.h"
#include "TextFileBuilder.h"


class FileSelector { // the selector in the builder pattern

public:

	enum FILE_TYPE { TEXT, HTML };
	FileSelector();
	~FileSelector();
	void process(FILE_TYPE type, string text);

private:
	FileDirector fileDirector;
	TextFileBuilder* txtBuilder;
	HTMLFileBuilder* htmlBuilder;
};


#endif // _FILESELECTOR_