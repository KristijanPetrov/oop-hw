#include "stdafx.h"
#include "Jedi.h"


void Jedi::copy(const Jedi& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	this->rank = other.rank;
	this->midichlorian = other.midichlorian;
	this->planet = other.planet;
	this->spicies = new char[strlen(other.spicies) + 1];
	strcpy_s(this->spicies, strlen(other.spicies) + 1, other.spicies);
	this->militaryRank = new char[strlen(other.militaryRank) + 1];
	strcpy_s(this->militaryRank, strlen(other.militaryRank) + 1, other.militaryRank);
}
void Jedi::erase() {
	delete[] this->name;
	delete[] this->spicies;
	delete[] this->militaryRank;
}
Jedi::Jedi() {
	this->name = new char;
	strcpy_s(this->name, 1, "");
	this->rank = Youngling;
	this->midichlorian = 0;
	this->spicies = new char;
	strcpy_s(this->spicies, 1, "");
	this->militaryRank = new char;
	strcpy_s(this->militaryRank, 1, "");
}
Jedi::Jedi(const char* name, Jedirank rank, double midichlorian, Planet& planet, const char* spicies, const char* militaryRank) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->rank = rank;
	this->midichlorian = midichlorian;
	this->planet = planet;
	this->spicies = new char[strlen(spicies) + 1];
	strcpy_s(this->spicies, strlen(spicies) + 1, spicies);
	this->militaryRank = new char[strlen(militaryRank) + 1];
	strcpy_s(this->militaryRank, strlen(militaryRank) + 1, militaryRank);
}
Jedi::Jedi(const Jedi& other) {
	copy(other);
}
Jedi& Jedi::operator=(const Jedi& other) {
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}
Jedi::~Jedi() {
	erase();
}
const char* Jedi::getName() const {
	return this->name;
}
Jedirank Jedi::getRank() const {
	return this->rank;
}
double Jedi::getMidichlorian() const {
	return this->midichlorian;
}
Planet& Jedi::getPlanet() {
	return this->planet;
}
const char* Jedi::getSpicies() const {
	return this->spicies;
}
const char* Jedi::getMilitaryRank() const {
	return this->militaryRank;
}
const char* Jedi::getPlanetName() const {
	return planet.getName();
}
void Jedi::setName(const char* name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
void Jedi::setRank(Jedirank rank) {
	this->rank = rank;
}
void Jedi::setMidichlorian(double midichlorian) {
	this->midichlorian = midichlorian;
}
void Jedi::setPlanet(Planet& planet) {
	this->planet = planet;
}
void Jedi::setSpicies(const char* spicies)
{
	delete[] this->spicies;
	this->spicies = new char[strlen(spicies) + 1];
	strcpy_s(this->spicies, strlen(spicies) + 1, spicies);
}
void Jedi::setMilitaryRank(const char* militaryRank) {
	delete[] this->militaryRank;
	this->militaryRank = new char[strlen(militaryRank) + 1];
	strcpy_s(this->militaryRank, strlen(militaryRank) + 1, militaryRank);
}

ostream& operator<<(ostream& os, const Jedi& jedi)
{
	os << jedi.getName() << " " << jedi.getRank() << " " << jedi.getMidichlorian() << " " << jedi.getPlanetName() << " " <<
		jedi.getSpicies() << " " << jedi.getMilitaryRank() << endl;
	return os;
}
bool Jedi::operator==(const Jedi& other) {
	return strcmp(this->name, other.name) == 0 && this->rank == other.rank && this->midichlorian == other.midichlorian &&
		this->planet == other.planet && strcmp(this->spicies, other.spicies) == 0 && strcmp(this->militaryRank, other.militaryRank) == 0;
}
