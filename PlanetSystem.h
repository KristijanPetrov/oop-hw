#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>

#include "Planet.h"

using namespace std;

class PlanetSystem {
private:
	char* name;
	Planet* planet;
	int size;
	int capacity;
	void copy(const PlanetSystem& other);
	void erase();
	void resize();
public:
	PlanetSystem();
	PlanetSystem(const char* name, Planet* planet, int size);
	PlanetSystem(const PlanetSystem& other);
	PlanetSystem& operator=(const PlanetSystem& other);
	~PlanetSystem();

	const char* getName();
	Planet* getPlanet();
	int getSize();

	Planet& operator[](int index);
	const Planet& operator[](int index)const;

	PlanetSystem& operator+(const Planet& planet);
	PlanetSystem& operator-(const Planet& planet);

	void printAllPlanets();

	bool operator==(const PlanetSystem& other);
	void writeAllPlanets(const char* pathToFile);

	bool isDominatedBy(const char* name);
};