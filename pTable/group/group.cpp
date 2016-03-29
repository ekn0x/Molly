#include "group.h"

#include <iostream>
#include <fstream>
//#include <string>

group::group()
{
	std::cout << "> group constructor" << std::endl;
}

group::group(std::string s)
{
	this->Name = s;
	std::cout << "> group constructor (" << this << ")" << std::endl;
}

group::group(std::ifstream &src)
{
	//
	// Example:
	//G, 1, Alkali metals, 1,
	//
	std::string tmp;
	// skip the G
	src.seekg(2, std::ios_base::cur);
	// get groupe id
	getline(src, tmp, ',');
	this->Id = stoi(tmp);
	// get name
	getline(src, this->Name, ',');
	// get group valence electron
	getline(src, tmp, ',');
	this->Valence = stoi(tmp);
	// change line;
	src.seekg(2, std::ios_base::cur);
}

group::group(const group &src)
{
	std::cout << "> group copy constructor" << std::endl;
	this->Id = src.Id;
	this->Name = src.Name;
}

group::~group()
{
	std::cout << "> group destructor (0x" << this << ")" << std::endl;
}

group& group::operator = (const group &src)
{
	std::cout << "> group copy constructor" << std::endl;
	this->Id = src.Id;

	this->Name = src.Name;

	return *this;
}
