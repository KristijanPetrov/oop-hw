#include "stdafx.h"
#include "Army.h"

void Army::copy(const Army& other) {
	this->capacity = other.capacity;
	this->size = other.size;
	this->stormtrooper = new Stormtrooper[this->capacity];
	for (int i = 0;i < this->size;i++)
	{
		this->stormtrooper[i] = other.stormtrooper[i];
	}
}
void Army::erase() {
	delete[] this->stormtrooper;
}
void Army::resize() {
	this->capacity *= 2;
	Stormtrooper *temp = this->stormtrooper;
	this->stormtrooper = new Stormtrooper[capacity];
	for (int i = 0;i<size;i++) {
		this->stormtrooper[i] = temp[i];
	}
	delete[] temp;

}

Army::Army() {
	this->size = 0;
	this->capacity = 16;
	this->stormtrooper = new Stormtrooper[this->capacity];
}
Army::Army(Stormtrooper* stormtrooper, int size) {
	this->size = size;
	this->capacity = 2 * size;
	this->stormtrooper = new Stormtrooper[this->capacity];
	for (int i = 0;i < size;i++)
	{
		this->stormtrooper[i] = stormtrooper[i];
	}
}
Army::Army(const Army& other) {
	copy(other);
}
Army& Army::operator=(const Army& other) {
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}
Army::~Army() {
	erase();
}

Stormtrooper* Army::getStormtrooper() {
	return this->stormtrooper;
}
int Army::getSize() {
	return this->size;
}

Stormtrooper& Army::operator[](int index) {
	return stormtrooper[index];
}
const Stormtrooper& Army::operator[](int index)const {
	return stormtrooper[index];
}

Army& Army::operator+(const Stormtrooper& stormtrooper) {
	if (this->size >= this->capacity) {
		resize();
	}
	this->stormtrooper[size] = stormtrooper;
	this->size++;
	return *this;
}
Army& Army::operator-(const Stormtrooper& stormtrooper) {
	for (int i = 0;i < this->size;i++)
	{
		if (this->stormtrooper[i] == stormtrooper)
		{
			for (int j = i;j - 1 < this->size;j++)
			{
				this->stormtrooper[j] = this->stormtrooper[j + 1];
			}
			size--;
			i--;
		}
	}
	return *this;
}

void Army::printByPlanet(const Planet& planet) {
	for (int i = 0;i < this->size;i++)
	{
		if (this->stormtrooper[i].getPlanet() == planet) {
			cout << this->stormtrooper[i];
		}
	}
}

void Army::writeAllStormtroopers(const char * pathToFile)
{
	ofstream outFile;
	outFile.open(pathToFile, ios::out);


	for (int i = 0; i < size; ++i)
	{
		outFile << stormtrooper[i].getId() << stormtrooper[i].getRank() << stormtrooper[i].getType() << stormtrooper[i].getPlanetName();
	}
	outFile.close();
}
