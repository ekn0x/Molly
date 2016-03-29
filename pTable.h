/**
 * \Class pTable
 * \Brief Provide a single instance of a periodic table
 * 
 * Provide an access to any element of the periodic table whereever 
 * 
 * \Author ekn0x
 * \version 0.99
 * 
 */
#ifndef _PTABLE_H_
#define _PTABLE_H_

#include <string>
#include "vect0r.h"

// pre declared class
class group;
class element;

class pTable
{
private:
	bool INITIALIZED;	//< State of the periodic table (initialized or not)
	std::string Name;	//< Name of the periodic table
	std::string SrcName;	//< Sourcefile

	vect0r<group*> GList;	//< Array of the chemical group
	vect0r<element*> EList;	//< Array of the chemical element

protected:
	/**
	 * \Brief Default constructor
	 * \Param None
	 * \Return None
	 */
	pTable() : INITIALIZED(false) { };

public:
	/**
	 * \Brief deconstructor
	 * \Param None
	 * \Return None
	 */
	~pTable();

	/**
	 * \Brief Return the sole and only instance of the periodic table
	 * \Param None
	 * \Return (pTable&) instance of the of the periodic table
	 */
	static pTable& getInstance();
	/*
	 * \Brief Initializer of the periodic table
	 * \Param (std::string) Name of the file
	 * \Return (bool) If the periodic table was initalized or not
	 */
	bool initpTable(std::string);

	/**
	 * \Brief return the name of the periodic table
	 * \Param None
	 * \Return (std::string) (the name of the periodic table)
	 */
	inline std::string getName() { return this->Name; };
	/**
	 * \Brief return if the periodic table is initialized or not
	 * \Param None
	 * \Return (bool) if the periodic is initialized or not
	 */
	inline bool getInitialized() { return this->INITIALIZED; };

	/**
	 * \Brief Print out the periodic table
	 * \Param None
	 * \Return None
	 */
	void displayGroup();
	/**
	 * \Brief To find a group within the periodic table
	 * \Param (unsigned int) id of the group
	 * \Return (group*) pointer to the group or nullptr;
	 */
	group* findGroup(unsigned int);
	/**
	 * \Brief Remove a group from the list
	 * \Param (unsigned int) id of the group to be removed
	 * \Return (bool) if the group was removed or not
	 */
// bool removeGroup(unsigned int);

	/**
	 * \Brief Print out all of the element
	 * \Param None
	 * \Return None
	 */
	void displayElement();
	/**
	 * \Brief Find an element based on it's symbol
	 * \Param (std::string) the symbol of the element
	 * \Return (element*) the element or nullptr
	 */
	element* FindElement(std::string);
	/*
	 * \Brief Remove an element from the list
	 * \Param (std::string) symbol of the element 
	 * \Return (bool) If the element was removed or not
	 */
//	bool removeElement(Element*);
};

#endif // _PTABLE_H_
