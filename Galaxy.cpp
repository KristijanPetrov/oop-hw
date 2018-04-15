#include "stdafx.h"
#include "Galaxy.h"

void Galaxy::copy(const Galaxy& other) {
	this->name = new char(strlen(other.name) + 1);
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	this->capacity = other.capacity;
	this->size = other.size;
	this->planetSystem = new PlanetSystem[this->capacity];
	for (int i = 0;i < this->size;i++)
	{
		this->planetSystem[i] = other.planetSystem[i];
	}
}
void Galaxy::erase() {
	delete[] this->planetSystem;
	delete[] this->name;
}
void Galaxy::resize() {
	this->capacity *= 2;
	PlanetSystem *temp = this->planetSystem;
	this->planetSystem = new PlanetSystem[capacity];
	for (int i = 0;i<size;i++) {
		this->planetSystem[i] = temp[i];
	}
	delete[] temp;

}

Galaxy::Galaxy() {
	this->name = new char;
	strcpy_s(this->name, 1, "");
	this->size = 0;
	this->capacity = 16;
	this->planetSystem = new PlanetSystem[this->capacity];
}
Galaxy::Galaxy(const char* name,PlanetSystem* planetSystem, int size) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->size = size;
	this->capacity = 2 * size;
	this->planetSystem = new PlanetSystem[this->capacity];
	for (int i = 0;i < size;i++)
	{
		this->planetSystem[i] = planetSystem[i];
	}
}
Galaxy::Galaxy(const Galaxy& other) {
	copy(other);
}
Galaxy& Galaxy::operator=(const Galaxy& other) {
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}
Galaxy::~Galaxy() {
	erase();
}

const char* Galaxy::getName() {
	return this->name;
}
PlanetSystem* Galaxy::getPlanetSystem() {
	return this->planetSystem;
}
int Galaxy::getSize() {
	return this->size;
}

PlanetSystem& Galaxy::operator[](int index) {
	return planetSystem[index];
}
const PlanetSystem& Galaxy::operator[](int index)const {
	return planetSystem[index];
}

Galaxy& Galaxy::operator+(const PlanetSystem& planetSystem) {
	if (this->size >= this->capacity) {
		resize();
	}
	this->planetSystem[size] = planetSystem;
	this->size++;
	return *this;
}
Galaxy& Galaxy::operator-(const PlanetSystem& planetSystem) {
	for (int i = 0;i < this->size;i++)
	{
		if (this->planetSystem[i] == planetSystem)
		{
			for (int j = i;j - 1 < this->size;j++)
			{
				this->planetSystem[j] = this->planetSystem[j + 1];
			}
			size--;
			i--;
		}
	}
	return *this;
}

void Galaxy::printAllPlanetsInGalaxy() {
	for (int i = 0;i < this->size;i++)
	{
		this->planetSystem[i].printAllPlanets();
	}
}

void Galaxy::writeAllPlanetsInGalaxy(const char * pathToFile)
{
	for (int i = 0;i < size;i++)
	{
		this->planetSystem[i].writeAllPlanets(pathToFile);
	}
}

bool Galaxy::isDominatedBy(const char * name)
{
	int count = 0;
	for (int i = 0;i < this->size;i++)
	{
		if (this->planetSystem[i].isDominatedBy(name))
			count++;
	}
	return count > (this->size / 2);
}
