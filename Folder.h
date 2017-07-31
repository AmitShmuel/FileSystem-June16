#ifndef _FOLDER_
#define _FOLDER_
#include "FileComponent.h"
#include <list>
using namespace std;


class Folder : public FileComponent { // acts as the composite
									  // implements clone() as part of the prototype pattern
	list<FileComponent*> files;

public:

	Folder(string fileName = "new file") : FileComponent(fileName) { ; }
	Folder(const Folder& f);

	void addFile(FileComponent* f, int dst);
	void copy(int id);
	void remove(int id);

	virtual string toString();
	virtual FileComponent* clone() { return new Folder(*this); }
	bool isFolder() const { return true; }
};


#endif // !_FOLDER_