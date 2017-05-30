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
#include <set>
#include <tuple>
#include <map>

//using get_hash = std::get<0>;
//using get_key = std::get<1>;
//using get_value = std::get<2>;

#define INITAL_TABLE_SIZE 1009

// The dictionary class provides a key, value pairing that runs in constant time
// for lookups.

template <typename T, typename V>

//#define std::tuple<int, T, V> dictionary_data

class dictionary
{
	public:
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
		
		// Inserts the key with the target value if th ekey has no value and
		// returns the set value.
		V insertIfAbsent(T key, V value);

		// Returns true if the hashtable is empty.
		bool empty();
		
		// Returns true if the table contains the key
		bool contains(T key);

		// Returns true if the table contains the key (Same as contains)
		bool containsKey(T key);

		// Returns true if the table contains the value.
		//  - This function runs in linear time.
		bool containsValue(V value);

		// Returns a copy of the values in order that the keys were inserted,
		// if none were updated.
		std::vector<V>& elements();

		// Returns a set of key -> value pairing in the order that the keys were addedto the dictionary.
		std::set< std::pair<T, V> > entrySet();

		// Compares the two vectors for complete equality.
		bool equals(const dictionary& table);


		// Returns the value of the specified key if it exists, 
		V get(T key);


	private:

		// Resizes th einternal datastructures that contain the mapping of th eindicies of the hashed values.
		void __resize();

		// Hash function that hashes the specified key.
		int __hash(T item);
		 

		// Data structure that holdsthe indicies of the keys to the actaul key value mappings.
		std::vector<unsigned int> indicies;

		// The actual key value mappings to for use from the indicies table.
		std::vector< std::tuple<int, T, V> > table;

};
