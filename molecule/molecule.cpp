#include "molecule.h"
#include "../vect0r.h"

#include <iostream>
#include <fstream>
#include <string>

/**
 * \Brief Count the number of atoms of one kind
 * \Param (std::string) Kind of element to count
 * \Return (unsigned int)
 */
unsigned int countAtoms(std::string str)
{
	int counter = 0;
	element* e = pTable::getInstance().findElement(str);

	if(e)
	{
		for (unsigned int i =0; i<Atoms.getSize(); ++i)
		{
			if(str.compare(atoms[i]->getElement()->getSymbol())==0)
				++counter;
		}
	}
	return counter;
}
/**
 * \Brief Auto define the formula of the molecule
 * \Param None
 * \Return None
 */
void autoDefineFormula()
{
	element* e;
	std::string symbol;
	
	// this vect0r do not own the object
	vect0r<element*> eList;
	// could potentially cause problems
	vect0r<int> qtyElement;
	
	for(unsigned int i = 0; i < Atoms.getSize(); ++i)
	{
		e = Atoms[i]->getElement();
		symbol = e->getSymbol();
		if(!pTable::getInstance().findElement(symbol))
		{
			eList.Insert(e);
			qtyElement.Insert(countAtoms(symbol));
		}
	}
}

/**
 * \Brief Basic constructor
 * \Param None
 * \Return: None
 */
molecule() : 
	b_id(0), a_id(0),
	B_Name(false), B_Formula(false),
	Name(""), Formula("")
{
	// nothing
}
/**
 * \Brief Constructor from file stream
 * \Param path to the file to open
 * \Return None
 */
molecule(std::string) :
	b_id(0), a_id(0),
	B_Name(false), B_Formula(false),
	Name(""), Formula("")
{
	// Open a file 
	// Custom function to load information
}
/**
 * \Brief Destructor
  * \Param None
 * \Return None
 */
~molecule()
{
	// Clear arrays
	for (unsigned int i = 0; i<Atoms.getSize(); ++i)
	{
		delete Atoms[i];
		Atoms[i] = nullptr;
	}
}

//
// Atom related methods
//

/**
 * \Brief Display one Atom and it's entourage
 * \Param (unsigned int) node Id
 * 	  (unsigned int) level of entourage
 * \Return None
 */
void displayAtom(unsigned int id, unsigned int lvl)
{
	int activeLevel =0;
	do
	{
		std::cout << "> Level of proximity : " << lvl << std::endl;
	} while(activeLevel<lvl);
}
/**
 * \Brief List atoms in the molecule
 * \Param None
 * \Return None
 */
void listAtom()
{
	std::cout << "> Atoms list" << std::endl;
	std::cout << "> (Id) Element Name [symbol]" << std::endl;
	for (unsigned int i = 0; i < Atoms.getSize(); ++i)
	{
		std::cout << "> (" << Atoms[i].getId() << ") " << Atoms[i].getElementName() 
			<< " [" << Atoms[i].getElementSymbol() << "]" << std::endl;
	}
}
/**
 * \Brief Add an atom to the molecule
 * \Param (std::string) Symbol of the element
 * \Return (bool) true if it works, false if it didn't
 */
bool insertAtom(std::string sym)
{
	atom* a = new atom(sym);
	if(a) // test if the element was found
		Atoms.Insert(a);
	else
		return false;
		
	return true;
}
/**
 * \Brief Remove an atom from the molecule
 * \Param (unsigned int) Id of the atom
 * \Returns (bool) true if it works, false if it didn't
 */
bool removeAtom(unsigned int id)
{

}
/**
 * \Brief Remove an atom from the molecule
 * \Param (unsigned int) Id of the atom
 * 	  (std::string) Symbol of the new element
 * \Returns (bool) true if it works, false if it didn't
 */
bool editAtom(unsigned int);

//
// Bond related methods
//

/**
 * \Brief Joint two atom
 * \Param The IDs of the atoms that need to be joint
 * \Return (bool) true if it works, false if it didn't
 */
bool insertBond(unsigned int, unsigned int);
/**
 * \Brief Remove a link that joint two atom together
 * \Param The IDs of the atoms.
 * \Return (bool) true if it works, false if it didn't
 */
bool removeBond(unsigned int, unsigned int);
/**
* \Brief Remove a link that joint two atom together
* \Param The id of the bond
* \Return (bool) true if it works, false if it didn't
*/
bool removeBond(unsigned int);
/**
* \Brief force set the type of the bond (Covalent, Ionic or Metallic)
* \Param (bond::type) Type of the bond
* \Return (bool) true if it works, false if it didn't
*/
bool editBond(bond::type);

//
// General methods
//

/**
 * \Brief Print the information relative to the molecule
 * \Param None
 * \Return None
 */
void display()
{
	for (unsigned int i = 0; i < Atoms.getSize(); ++i)
	{
		Atoms[i]->display();
	}
}
