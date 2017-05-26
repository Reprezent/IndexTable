//
// Index Table Container (C++ 11)
// 
// Version 0.1 (Last Updated: 5/24/2017)
// 
// Description:
//    This class implements a hash table with indicies
//	  in order to reduce the memory overhead and increase
//    cache line efficency.
//
// Author:
//    Richard "Alex" Riedel
//


#include <vector>
#include <map>

#define INITAL_TABLE_SIZE 1009

// The dictionary class provides a key, value pair 

template <typename T, typename V>
class dictionary
{
	public;
		// Default constructor
		//	- Allocates the index table and the vector to hold it
		//	  the tuples of (hashValue, Key, Value).
		dictionary();

		// User Set Size Constructor
		//  - Constructor that allows a preset size for the dictionary,
		//  reallocation will still be based on preset algorithm.
		dictionary(int size);

		// Map Constructor
		//  - Passes a map to the Hash table to presetup the
		//    dictionary with.
		dictionary(std::map<T, V> map);

		// Copy Constructor
		//  - Copys the dicitonary into tanother dictionary.
		dictionary(const dictionary& table);
		
		// Move Constructor
		//  - Moves the dictionary to another dictionary.
		//    This assumes that the previous dictionary will
		//    be destroyed soon after.
		dictionary(dictionary&& table);

		// Clears the dictionary of all key value references.
		// Does NOT resize the table back toits original state.
		void clear();

		// Creates a copy of the dictionary from the point in time in
		// which this function was called.
		dictionary& clone();

		// Inserts an element into the dictionary, if the key already exists
		// the value is replaced. 
		// The return value is two fold:
		//	 - If the key is in the dictionary then the previous value is returned.
		//   - If the key is not within the dictionary then null is returned. 
		// *********************** NEED TO CHANGE THIS TO A NEW VALUE OR SOMETHING, CAN'T DO IT IN C++ ********************
		bool insert(T key, V value);

		// Returns true if the hashtable is empty.
		bool empty();
		
		// Returns true if the table contains the key
		bool contains(T key);

		// Returns true if the table contains the key (Same as contains)
		bool containsKey(T key);

		// Returns true if the table contains the value.
		//  - This function runs in linear time.
		bool containsValue(V value);
		std::vector<V>& elements();
		std::set< std::pair<T, V> > entrySet();
		boolean equals(const dictionary& table);


		V get(T key);


	private:
		void __resize();
		int __hash(T item);
		

		std::vector<unsigned int> indicies;
		std::vector< std::tuple<size_t, T, V> > table;

};
