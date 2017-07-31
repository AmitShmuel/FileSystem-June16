#ifndef _FILECOMPONENT_
#define _FILECOMPONENT_
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;


class FileComponent { // acts as abstract component in the composite pattern
					  // uses clone() as part of the prototype pattern, inherited classes must override
protected:

	static int idGen;
	int id;
	time_t timeCreated;
	string name;


public:

	FileComponent(string fileName = "new file") : id(idGen++), name(fileName), timeCreated(time(0)) { ; }
	FileComponent(const FileComponent& f) : id(idGen++), name(f.name), timeCreated(time(0)) { ; }

	int getId() const { return id; }
	string getName() const { return name; }
	string getTimeCreated() const { return ctime(&timeCreated); }

	virtual FileComponent* clone() = 0;
	virtual string toString();
	virtual bool isFolder() const { return false; }
};


#endif // !_FILECOMPONENT_
