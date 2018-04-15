#include "stdafx.h"
#include "GalacticRepublic.h"
 
void GalacticRepublic::copy(const GalacticRepublic& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	this->jediTemple = other.jediTemple;
	this->army = other.army;
	this->galaxy = other.galaxy;
}
void GalacticRepublic::erase() {
	delete[] this->name;
}
GalacticRepublic::GalacticRepublic() {
	this->name = new char;
	strcpy_s(this->name, 1, "");
}
GalacticRepublic::GalacticRepublic(const char* name, JediTemple& jediTemple, Army& army, Galaxy& galaxy) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->jediTemple = jediTemple;
	this->army = army;
	this->galaxy = galaxy;
}
GalacticRepublic::GalacticRepublic(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
GalacticRepublic::GalacticRepublic(const GalacticRepublic& other) {
	copy(other);
}
GalacticRepublic& GalacticRepublic::operator=(const GalacticRepublic& other) {
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}
GalacticRepublic::~GalacticRepublic() {
	erase();
}

const char* GalacticRepublic::getName() {
	return this->name;
}
JediTemple& GalacticRepublic::getJediTemle() {
	return this->jediTemple;
}
Army& GalacticRepublic::getArmy() {
	return this->army;
}
Galaxy& GalacticRepublic::getGalaxy() {
	return this->galaxy;
}

bool GalacticRepublic::dominates()
{
	return this->army.getSize() > this->jediTemple.getSize() && this->galaxy.isDominatedBy(this->name);
}
