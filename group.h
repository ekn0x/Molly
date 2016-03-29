/**
 * \Class group
 * \Brief Chemical group
 * 
 * Provide a template for chemical group and their respective proprieties
 * 
 * \Author ekn0x
 * \version 0.99
 * 
 */
#ifndef _GROUP_H_
#define _GROUP_H_

#include <string>

class group
{
private:
	std::string Name; \\< Name of the group
	int Valence;      \\< Number of valence electrons
	unsigned int Id;  \\< Id of the group

public:
	/**
	 * \Brief Default construtor
	 * \Param None
	 * \Return None
	 */
	group();
	/**   
	 * \Brief constructor from stream
	 * \Parameter: data stream 
	 * \Return None
	 */
	group(std::ifstream&);
	/**
	 * \Brief copy constructor
	 * \Param copy value
	 * \Return None
	 */
	group(const group&);
	/**
	 * \Brief the one and only destructor
	 * \Param None
	 * \Return None
	 */
	~group();
	/**
	 * \Brief Assignement operator
	 * \Param None
	 * \Return (group&) Instance of a group
	 */
	group& group::operator = (const group&);

  	/**
	 * \Brief return the name of the group
	 * \Param None
	 * \Return (std::string) name of the group
	 */
	inline std::string getName() { return this->Name; };
	/**
	 * \Brief return the id of the group
	 * \Param None
	 * \Return (unsigned int) Id of the group
	 */
	inline unsigned int getId() { return this->Id; };
	/**
	 * \Brief Return the number of valence electrons a group has
	 * \Param None
	 * \Return (unsigned int) Number of valence electrons
	 */
	inline int getValence() { return this->Valence; };
};

#endif // _GROUP_H_
