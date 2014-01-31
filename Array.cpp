//Array Class Implementation File

#include "Array.h"
#include <ctime>
using std::time;
#include <cstdlib>
using std::srand;
using std::rand;
using std::exit;
#include <iostream>
using std::ostream;
using std::endl;
using std::cerr;


inline int Array::square (int x) {
    return x*x;
}

int Array::fastExp ( unsigned long int b, unsigned long int n) {
    if ( n > 0 ) {
       if ( n % 2 )
          return b * fastExp(b, n - 1);

       else return square( fastExp(b, n / 2) );
	}
    else
        return 1;
}
/*
void Array::swap ( int i, int j ){			//swaps fucntions
	int temp = this->get(i);
	this->get(i) = this->get(j);
	this->get(j) = temp;
}
*/
Array::Array() {
	n = 0;
	a = 0;
}

Array::Array( int n ) {

	a = new int[n];
	this->n = n;

	int max_Rand = fastExp(2,31) - 1;

	srand( time(NULL) );

    for (int i = 0; i < n; i++)
		a[i] = rand() % max_Rand;

}

Array::Array(const Array& arr) {
	n = arr.n;
	a = new int[n];

	for (int i = 0; i < n; i++)
		a[i] = arr.a[i];
}

Array::~Array() {
	delete[] a;
	a = 0;
}

bool Array::operator==(const Array& newArr) const {
     if (n != newArr.n)
        return false;        // arrays of diffeent number of elements

     for (int i = 0; i < n; i++)
         if (a[i] != newArr[i])
            return false;      // array contents are not equal

     return true;              // arrays are equal
} // end overloaded operator ==

bool Array::operator!=(const Array& newArr) const {
     return !(*this == newArr);      // invokes Array::operator ==
} // end overloaded operator !=

Array &Array::operator=(const Array& newArr) {
      if(this==&newArr)
      return *this;

      delete[] a; // release space
      n = newArr.n;     // reseize this object
      a = new int[n];        // create space space for array copy

      for (int i = 0; i < n; i++)
          a[i] = newArr[i];  // copy array into object

      return *this;

} // end overloaded assignment

void Array::set( int i, int v ) {
	a[i] = v;
}

int Array::size() const {
    return n;
}

int& Array::operator[]( int i ) {

     if ( i < 0 || i >= n ) {
        cerr << "\nError: Subscript "  << i
             << " out of range" << endl;
        exit(1);
     } // end if

     return a[ i ];
} // end operator[]

int Array::operator[]( int i ) const {

    if ( i < 0 || i >= n ) {
           cerr << "\nError: Subscript " << i
                << " out of range" << endl;
           exit(1);
    } // end if

    return a[ i ];
} // end operator[]


ostream& operator<<(ostream& out, const Array& arr) {
	for (int i = 0; i < arr.size(); i++) {
		if (i % 10 == 0)
			out << endl;

		out << arr[i] << " ";
	}

	out << endl;

	return out;
}
