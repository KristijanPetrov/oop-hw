#include "stdafx.h"
#include "JediTemple.h"

void JediTemple::copy(const JediTemple& other) {
	this->capacity = other.capacity;
	this->size = other.size;
	this->jedi = new Jedi[this->capacity];
	for (int i = 0;i < this->size;i++)
	{
		this->jedi[i] = other.jedi[i];
	}
}
void JediTemple::erase() {
	delete[] this->jedi;
}
void JediTemple::resize() {
	this->capacity *= 2;
	Jedi *temp = this->jedi;
	this->jedi = new Jedi[capacity];
	for (int i = 0;i<size;i++) {
		this->jedi[i] = temp[i];
	}
	delete[] temp;

}

JediTemple::JediTemple() {
	this->size = 0;
	this->capacity = 16;
	this->jedi = new Jedi[this->capacity];
}
JediTemple::JediTemple(Jedi* jedi, int size) {
	this->size = size;
	this->capacity = 2 * size;
	this->jedi = new Jedi[this->capacity];
	for (int i = 0;i < size;i++)
	{
		this->jedi[i] = jedi[i];
	}
}
JediTemple::JediTemple(const JediTemple& other) {
	copy(other);
}
JediTemple& JediTemple::operator=(const JediTemple& other) {
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}
JediTemple::~JediTemple() {
	erase();
}

Jedi* JediTemple::getJedi() {
	return this->jedi;
}
int JediTemple::getSize() {
	return this->size;
}

Jedi& JediTemple::operator[](int index) {
	return jedi[index];
}
const Jedi& JediTemple::operator[](int index)const {
	return jedi[index];
}

JediTemple& JediTemple::operator+(const Jedi& jedi) {
	if (this->size >= this->capacity) {
		resize();
	}
	this->jedi[size] = jedi;
	this->size++;
	return *this;
}
JediTemple& JediTemple::operator-(const Jedi& jedi) {
	for (int i = 0;i < this->size;i++)
	{
		if (this->jedi[i] == jedi)
		{
			for (int j = i;j - 1 < this->size;j++)
			{
				this->jedi[j] = this->jedi[j + 1];
			}
			size--;
			i--;
		}
	}
	return *this;
}

void JediTemple::printByPlanet(const Planet& planet) {
	for (int i = 0;i < this->size;i++)
	{
		if (this->jedi[i].getPlanet() == planet) {
			cout << this->jedi[i];
		}
	}
}

void JediTemple::writeAllJedi(const char* pathToFile)
{
	ofstream outFile;
	outFile.open(pathToFile, ios::out);


	for (int i = 0; i < size; ++i)
	{
		outFile << jedi[i].getName() << jedi[i].getRank() << jedi[i].getMidichlorian() << jedi[i].getPlanetName() << jedi[i].getSpicies()
			<< jedi[i].getMilitaryRank();
	}
	outFile.close();
}
