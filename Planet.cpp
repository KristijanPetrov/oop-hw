#include "stdafx.h"
#include "Planet.h"

void Planet::copy(const Planet& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	this->planetSystem = new char[strlen(other.planetSystem) + 1];
	strcpy_s(this->planetSystem, strlen(other.planetSystem) + 1, other.planetSystem);
	this->republic = new char[strlen(other.republic) + 1];
	strcpy_s(this->republic, strlen(other.republic) + 1, other.republic);
}

void Planet::destroy() {
	if(this->name!= nullptr)
		delete[] this->name;
	if (this->planetSystem != nullptr)
		delete[] this->planetSystem;
	if (this->republic != nullptr)
		delete[] this->republic;
}
Planet::Planet() {
	this->name = new char;
	strcpy_s(this->name, 1, "");
	this->planetSystem = new char;
	strcpy_s(this->planetSystem, 1, "");
	this->republic = new char;
	strcpy_s(this->republic, 1, "");
}
Planet::Planet(const char* name, const char* planetSystem, const char* republic) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->planetSystem = new char[strlen(planetSystem) + 1];
	strcpy_s(this->planetSystem, strlen(planetSystem) + 1, planetSystem);
	this->republic = new char[strlen(republic) + 1];
	strcpy_s(this->republic, strlen(republic) + 1, republic);
}
Planet::Planet(const Planet& other) {
	copy(other);
}

Planet& Planet::operator=(const Planet& other) {
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}
Planet::~Planet() {
	destroy();
}
const char* Planet::getName() const {
	return this->name;
}
const char* Planet::getPlanetSystem() const {
	return this->planetSystem;
}
const char* Planet::getRepublic() const {
	return this->republic;
}
void Planet::setName(const char* name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
void Planet::setPlanetSystem(const char* planetSystem) {
	delete[] this->planetSystem;
	this->planetSystem = new char[strlen(planetSystem) + 1];
	strcpy_s(this->planetSystem, strlen(planetSystem) + 1, planetSystem);
}
void Planet::setRepublic(const char* republic) {
	delete[] this->republic;
	this->republic = new char[strlen(republic) + 1];
	strcpy_s(this->republic, strlen(republic) + 1, republic);
}
bool Planet::operator==(const Planet& other) {
	return (strcmp(this->name, other.name) == 0 && strcmp(this->planetSystem, other.planetSystem) == 0 && strcmp(this->republic, other.republic) == 0);
}
bool Planet::operator!=(const Planet& other) {
	return !(this == &other);
}

ostream& operator<<(ostream& os, const Planet& planet)
{
	os << planet.getName() << " " << planet.getPlanetSystem() << " " << planet.getRepublic() << endl;
	return os;
}
