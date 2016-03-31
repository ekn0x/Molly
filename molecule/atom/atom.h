#ifndef _ATOM_H_
#define _ATOM_H_

#include "../../pTable/element/element.h"
#include "../../vect0r.h"

class element;
class bond;

/**
 * \Brief Molecule container
 * This object provides an interface to manipulate a molecule.
 */
class atom
{
private:
	unsigned int id;  //< Unique ID of the atom
	element* Identity; //< Pointer to an element

	vect0r<bond*> bonds; //< Array of bonds

public:
	/**
	 * \Brief Basic constructor
	 * \Param None
	 * \Return None
	 */
	atom();
	/**
	 * atom()
	 * \Brief Constructor with element and id
	 * \Param pointer to the kind of element, and id of the atom
	 * \Return None
	 */
	atom(element*, unsigned int);
	/**
	 * ~atom()
	 * \Brief basic destructor
	 * \Param None
	 * \Return None
	 */
	~atom();

	/**
	 * insertBond()
	 * \Brief Add a new connection to the atom
	 * \Param (bond*) pointer to a bond
	 * \Return bool (either if the operation succeeded or not)
	 */
	bool insertBond(bond*);
	/**
	 * display()
	 * \Brief print the information relative to the atom
	 * \Param None
	 * \Return None
	 */
	void display();

	inline unsigned int getId() { return id; };
	inline std::string getElementName() { return Identity->getName; };
};

#endif
