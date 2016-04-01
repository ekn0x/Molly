#ifndef _BOND_H_
#define _BOND_H_

class bond;
class atom;

/**
 * \Brieg Molecule container
 * This object provides an interface to manipulate a molecule.
 */
class bond
{
private:
	unsigned int id;
	unsigned short bondType;
	atom *left;
	atom *right;

public:
  //
  // Bond type public
  //
  
  /* Covalent bond */
  const unsigned short Covalent = 0xF800;
  /* Ionic bond */
  const unsigned short Ionic = 0x07E0;
  /* Metallic bond */
  const unsigned short Metallic = 0x001F;

	/**
	 * \Brief Basic constructor
	 * \Param None
	 * \Return None
	 */
	bond();
	/**
	 * \Brief Basic constructor
	 * \Param (atom*) First atom to be bonded
	 *        (atom*) Second atom to be bonded
	 *        (unsigned short) Kind of bond between the two atoms
	 * \Return None
	 */
	bond(atom*, atom*, unsigned int);
	/**
	 * \Brief basic destructor
	 * \Param None
	 * \Return None
	 */
	~bond();

	/**
	 * \brief Print the information relative to the bond
	 * \Param None
	 * \Return None
	 */
	void display();
};


#endif
