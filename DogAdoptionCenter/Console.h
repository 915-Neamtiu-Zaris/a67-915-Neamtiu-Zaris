#pragma once
// Console module

#include "Service.h"
#include <iostream>
#include <sstream>

class Console {
private:
	Service s;

public:

	Console();
	~Console();

	void printInitialPrompt();
	void printAdminMenu();
	void printUserMenu();
	void printAdoptionPrompt();
	void runConsole();
};

Console::Console()
{
}

Console::~Console()
{
}

void Console::printInitialPrompt()
{
	std::cout << "\nSelect the mode you would like to use the application in:"
		"\na - Administrator mode.\nu - User mode.\n";
}

void Console::printAdminMenu()
{
	std::cout << "\n1 - Add a dog.\n2 - Remove a dog.\n3 - Update a dog.\n4 - Print all dogs.\n5 - Exit.\n";
}

void Console::printUserMenu()
{
	std::cout << "\n1 - View dogs.\n2 - Filter dogs by breed, with maximum age.\n3 - See adoption list.\n4 - Exit\n";
}

inline void Console::printAdoptionPrompt()
{
	std::cout << "\n1 - Adopt.\n2 - See dog's photo.\n3 - Next.\n4 - See adoption list.\n5 - Return.\n";
}

inline void Console::runConsole()
{
	this->s.add10Dogs();
	char initialCommand;

	while (true)
	{
		try
		{
			std::cin.exceptions(std::iostream::failbit);
			this->printInitialPrompt();

			std::cin >> initialCommand;

			if (initialCommand == 'a')
			{
				while (true)
				{
					this->printAdminMenu();

					int command;
					std::cin >> command;

					if (command == 1)
					{
						std::string name;
						std::string breed;
						int age;
						std::string photo_link;

						std::cout << "Name: ";
						std::cin >> name;
						std::cout << "Breed: ";
						std::cin >> breed;
						std::cout << "Age: ";
						std::cin >> age;
						std::cout << "Photo link: ";
						std::cin >> photo_link;

						this->s.addDogByVars(name, breed, age, photo_link);
					}
					else if (command == 2)
					{
						int id;
						std::cout << "The id of the dog to be removed: ";
						std::cin >> id;
						try
						{
							this->s.removeDogById(id);
						}
						catch (int ex)
						{
							if (ex == 21)
								std::cout << "The dog you are trying to remove does not exist.\n";
						}
					}
					else if (command == 3)
					{
						int id;
						std::string name;
						std::string breed;
						int age;
						std::string photo_link;

						std::cout << "The id of the dog you want to update: ";
						std::cin >> id;
						std::cout << "Name: ";
						std::cin >> name;
						std::cout << "Breed: ";
						std::cin >> breed;
						std::cout << "Age: ";
						std::cin >> age;
						std::cout << "Photo link: ";
						std::cin >> photo_link;

						try
						{
							this->s.updateDogById(id, name, breed, age, photo_link);
						}
						catch (int ex)
						{
							if (ex == 21)
								std::cout << "The dog you are trying to update does not exist.\n";
						}
					}
					else if (command == 4)
					{
						Dog* dogs = this->s.getAllDogs();
						int nrDogs = this->s.getNrDogs();

						for (int i = 0; i < nrDogs; ++i)
							std::cout << dogs[i].ToString();
					}
					else if (command == 5)
						return;
				}
			}
			else if (initialCommand == 'u')
			{
				while (true)
				{
					this->printUserMenu();
					int command;
					std::cin >> command;

					if (command == 1)
					{
						bool go = true;
						int ind = 0;
						int nrDogs = this->s.getNrDogs();
						Dog* dogs = this->s.getAllDogs();
						int cmd;

						while (go)
						{
							std::cout << "\nCurrent dog: " << dogs[ind % nrDogs].ToString() << "\n";
							this->printAdoptionPrompt();

							std::cin >> cmd;

							if (cmd == 1)
							{
								// Adding to adoption list.
								this->s.addToAdoptionList(dogs[ind % nrDogs]);

								// Removing from dog repo.
								this->s.removeDogById(dogs[ind % nrDogs].get_id());

								// Refresh dog list.
								dogs = this->s.getAllDogs();
								nrDogs = this->s.getNrDogs();
								ind++;
							}
							else if (cmd == 2)
							{
								system(std::string("start " + dogs[ind % nrDogs].get_photoLink()).c_str());
							}
							else if (cmd == 3)
							{
								ind++;
							}
							else if (cmd == 4)
							{
								std::cout << "\nAdoption list: \n";

								Dog* dogs = this->s.getAdoptedDogs();
								int nrDogs = this->s.getNrAdoptedDogs();

								for (int i = 0; i < nrDogs; ++i)
									std::cout << dogs[i].ToString();

								std::cout << '\n';
							}
							else if (cmd == 5)
							{
								go = false;
							}
						}
					}
					else if (command == 2)
					{
						std::string breed;
						int age;
						std::getchar();
						std::cout << "The breed that you want to filter by: ";
						std::getline(std::cin, breed);
						std::istringstream iss(breed);
						std::cout << "The age that you want to filter by: ";
						std::cin >> age;

						Dog filteredDogs[101];

						int nrDogs = this->s.filterDogsBreedAge(breed, age, filteredDogs);

						if (nrDogs == 0)
						{

							Dog* dogs = this->s.getAllDogs();
							int nrDogs = this->s.getNrDogs();

							for (int i = 0; i < nrDogs; ++i)
								std::cout << dogs[i].ToString();
						}
						else
						{
							for (int i = 0; i < nrDogs; ++i)
								std::cout << filteredDogs[i].ToString();
						}
					}
					else if (command == 3)
					{
						Dog* dogs = this->s.getAdoptedDogs();
						int nrDogs = this->s.getNrAdoptedDogs();

						std::cout << "\nAdoption list: \n";
						for (int i = 0; i < nrDogs; ++i)
							std::cout << dogs[i].ToString();
					}
					else if (command == 4)
					{
						return;
					}
				}
			}
		}
		catch (std::iostream::failure e)
		{
			//std::cerr << "Exception reading info\n";
			//std::getchar();
			std::cout << "Incorrect input!";
			return;
		}
	}
}
