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
	bool INITIALIZED;
	std::string Name;
	std::string SrcName;

	vect0r<group*> GList;
	vect0r<element*> EList;

protected:
	/*
	 * pTable()
	 * \Purpose: default constructor
	 * \Parameter: None
	 * \return: None
	 */
	pTable() : INITIALIZED(false) { };

public:
	/*
	 * ~pTable()
	 * \Purpose: deconstructor
	 * \Parameter: None
	 * \return: None
	 */
	~pTable();

	/*
	 * getInstance()
	 * \Purpose: Return the sole and only instance of the periodic table
	 * \Parameter: None
	 * \return: instance of the of the periodic table
	 */
	static pTable& getInstance();
	/*
	 * InitPTable(std::string)
	 * \Purpose: Initializer of the periodic table
	 * \Parameter: Name of the file
	 * \return: true or false depending if the periodic table is initalized or not
	 */
	bool initpTable(std::string);

	/**
	 * getName()
	 * \Purpose: return the name of the periodic table
	 * \Parameter: None
	 * \return: std::string (the name of the periodic table)
	 */
	inline std::string getName() { return this->Name; };
	/**
	 * getName()
	 * \Purpose: return if the periodic table is initialized or not
	 * \Parameter: None
	 * \return: bool (true if pt is initialized or false)
	 */
	inline bool getInitialized() { return this->INITIALIZED; };

	/*
	 * displayGroup()
	 * \Purpose: Print out the periodic table
	 * \Parameter: None
	 * \return: None
	 */
	void displayGroup();
	/*
	 * findGroup(unsigned int)
	 * \Purpose: To find a group within the periodic table
	 * \Parameter: (unsigned int) id of the group
	 * \return: pointer to the group or nullptr;
	 */
	group* findGroup(unsigned int);
	/*
	* pTable(std::ifstream&)
	* \Purpose: Constructor from file stream
	* \Parameter: File stream
	* \return: None
	*/
// bool removeGroup(Group*);

	/*
	 * displayElement()
	 * \Purpose: Show the list of all element
	 * \Parameter: None
	 * \return: None
	 */
	void displayElement();
	/*
	 * pTable(std::ifstream&)
	 * \Purpose: find an element within the array
	 * \Parameter: (string) the symbol of the element
	 * \return: (pointer) the correct element or nullptr
	 */
	element* FindElement(std::string);
	/*
	* pTable(std::ifstream&)
	* \Purpose: Constructor from file stream
	* \Parameter: File stream
	* \return: None
	*/
//	bool removeElement(Element*);
};

#endif
