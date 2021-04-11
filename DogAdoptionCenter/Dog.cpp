#include "Dog.h"
#include <sstream>
#include <iostream>


Dog::Dog()
{
	this->id = this->current_id;
	this->name = "";
	this->breed = "";
	this->age = 0;
	this->photo_link = "";

	this->current_id++;
}

Dog::Dog(std::string _name, std::string _breed, int _age, std::string _photo_link) : name{ _name }, breed{ _breed }, age{ _age }, photo_link{ _photo_link }
{
	this->id = this->current_id;
	this->current_id++;
}

Dog::~Dog()
{
}

std::string Dog::ToString() const
{
	std::stringstream buffer;
	buffer << "Id: " << this->id << "; Name: " << this->name << "; Breed: " << this->breed << "; Age: " << this->age << "; Photo: " << this->photo_link << " \n";
	return buffer.str();
}

int Dog::get_id()
{
	return this->id;
}

std::string Dog::get_name()
{
	return this->name;
}

std::string Dog::get_breed()
{
	return this->breed;
}

int Dog::get_age()
{
	return this->age;
}

std::string Dog::get_photoLink()
{
	return this->photo_link;
}

void Dog::set_id(int id)
{
	this->id = id;
}



int Dog::current_id = 0;