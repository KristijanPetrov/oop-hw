#include "stdafx.h"
#include "PlanetSystem.h"

void PlanetSystem::copy(const PlanetSystem& other) {
	this->name = new char(strlen(other.name) + 1);
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	this->capacity = other.capacity;
	this->size = other.size;
	this->planet = new Planet[this->capacity];
	for (int i = 0;i < this->size;i++)
	{
		this->planet[i] = other.planet[i];
	}
}
void PlanetSystem::erase() {
	delete[] this->planet;
	delete[] this->name;
}
void PlanetSystem::resize() {
	this->capacity *= 2;
	Planet *temp = this->planet;
	this->planet = new Planet[capacity];
	for (int i = 0;i<size;i++) {
		this->planet[i] = temp[i];
	}
	delete[] temp;

}

PlanetSystem::PlanetSystem() {
	this->name = new char;
	strcpy_s(this->name, 1, "");
	this->size = 0;
	this->capacity = 16;
	this->planet = new Planet[this->capacity];
}
PlanetSystem::PlanetSystem(const char* name, Planet* planet, int size) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->size = size;
	this->capacity = 2 * size;
	this->planet = new Planet[this->capacity];
	for (int i = 0;i < size;i++)
	{
		this->planet[i] = planet[i];
	}
}
PlanetSystem::PlanetSystem(const PlanetSystem& other) {
	copy(other);
}
PlanetSystem& PlanetSystem::operator=(const PlanetSystem& other) {
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}
PlanetSystem::~PlanetSystem() {
	erase();
}

const char* PlanetSystem::getName() {
	return this->name;
}
Planet* PlanetSystem::getPlanet() {
	return this->planet;
}
int PlanetSystem::getSize() {
	return this->size;
}

Planet& PlanetSystem::operator[](int index) {
	return planet[index];
}
const Planet& PlanetSystem::operator[](int index)const {
	return planet[index];
}

PlanetSystem& PlanetSystem::operator+(const Planet& planet) {
	if (this->size >= this->capacity) {
		resize();
	}
	this->planet[size] = planet;
	this->size++;
	return *this;
}
PlanetSystem& PlanetSystem::operator-(const Planet& planet) {
	for (int i = 0;i < this->size;i++)
	{
		if (this->planet[i] == planet)
		{
			for (int j = i;j - 1 < this->size;j++)
			{
				this->planet[j] = this->planet[j + 1];
			}
			size--;
			i--;
		}
	}
	return *this;
}

void PlanetSystem::printAllPlanets() {
	for (int i = 0;i < this->size;i++)
	{
		cout << this->planet[i];
	}
}

bool PlanetSystem::operator==(const PlanetSystem& other) {
	for (int i = 0;i < this->size;i++) {
		if (this->planet[i] != other.planet[i]) {
			return false;
		}
	}
	return true;
}

void PlanetSystem::writeAllPlanets(const char * pathToFile)
{
	ofstream outFile;
	outFile.open(pathToFile, ios::out,ios::app);


	for (int i = 0; i < size; ++i)
	{
		outFile << planet[i].getName() << planet[i].getPlanetSystem() << planet[i].getRepublic();
	}
	outFile.close();
}

bool PlanetSystem::isDominatedBy(const char * name)
{
	if (this->size < 3) {
		return false;
	}
	int count = 0;
	for (int i = 0;i < this->size;i++)
	{
		if (planet[i].getRepublic() == name)
		{
			count++;
		}
	}
	if (count < 3)
		return false;
	return count > (this->size / 2);
}
