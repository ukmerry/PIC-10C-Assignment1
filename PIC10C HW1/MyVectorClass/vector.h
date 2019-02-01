//
//  vector.h
//  MyVectorClass
//
//  Created by Alex Ngun on 2019/02/01.
//  Copyright © 2019 Wai Yin Ngun. All rights reserved.
//

#ifndef vector_h
#define vector_h

#include "cmath"

class vector
{
public:
  // The big 4
  vector();
  vector( const vector& );
  vector& operator=( const vector& );
  ~vector();
  
  void push_back( int new_value );
  int& operator[]( size_t index );
  int operator[]( size_t index ) const;
  
private:
  int* the_data;
  size_t the_size;
  size_t the_capacity;
  
  static const int INIT_CAP = 10;
};

vector::vector()
:the_data(nullptr), the_size(0), the_capacity(INIT_CAP)
{
  the_data = new int[INIT_CAP];
}

vector::vector( const vector& source )
: the_data(nullptr), the_size(source.the_size), the_capacity(source.the_capacity)
{
  the_data = new int[the_capacity];
  
  // Deep copy of internal array
  for ( int i = 0 ; i < the_size ; ++i )
  {
    the_data[i] = source.the_data[i];
  }
}

vector& vector::operator=(const vector& rhs)
{
  if ( this != &rhs )
  {
    // Release old memory and request more
    delete[] the_data;
    the_data = new int[rhs.the_capacity];
    
    // Shallow copy non-pointers
    the_size = rhs.the_size;
    the_capacity = rhs.the_capacity;
    
    // Deep copy internal array
    for ( int i = 0 ; i < the_size ; ++i )
      the_data[i] = rhs.the_data[i];
  }
  
  return *this;
}

vector::~vector()
{
  delete[] the_data;
}


#endif /* vector_h */
