#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


class Planet {
private:
	char* name;
	char* planetSystem;
	char* republic;
	void copy(const Planet& other);
	void destroy();
public:
	Planet();
	Planet(const char* name, const char* planetSystem, const char* republic);
	Planet(const Planet& other);
	Planet& operator=(const Planet& other);
	~Planet();

	const char* getName() const;
	const char* getPlanetSystem() const;
	const char* getRepublic() const;
	void setName(const char* name);
	void setPlanetSystem(const char* planetSystem);
	void setRepublic(const char* republic);

	bool operator==(const Planet& other);
	bool operator!=(const Planet& other);


	friend ostream& operator<<(ostream& os, const Planet& planet);

};