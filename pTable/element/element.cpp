#include "../pTable.h"
#include "element.h"

#include <iostream>
#include <fstream>
#include <string>

element::element(std::ifstream &src)
{
	//E,14,Silicon,Si,14,14,14,1.90f,
	std::string tmp;
	src.seekg(2, std::ios_base::cur);
	// group id
	getline(src, tmp, ',');
	family = pTable::getInstance().findGroup(stoi(tmp));
	// name
	getline(src, Name, ',');
	//symbol
	getline(src, Symbol, ',');
	// proton
	getline(src, tmp, ',');
	// Proton = stoi(tmp);
	// neutron
	getline(src, tmp, ',');
	// Neutron = stoi(tmp);
	// electrons
	getline(src, tmp, ',');
	// Electron = stoi(tmp);
	// electronegativity
	getline(src, tmp, ',');
	// electroNegativity = stof(tmp);
	src.seekg(2, std::ios_base::cur);
}

element::element(const element &cpy)
{
	std::cout << "> element copy constructor" << std::endl;
	this->Name = cpy.Name;
	this->Symbol = cpy.Symbol;
}

element::~element()
{
	std::cout << "> element destructor (0x" << this << ")" << std::endl;
}

void element::display()
{
	std::cout << "> " << Name << " [" << Symbol << "]" << std::endl;
}
