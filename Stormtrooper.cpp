#include "stdafx.h"
#include "Stormtrooper.h"

void Stormtrooper::copy(const Stormtrooper& other) {
	this->id = new char[strlen(other.id) + 1];
	strcpy_s(this->id, strlen(other.id) + 1, other.id);
	this->rank = other.rank;
	this->type = new char[strlen(other.type) + 1];
	strcpy_s(this->type, strlen(other.type) + 1, other.type);
	this->planet = other.planet;
}
void Stormtrooper::erase() {
	delete[] this->id;
	delete[] this->type;
}

Stormtrooper::Stormtrooper() {
	this->id = new char;
	strcpy_s(this->id, 1, "");
	this->rank = Tank;
	this->type = new char;
	strcpy_s(this->type, 1, "");
}
Stormtrooper::Stormtrooper(const char* id, Stormtrooperrank rank, const char* type, Planet& planet) {
	this->id = new char[strlen(id) + 1];
	strcpy_s(this->id, strlen(id) + 1, id);
	this->rank = rank;
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
	this->planet = planet;
}
Stormtrooper::Stormtrooper(const Stormtrooper& other) {
	copy(other);
}
Stormtrooper& Stormtrooper::operator=(const Stormtrooper& other) {
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}
Stormtrooper::~Stormtrooper() {
	erase();
}

const char* Stormtrooper::getId() const {
	return this->id;
}
Stormtrooperrank Stormtrooper::getRank() const {
	return this->rank;
}
const char* Stormtrooper::getType() const {
	return this->type;
}
Planet& Stormtrooper::getPlanet() {
	return this->planet;
}
const char* Stormtrooper::getPlanetName() const {
	return planet.getName();
}

void Stormtrooper::setId(const char* id) {
	delete[] this->id;
	this->id = new char[strlen(id) + 1];
	strcpy_s(this->id, strlen(id) + 1, id);
}
void Stormtrooper::setRank(Stormtrooperrank rank) {
	this->rank = rank;
}
void Stormtrooper::setType(const char* type) {
	delete[] this->type;
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}
void Stormtrooper::setPlanet(Planet& planet) {
	this->planet = planet;
}

ostream& operator<<(ostream& os, const Stormtrooper& stormtrooper)
{
	os << stormtrooper.getId() << " " << stormtrooper.getRank() << " " << stormtrooper.getType() << " " << stormtrooper.getPlanetName() << endl;
	return os;
}

bool Stormtrooper::operator==(const Stormtrooper& other) {
	return strcmp(this->id, other.id) == 0 && this->rank == other.rank && strcmp(this->type, other.type) == 0 && this->planet == other.planet;
}