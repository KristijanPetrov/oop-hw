#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>

#include "Stormtrooper.h"

using namespace std;

class Army {
private:
	Stormtrooper* stormtrooper;
	int size;
	int capacity;
	void copy(const Army& other);
	void erase();
	void resize();
public:
	Army();
	Army(Stormtrooper* stormttooper, int size);
	Army(const Army& other);
	Army& operator=(const Army& other);
	~Army();

	Stormtrooper* getStormtrooper();
	int getSize();

	Stormtrooper& operator[](int index);
	const Stormtrooper& operator[](int index)const;

	Army& operator+(const Stormtrooper& stormtrooper);
	Army& operator-(const Stormtrooper& stormtrooper);

	void printByPlanet(const Planet& planet);
	void writeAllStormtroopers(const char* pathToFile);
};
