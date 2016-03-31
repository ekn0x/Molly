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
	unsigned int b_id;
	unsigned int a_id;
	std::string Name;
	std::string Formula;

	vect0r<atom*> Atoms;

public:
	/**
	 * molecule()
	 * \Purpose: Basic constructor
	 * \Parameters: None
	 * \Returns: None
	 */
	molecule();
	/**
	 * ~molecule()
	 * \Purpose: basic destructor
 	 * \Parameters: None
	 * \Returns: None
	 */
	~molecule();

	/**
	 * display()
	 * \Purpose: print the information relative to the molecule
	 * \Parameters: None
	 * \Returns: None
	 */
	void display();
	/**
	 * 
	 * \
	 * \
	 * \
	 */
	void listAtom();
	/**
	 * insertAtom(std::string)
	 * \Purpose: add an atom to the molecule
	 * \Parameters: Symbol of the element
	 * \Returns: None
	 */
	bool insertAtom(std::string);

	/**
	 * insertBond(unsigned int, unsigned int)
	 * \Purpose: Joint two atom
	 * \Parameters: The IDs of the atoms that need to be joint
	 * \Returns: None
	 */
	//void insertBond(unsigned int, unsigned int);

	/**
	 * removeBond(unsigned int, unsigned int)
	 * \Purpose: Remove a link that joint two atom together
	 * \Parameters: The IDs of the atoms.
	 * \Returns: None
	 */
	//void removeBond(unsigned int, unsigned int);
	/**
	* removeBond(unsigned int)
	* \Purpose: Remove a link that joint two atom together
	* \Parameters: The id of the bond
	* \Returns: None
	*/
	//void removeBond(unsigned int);

};


#endif
