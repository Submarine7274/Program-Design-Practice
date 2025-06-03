// Exercise 13.16: Complex.cpp

#include <iostream>
#include "Complex.h"

using namespace std;

istream& operator>>( istream& in, Complex& c ) {

   in >> c.realNumber;

   if ( cin.peek() == ' ' )
      cin.ignore();

   char sign;
   in >> sign;

   if ( sign != '+' && sign != '-' )
      cin.clear( ios::failbit );

   if ( cin.peek() == ' ' )
      cin.ignore();

   in >> c.imaginaryNumber;
   c.imaginaryNumber *= ( sign == '+' ? 1 : -1 );

   if ( cin.peek() != 'i' )
      cin.clear( ios::failbit );

   return in;
}

ostream& operator<<( ostream& out, const Complex& C ) {
   if ( cin.good() )
      out << C.realNumber << showpos << C.imaginaryNumber << 'i' << endl << noshowpos;
   else
      out << "ERROR!" << endl;
   return out;
}

Complex::Complex() {
   realNumber = imaginaryNumber = 0;
}