#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>

#include "Jedi.h"

using namespace std;

class JediTemple {
private:
	Jedi* jedi;
	int size;
	int capacity;
	void copy(const JediTemple& other);
	void erase();
	void resize();
public:
	JediTemple();
	JediTemple(Jedi* jedi,int size);
	JediTemple(const JediTemple& other);
	JediTemple& operator=(const JediTemple& other);
	~JediTemple();

	Jedi* getJedi();
	int getSize();

	Jedi& operator[](int index);
	const Jedi& operator[](int index)const;

	JediTemple& operator+(const Jedi& jedi);
	JediTemple& operator-(const Jedi& jedi);

	void printByPlanet(const Planet& planet);

	void writeAllJedi(const char* pathToFile);
};