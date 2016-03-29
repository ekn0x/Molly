#ifndef _VECT0R_H_
#define _VECT0R_H_

//
// pointer type bool
// pointer flag, not used at the moment
// used like this:
// is_pointer<int>::value       'return 0
// is_pointer<int*>::value      'return 1
// 

template<typename T>
struct is_pointer { static const bool value = false; };
template<typename T>
struct is_pointer<T*> { static const bool value = true; };

/**
 * \brief Homebrew vector function
 * Since I cannot use the stl implementation vector, i'll make my own.
 *
 * Known issues
 *  Poor pointer implementation
 *      If T is a pointer, all of the objects stored in the vect0r are never
 *      freed, this causes a huge memory leak.
 *  potential fix:
 *      serialization               (boost librairy, could provide some features)
 *      partial specialization      (need to learn more before)
 *      
 * New things to implement or look into:
 *	-> Iterators
 *	-> Allocators (coud potentially fix the pointer problem)
 */
template <class T>
class vect0r
{
private:
	T *arr;         //< Dynamically allocated array
	unsigned int Size;  //< Number of element in the array at the moment
	unsigned int Capacity; //< The actual size allocated

						   // static information
	const static int memoryGrowthRate = 2; //< Array growth rate (multiplication factor when redimmensionning the array)

	// growing function
	/**
	 * growArray()
	 * \Purpose: Increase the amount of memory by the memoryGrowthRate
	 * \Parameters: None
	 * \Returns: None
	 */
	void growArray();
	/**
	 * shrinkArray()
	 * \Purpose: Reduce the amount of memory by the memoryGrowthRate
	 * \Parameters: None
	 * \Returns: None
	 */
	void shrinkArray();
public:
	/**
	 * vect0r()
	 * \Purpose: Default constructor
	 * \Parameters: None
	 * \Returns: None
	 */
	vect0r<T>();
	/**
	 * vect0r(const vect0r&)
	 * \Purpose: copy constructor
	 * \Parameters: const vect0r&
	 * \Returns: None
	 */
	vect0r<T>(const vect0r&);
	/**
	 * ~vect0r()
	 * \Purpose: destructor
	 * \Parameters: None
	 * \Returns: None
	 */
	~vect0r<T>();

	/// operators overloading
	/**
	 * operator =
	 * \Purpose: assignation method
	 * \Parameters: const vect0r&
	 * \Returns: vect0r&
	 */
	vect0r<T>& operator = (const vect0r&);
	/**
	 * operator []
	 * \Purpose: gapping and dereferencing operator
	 * \Parameters: gapping index
	 * \Returns: T&
	 */
	T& operator [] (unsigned int);

	/**
	 * Insert()
	 * \Purpose: Inserting and managing the Size of the array
	 * \Parameters: the element we want to insert
	 * \Returns: None
	 */
	void Insert(const T&);
	/**
	 * Delete()
	 * \Purpose: Deleting and managing the Size of the array
	 * \Parameters: The case we want to delete
	 * \Returns: None
	 */
	void Delete(unsigned int);
	/**
	 * Clear()
	 * \Purpose: Delete every element of the array and set the array to default values
	 * \Parameters: None
	 * \Returns: None
	 */
	void Clear();

	// a few getters
	/**
	 * getCapacity()
	 * \Purpose: Return the number of number cell Capacity
	 * \Parameters: None
	 * \Returns: The number of space Capacity at the moment
	 */
	unsigned int getCapacity();
	/**
	 * getSize()
	 * \Purpose: Return the number of Size cells occupied
	 * \Parameters: None
	 * \Returns: the number of space Capacity occupied at the moment
	 */
	unsigned int getSize();
};


template <class T>
vect0r<T>::vect0r()
{
	Capacity = 2;
	arr = new T[Capacity];
	Size = 0;
}

template <class T>
vect0r<T>::vect0r(const vect0r &n)
{
	// need to recreate the whole array.
	if (this != &n)
	{
		delete[] arr;
		Capacity = n.getCapacity();
		Size = n.getSize();

		arr = new T[Capacity];
		for (int i = 0; i<Size; ++i)
			arr[i] = n.arr[i];
	}	
}

template <class T>
vect0r<T>::~vect0r()
{
	for (unsigned int i = 0; i < Size; ++i)
	{
		if(arr[i] != nullptr)
			delete arr[i];
	}

	// need to validate if it's optionnal or not
	delete[] arr;
	system("PAUSE");
}

template <class T>
vect0r<T>& vect0r<T>::operator = (const vect0r<T> &n)
{
	// Here because we have Capacity memory, we cannot just go with a 
	// shallow copy, we have to make it deep. and therefore, we make 
	// exactly the same thing as a copy constructor
	if (this != &n)
	{
		delete[] arr;
		Capacity = n.getCapacity();
		Size = n.getSize();

		arr = new T[Capacity];
		for (int i = 0; i<Size; ++i)
			arr[i] = n.arr[i];
	}

	return *this;
}

template <class T>
T& vect0r<T>::operator [] (unsigned int i)
{
	// should probably throw an exception
	// but at the moment I don't know how they works
	return (i<Size && i>= 0) ? arr[i] : arr[0] ;
}

template <class T>
void vect0r<T>::Insert(const T &n)
{
	//
	// Expected behavior:
	// When inserting an object it's logical that it goes at the end of the array
	// 
	if (this->Size == this->Capacity)
		this->growArray();

	arr[Size] = n;
	++Size;
}

template <class T>
void vect0r<T>::Delete(unsigned int i)
{
	// In case of misuse
	if (i>Size || i < 0)
		return;
	/**
	 * Expected behavior:
	 * When deleting an item from the array, it should filled the case with the
	 * next one in line.
	 * Therefore, when deleting, there's a shifting of data that takes places.
	 */
	delete arr[i];
	for (unsigned int j = i; j<Size - 1; ++j)
	{
		arr[j] = arr[j + 1];
	}
	arr[Size] = nullptr;
	
	--Size;
	if (this->Size <= (this->Capacity) / 2)
		this->shrinkArray();

}

template <class T>
void vect0r<T>::Clear()
{
	for (unsigned int i = 0; i < Size; ++i)
	{
		if (arr[i])
			delete arr[i];
	}

	// reset to base;
	Capacity = 2;
	arr = new T[Capacity];
	Size = 0;
}

template <class T>
unsigned int vect0r<T>::getCapacity()
{
	return this->Capacity;
}

template <class T>
unsigned int vect0r<T>::getSize()
{
	return this->Size;
}

/// Private methods

template <class T>
void vect0r<T>::growArray()
{
	Capacity *= memoryGrowthRate;
	T *tmp = new T[Capacity];
	
	for (unsigned int i = 0; i<Size; ++i)
	{
		tmp[i] = arr[i];
	}
	
	delete[] arr;
	arr = tmp;
}

template <class T>
void vect0r<T>::shrinkArray()
{
	Capacity /= memoryGrowthRate;
	T *tmp = new T[Capacity];

	for (unsigned int i = 0; i<Size; ++i)
	{
		tmp[i] = arr[i];
	}
	
	delete[] arr;
	arr = tmp;
}

#endif
