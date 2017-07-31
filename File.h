#ifndef _FILE_
#define _FILE_
#include "FileComponent.h"


class File : public FileComponent { // acts as the leaf in the composite pattern
									// implements clone() as part of the prototype pattern
public:

	File(string fileName) : FileComponent(fileName) {};
	virtual FileComponent* clone() { return new File(*this); };
};


#endif // !_FILE_