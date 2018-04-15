#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>

#include "GalacticRepublic.h"
#include "Galaxy.h"

using namespace std;

class RepublicList { 
private:
	GalacticRepublic* galacticRepublic;
	int size;
public:
	RepublicList();
	RepublicList(GalacticRepublic* galacticRepublic, int size);
	~RepublicList();

	GalacticRepublic* getGalacticRepublic();
	int getSize();

	GalacticRepublic& operator[](int index);
	const GalacticRepublic& operator[](int index)const;

	void whoDominates(Galaxy& galaxy,const char* pathToFile);
};