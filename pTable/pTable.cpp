#include "pTable.h"
#include "/group/group.h"
#include "/element/element.h"

#include <iostream>
#include <fstream>
#include <string>

pTable::~pTable()
{
	std::cout << "> PT Destructor" << std::endl;
	

	system("PAUSE");
}

pTable& pTable::getInstance()
{
	static pTable instance;

	return instance;
}

bool pTable::initpTable(std::string fileName)
{
	if (this->INITIALIZED)
		return true; // if the periodic table is already initialized

	std::ifstream src;
	src.open(fileName);
	if (src.is_open())
	{
		// Validate the file
		if (src.peek() == 'P')
		{
			// get the name;
			src.seekg(2, std::ios_base::cur);
			getline(src, Name);
			std::cout << "> " << Name << std::endl;
			this->SrcName = fileName;
		}
		else
			return false;

		while (!src.eof())
		{
			// if it's a group
			if (src.peek() == 'G')
			{
				GList.Insert(new group(src));
			}
			// if it's an element
			else if (src.peek() == 'E')
			{
				EList.Insert(new element(src));
			}
		}

		this->INITIALIZED = true;
		src.close();
		return true;
	}

	return false;
}

void pTable::displayGroup()
{
	for (unsigned int i = 0; i < GList.getSize(); ++i)
	{
		std::cout << "> " << GList[i]->getName() << std::endl;
	}
}

group* pTable::findGroup(unsigned int v)
{
	group *gr = nullptr;
	for (unsigned int i = 0; i < GList.getSize(); ++i)
	{
		if (GList[i]->getId() == v)
			gr = GList[i];
	}

	return gr;
}

void pTable::displayElement()
{
	for (unsigned int i = 0; i < EList.getSize(); ++i)
	{
		std::cout << "> " << EList[i]->getName() << " [" << EList[i]->getSymbol() << "]"
			<< " (" << EList[i]->getGroup()->getName() << ")" << std::endl;
	}
}

element* pTable::FindElement(std::string s)
{
	element *e = nullptr;
	for (unsigned int i = 0; i < EList.getSize(); ++i)
	{
		if (s.compare(EList[i]->getSymbol()) == 0)
			e = EList[i];
	}

	return e;
}
