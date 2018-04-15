#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>

#include "Planet.h"

using namespace std;


enum Jedirank {
	Youngling,
	Padawan,
	Knight,
	Master
};

class Jedi {
private:
	char* name;
	Jedirank rank;
	double midichlorian;
	Planet planet;
	char* spicies;
	char* militaryRank;
	void copy(const Jedi& other);
	void erase();
public:
	Jedi();
	Jedi(const char* name, Jedirank rank, double midichlorian, Planet& planet, const char* spicies, const char* militaryRank);
	Jedi(const Jedi& other);
	Jedi& operator=(const Jedi& other);
	~Jedi();

	const char* getName() const;
	Jedirank getRank() const;
	double getMidichlorian() const;
	Planet& getPlanet();
	const char* getSpicies() const;
	const char* getMilitaryRank() const;
	const char* getPlanetName() const;

	void setName(const char* name);
	void setRank(Jedirank rank);
	void setMidichlorian(double midichlorian);
	void setPlanet(Planet& planet);
	void setSpicies(const char* spicies);
	void setMilitaryRank(const char* militaryRank);

	friend ostream& operator<<(ostream& os, const Jedi& jedi);

	bool operator==(const Jedi& other);
};