#include "Folder.h"


Folder::Folder(const Folder& f) {

	this->name = f.name;
	for (list<FileComponent*>::const_iterator it = f.files.begin(); it != f.files.end(); it++)
		this->files.push_front((*it)->clone());
}


void Folder::addFile(FileComponent* f, int dst) {

	if (this->id == dst)
	{
		files.push_front(f);
		cout << "The file " << f->getName() << " was successfuly created\n";
		return;
	}

	else
	{
		for (list<FileComponent*>::iterator it = files.begin(); it != files.end(); it++)
			if ((*it)->isFolder())
				static_cast<Folder*>(*it)->addFile(f, dst);
	}
}


void Folder::copy(int id) {

	for (list<FileComponent*>::iterator it = files.begin(); it != files.end(); it++)
	{
		if ((*it)->getId() == id) // if this is the file to copy
		{
			files.push_front((*it)->clone()); // push a clone of this file to the container
			return;
		}
		else if ((*it)->isFolder())
			static_cast<Folder*>(*it)->copy(id); // recursivly searching for the file under folders
	}
}


void Folder::remove(int id) {

	for (list<FileComponent*>::iterator it = files.begin(); it != files.end(); ++it)
	{
		if ((*it)->getId() == id) // if this is the file to remove
		{
			files.erase(it); // remove the file from the container
			return;
		}
		else if ((*it)->isFolder())
			static_cast<Folder*>(*it)->remove(id); // recursivly searching for the file under folders
	}
}


string Folder:: toString() {

	static int tabs = 0;
	tabs++;
	stringstream ss;
	ss << "-DIR- " << this->name << " ID: " << this->id << " Created on " << this->getTimeCreated() << endl;
	for (list<FileComponent*>::iterator it = files.begin(); it != files.end(); ++it)
	{
		for (int i = 0; i < tabs; i++)
			ss << "\t";
		ss << (*it)->toString();
	}
	tabs--;
	return ss.str();
}