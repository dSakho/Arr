//Array Class Header File

#ifndef Array_H
#define Array_H

#include <iostream>
using std::ostream;

class Array {

friend ostream& operator<<(ostream& out, const Array& arr);

private:
int * a;	 //private data for array
int n;	 //private data for size

inline int square (int x);	 //obtain the square of a number
int fastExp ( unsigned long int b, unsigned long int n);	//obtains the exponent of a number


public:
Array();	 //default constructor
Array( int n );
Array (const Array& arr);	//copy constructor
~Array();	 //destructor
Array& operator=(const Array& arr);

bool operator==(const Array& newArr) const;
bool operator!=( const Array& newArr) const;

void swap (int i, int j);	//swaps elements inside the array
void set( int i, int v );	//sets array element
int size() const;	 //return size of array

int& operator[]( int );
int operator[]( int i ) const;


}; // end Array class definition

#endif
