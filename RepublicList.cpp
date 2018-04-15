#include "stdafx.h"
#include "RepublicList.h"

RepublicList::RepublicList() {
	this->size = 0;
	this->galacticRepublic = new GalacticRepublic;
}
RepublicList::RepublicList(GalacticRepublic* galacticRepublic, int size) {
	this->size = size;
	this->galacticRepublic = new GalacticRepublic[this->size];
	for (int i = 0;i < size;i++)
	{
		this->galacticRepublic[i] = galacticRepublic[i];
	}
}
RepublicList::~RepublicList() {
	delete[] this->galacticRepublic;
}

GalacticRepublic* RepublicList::getGalacticRepublic() {
	return this->galacticRepublic;
}
int RepublicList::getSize() {
	return this->size;
}

GalacticRepublic& RepublicList::operator[](int index) {
	return this->galacticRepublic[index];
}
const GalacticRepublic& RepublicList::operator[](int index)const {
	return this->galacticRepublic[index];
}

void RepublicList::whoDominates(Galaxy& galaxy,const char* pathToFile)
{
	for (int i = 0;i < this->size;i++)
	{
		if (galaxy.isDominatedBy(this->galacticRepublic[i].getName())) {
			ofstream outFile;
			outFile.open(pathToFile, ios::out,ios::app);

			for (int i = 0; i < size; ++i)
			{
				outFile << this->galacticRepublic[i].getName() << " - " << galaxy.getName() << endl;
			}
			outFile.close();
			return;
		}
	}
}
