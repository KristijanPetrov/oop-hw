#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>

#include "JediTemple.h"
#include "Army.h"
#include "Galaxy.h"

using namespace std;

class GalacticRepublic {
private:
	char* name;
	JediTemple jediTemple;
	Army army;
	Galaxy galaxy;
	void copy(const GalacticRepublic& other);
	void erase();
public:
	GalacticRepublic();
	GalacticRepublic(const char* name,JediTemple& jediTemple, Army& army, Galaxy& galaxy);
	GalacticRepublic(const char* name);
	GalacticRepublic(const GalacticRepublic& other);
	GalacticRepublic& operator=(const GalacticRepublic& other);
	~GalacticRepublic();

	const char* getName();
	JediTemple& getJediTemle();
	Army& getArmy();
	Galaxy& getGalaxy();

	bool dominates();
};