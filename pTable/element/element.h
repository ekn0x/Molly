/**
 * \Class element
 * \Brief chemical element
 * 
 * interface for a chemical element.
 * 
 * \Author ekn0x
 * \version 0.99
 */
#ifndef _ELEMENT_H_
#define _ELEMENT_H_

#include <fstream>
#include <string>
 
class group;

class element
{
private:
	std::string Name;   //< Name of the element
	std::string Symbol; //< Symbol of the element

	group* family;      //< Pointer to the element's chemical group

public:
	/**
	 * \Brief Constructor from data stream
	 * \Param file stream of data
	 * \Return	None
	 */
	element(std::ifstream&);
	/**
	 * \Brief copy constructor
	 * \Param element
	 * \Return None
	 */
	element(const element&);
	/**
	 * \Brief default destructor
	 * \Param 
	 * \Return
	 */
	~element();

	/**
	 * \Brief Assignement operator
	 *  Not in function at the moment
	 * \Param None
	 * \Returns: None
	 */
	//element& element::operator = (const element&);

	/**
	 * \Brief Print out all the elements of the periodic table 
	 * \Param None
	 * \Return None
	 */
	void display();

  /**
	 * \Brief Return the element's name
	 * \Param None
	 * \Return (std::string) Name of the element
	 */
	inline std::string getName() { return this->Name; };
	/**
	 * \Brief Return the symbol of the element
	 * \Param None
	 * \Return (std::string) element's symbol
	 */
	inline std::string getSymbol() { return this->Symbol; };
	/**
	 * \Brief Return a pointer to the element's chemical group
	 * \Param None
	 * \Return (group*) pointer to the element's group
	 */
	inline group* getGroup() { return this->family; };
};

#endif // _ELEMENT_H_
