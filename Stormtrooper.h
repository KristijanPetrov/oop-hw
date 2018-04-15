#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>

#include "Planet.h"

using namespace std;

enum Stormtrooperrank {
	Tank,
	AntiRush,
	Duelist,
	Sniper
};

class Stormtrooper {
private:
	char* id;
	Stormtrooperrank rank;
	char* type;
	Planet planet;
	void copy(const Stormtrooper& other);
	void erase();
public:
	Stormtrooper();
	Stormtrooper(const char* id, Stormtrooperrank rank, const char* type, Planet& planet);
	Stormtrooper(const Stormtrooper& other);
	Stormtrooper& operator=(const Stormtrooper& other);
	~Stormtrooper();

	const char* getId() const;
	Stormtrooperrank getRank() const;
	const char* getType() const;
	Planet& getPlanet();
	const char* getPlanetName() const;

	void setId(const char* id);
	void setRank(Stormtrooperrank rank);
	void setType(const char* type);
	void setPlanet(Planet& planet);

	friend ostream& operator<<(ostream& os, const Stormtrooper& stormtrooper);

	bool operator==(const Stormtrooper& other);
	

};