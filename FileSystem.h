#ifndef _FILESYSTEM_
#define _FILESYSTEM_
#include "FileSelector.h"
#include "File.h"
#include "Folder.h"

typedef enum{ file, folder } kind;

typedef void(Folder::*pfunc)(int); // function pointer


class FileSystem { // singleton class

	static FileSystem* fs;
	Folder* root;
	FileSelector selector; // the selector in the builder pattern
	FileSystem();
	
public:

	FileSystem(const FileSystem&) = delete;
	~FileSystem();
	static FileSystem* getInstance();
	
	void toFile();
	void create(kind);
	void copyOrRemove(pfunc);
	string print() { return root->toString(); }
	
};


#endif // !_FILESYSTEM_