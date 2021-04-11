// Service module
#pragma once
#include "Repository.h"
#include "Dog.h"
#include <string>

class Service {
private:
	Repository<Dog> repo;
	Repository<Dog> adoptionList;

public:

	Service();
	~Service();

	void addDogByVars(std::string name, std::string breed, int age, std::string link_photo);
	void removeDogById(int id);
	void updateDogById(int id, std::string name, std::string breed, int age, std::string link_photo);
	Dog* getAllDogs();
	int getNrDogs();
	void add10Dogs();
	int filterDogsBreedAge(std::string breed, int age, Dog* filteredDogs);
	Dog* getAdoptedDogs();
	int getNrAdoptedDogs();
	void addToAdoptionList(Dog d);
};

Service::Service()
{
}

Service::~Service()
{
}

inline void Service::addDogByVars(std::string name, std::string breed, int age, std::string link_photo)
{
	Dog d(name, breed, age, link_photo);
	this->repo.add(d);
}

inline void Service::removeDogById(int id)
{
	if(this->repo.existsElem(id))
		this->repo.removeById(id);
	else
	{
		throw 21;
	}
}

inline void Service::updateDogById(int id, std::string name, std::string breed, int age, std::string link_photo)
{
	if (this->repo.existsElem(id))
	{
		Dog dUpdate(name, breed, age, link_photo);
		this->repo.updateElem(id, dUpdate);
	}
	else
		throw 21;
}

inline Dog* Service::getAllDogs()
{
	return this->repo.getAllElements();
}

inline int Service::getNrDogs()
{
	return this->repo.getNrElements();
}

inline void Service::add10Dogs()
{
	Dog d1("Bobita", "Yorkshire Terrier", 11, "https://www.pexels.com/photo/two-yellow-labrador-retriever-puppies-1108099/");
	Dog d2("Rex", "German Shepherd", 2, "https://www.pexels.com/photo/brown-and-white-short-coated-puppy-1805164/");
	Dog d3("Thor", "Bulldog", 6, "https://www.pexels.com/photo/short-coated-tan-dog-2253275/");
	Dog d4("Avalach", "Siberian Husky", 1, "https://www.pexels.com/photo/cute-puppy-wearing-a-party-hat-4588047/");
	Dog d5("Astral", "Siberian Husky", 8, "https://www.pexels.com/photo/short-coated-brown-dog-sitting-inside-a-car-2797318/");
	Dog d6("Pumba", "Chihuahua", 1, "https://www.pexels.com/photo/photo-of-dog-lying-on-bed-1839753/");
	Dog d7("Bono", "Doberman", 9, "https://www.pexels.com/photo/brown-pomeranian-puppy-on-grey-concrete-floor-3687770/");
	Dog d8("Cora", "Bichon", 4, "https://www.pexels.com/photo/white-and-brown-short-coated-dog-4587971/");
	Dog d9("Bobo", "Dalmatian", 6, "https://www.pexels.com/photo/brown-and-white-dog-wearing-yellow-knit-cap-4588052/");
	Dog d10("Terry", "Rottweiler", 1, "https://www.pexels.com/photo/white-and-black-siberian-husky-puppy-3663082/");

	this->repo.add(d1);
	this->repo.add(d2);
	this->repo.add(d3);
	this->repo.add(d4);
	this->repo.add(d5);
	this->repo.add(d6);
	this->repo.add(d7);
	this->repo.add(d8);
	this->repo.add(d9);
	this->repo.add(d10);
}

inline int Service::filterDogsBreedAge(std::string breed, int age, Dog* filteredDogs)
{
	Dog* dogs = this->getAllDogs();
	int nrDogs = this->getNrDogs();

	if (breed == "")
		return 0;

	int nrTBR = 0;

	for (int i = 0; i < nrDogs; ++i)
		if (dogs[i].get_breed() == breed && dogs[i].get_age() < age)
		{
			filteredDogs[nrTBR] = dogs[i];
			nrTBR++;
		}

	return nrTBR;
}

inline Dog* Service::getAdoptedDogs()
{
	return this->adoptionList.getAllElements();
}

inline int Service::getNrAdoptedDogs()
{
	return this->adoptionList.getNrElements();
}

inline void Service::addToAdoptionList(Dog d)
{
	this->adoptionList.add(d);
}

