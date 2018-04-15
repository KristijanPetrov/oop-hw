#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>

#include "PlanetSystem.h"

using namespace std;

class Galaxy {
private:
	char* name;
	PlanetSystem* planetSystem;
	int size;
	int capacity;
	void copy(const Galaxy& other);
	void erase();
	void resize();
public:
	Galaxy();
	Galaxy(const char* name,PlanetSystem* planetSystem, int size);
	Galaxy(const Galaxy& other);
	Galaxy& operator=(const Galaxy& other);
	~Galaxy();

	const char* getName();
	PlanetSystem* getPlanetSystem();
	int getSize();

	PlanetSystem& operator[](int index);
	const PlanetSystem& operator[](int index)const;

	Galaxy& operator+(const PlanetSystem& planetSystem);
	Galaxy& operator-(const PlanetSystem& planetSystem);

	void printAllPlanetsInGalaxy();
	void writeAllPlanetsInGalaxy(const char* pathToFile);

	bool isDominatedBy(const char* name);
};