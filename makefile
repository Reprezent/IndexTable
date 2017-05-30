index_table: index_table.hpp index_table.cpp index_table_test.cpp
	g++ -Wall -g -std=c++11 -o $@ index_table.cpp index_table_test.cpp
