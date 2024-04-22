#include "Database.h"
#include "Bird.h"
#include "Animal.h"
#include "Fish.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <list>
#include <Algorithm>

Database::~Database()
{
	RemoveAll();
}

void Database::RemoveAll() {
	m_animals.clear();
}

void Database::Remove(Animal::eType type) {
	for (auto iter = m_animals.begin();iter != m_animals.end();) 
	{ 
		iter = std::find(iter, m_animals.end(), type);
		if (iter != m_animals.end())
		{ 
			iter = m_animals.erase(iter); } }
}




void Database::Remove(const std::string& name) {
	for (auto iter = m_animals.begin(); iter != m_animals.end();)
	{
		iter = std::find(iter, m_animals.end(), name);
		if (iter != m_animals.end())
		{
			iter = m_animals.erase(iter);
		}
	}
}

void Database::Add(Animal::eType type)
{
	std::unique_ptr<Animal> animal = Create(type);

	std::cin >> *animal;
	m_animals.push_back(std::move(animal));
}


void Database::Load(const std::string& filename)
{
	std::ifstream input(filename);
	if (input.is_open())
	{
		RemoveAll();

		while (!input.eof())
		{
			int type;
			input >> type;

			if (input.fail()) break;

			std::unique_ptr<Animal> animal = Create(static_cast<Animal::eType>(type));
			input >> *animal;
			m_animals.push_back(std::move(animal));
		}

	}
}

void Database::Save(const std::string& filename) {
	std::ofstream output(filename);
	if (output.is_open())
	{
		for (auto& animal : m_animals)
		{
			output << static_cast<int>(animal ->GetType()) << std::endl;
			output << *animal;
			//Animal* Write(std::ofstream);
		}
	}
}

std::unique_ptr<Animal>Database::Create(Animal::eType type) {
	Animal* animal = nullptr;
	switch (type)
	{ 
	case Animal::eType::Fish:
			animal = new Fish;
			break;
	case Animal::eType::Bird:
			animal = new Bird;
			break;
	default:
			break;
	}
	return std::unique_ptr<Animal>{animal};
}

void Database::DisplayAll()
{
	for (auto& animal : m_animals)
	{
		//animal->Write(std::cout);
		std::cout << *animal;

	}
}


void Database::Display(std::string name)
{
	for (auto& animal : m_animals)
	{
		if (name == animal->GetName())
		{
			std::cout << *animal;
			//animal->Write(std::cout);
		}
	}
}

void Database::Display(Animal::eType type)
{
	for (auto& animal : m_animals)
	{
		if (type == animal->GetType())
		{
			//animal->Write(std::cout);
			std::cout << *animal;
		}
	}
}

