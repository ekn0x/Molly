#ifndef _MOLECULE_H_
#define _MOLECULE_H_

#include <string>
#include "vect0r.h"

class atom;
class bond;

/**
 * \Brieg Molecule container
 * This object provides an interface to manipulate a molecule.
 */
class molecule
{
private:
	unsigned int b_id;	//< key increment for bonds
	unsigned int a_id;	//< key increment for atoms
	std::string Name;	//< Name of the molecule
	bool Formula;		//< either true or false if the formula is up to date
	std::string Formula;	//< Formula of the molecule

	vect0r<atom*> Atoms;	//< Array of atoms

	//
	// Private Methods
	//
	
	/**
	 * \Brief Count the number of atoms of one kind
	 * \Param (std::string) Kind of element to count
	 * \Return (unsigned int)
	 */
	unsigned int countAtoms(std::string)

public:
	/**
	 * \Brief Basic constructor
	 * \Param None
	 * \Return: None
	 */
	molecule();
	/**
	 * \Brief Constructor from file stream
	 * \Param path to the file to open
	 * \Return None
	 */
	molecule(std::string);
	/**
	 * \Brief Destructor
 	 * \Param None
	 * \Return None
	 */
	~molecule();

	//
	// Atom related methods
	//
	
	/**
	 * \Brief Display one Atom and it's entourage
	 * \Param (unsigned int) node Id
	 * 	  (unsigned int) level of entourage
	 * \Return None
	 */
	void displayAtom(unsigned int, unsigned int);
	/**
	 * \Brief List atoms in the molecule
	 * \Param None
	 * \Return None
	 */
	void listAtom();
	/**
	 * \Purpose: add an atom to the molecule
	 * \Parameters: Symbol of the element
	 * \Returns: None
	 */
	bool insertAtom(std::string);
	
	//
	// Bond related methods
	//
	
	/**
	 * \Brief Joint two atom
	 * \Param The IDs of the atoms that need to be joint
	 * \Return None
	 */
	void insertBond(unsigned int, unsigned int);

	/**
	 * \Brief Remove a link that joint two atom together
	 * \Param The IDs of the atoms.
	 * \Return None
	 */
	void removeBond(unsigned int, unsigned int);
	/**
	* \Brief Remove a link that joint two atom together
	* \Param The id of the bond
	* \Return None
	*/
	void removeBond(unsigned int);

	//
	// General methods
	//
	
	/**
	 * \Brief Print the information relative to the molecule
	 * \Param None
	 * \Return None
	 */
	void display();

};


#endif
