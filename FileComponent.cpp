#include "FileComponent.h" 

int FileComponent::idGen = 0;

string FileComponent::toString() { 
	
	stringstream ss;
	ss << "-FILE- " << name << " ID: " << id << " Created on " << ctime(&timeCreated) << endl;
	return ss.str();

}