#include "molecule.h"

#include <iostream>
#include <fstream>
#include <string>

/**
 * \Brief Count the number of atoms of one kind
 * \Param (std::string) Kind of element to count
 * \Return (unsigned int)
 */
unsigned int countAtoms(std::string)
/**
 * \Brief Auto define the formula of the molecule
 * \Param None
 * \Return None
 */
void autoDefineFormula();

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
 * \Brief Add an atom to the molecule
 * \Param (std::string) Symbol of the element
 * \Return (bool) true if it works, false if it didn't
 */
bool insertAtom(std::string);
/**
 * \Brief Remove an atom from the molecule
 * \Param (unsigned int) Id of the atom
 * \Returns (bool) true if it works, false if it didn't
 */
bool removeAtom(std::string);
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
void display();
