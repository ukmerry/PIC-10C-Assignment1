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
  
  //utility functions
  size_t size() const;
  bool empty() const;
  size_t capacity() const;
  int front() const;
  int back() const;
  int at( size_t index ) const;
  void pop_back();
  
  //overloading operators
  vector operator+(const vector& v) const;
  void operator+=(const vector& v);
  int operator*(const vector& v) const;
  bool operator<(const vector&) const;
  bool operator>(const vector&) const;
  bool operator==(const vector&) const;
  bool operator!=(const vector&) const;
  bool operator>=(const vector&) const;
  bool operator<=(const vector&) const;
  
private:
  int* the_data;
  size_t the_size;
  size_t the_capacity;
  
  static const int INIT_CAP = 10;
  
  void reserve( size_t new_capacity );
  double norm(const vector&) const;
  
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

void vector::push_back( int new_value )
{
  if ( the_size == the_capacity )
    reserve( the_capacity + 1 );     // `the_data` is reassigned
  
  the_data[the_size++] = new_value;
}

int& vector::operator[]( size_t index )
{
  return the_data[index];
}

int vector::operator[]( size_t index ) const
{
  return the_data[index];
}

void vector::reserve( size_t new_capacity )
{
  
  if ( new_capacity > the_capacity ) {
    if ( new_capacity <= 2 * the_capacity )
      new_capacity = 2 * the_capacity;
    
    int* old_location = the_data;
    
    the_data = new int[new_capacity];
    the_capacity = new_capacity;
    
    for ( size_t i = 0 ; i < the_size ; ++i )
      the_data[i] = old_location[i];
    
    delete old_location;
  }
}

size_t vector::size() const
{
  return the_size;
}

bool vector::empty() const
{
  return the_size == 0;
}

size_t vector::capacity() const
{
  return the_capacity;
}

int vector::front() const
{
  return *the_data;
}

int vector::back() const
{
  return *(the_data + the_size - 1);
}

int vector::at( size_t index ) const
{
  if ( index < the_size )
    return the_data[index];
  return the_data[0];
}

void vector::pop_back()
{
  if ( the_size > 0 )
    --the_size;
}

int vector::operator*(const vector& v) const
{
  int dot_product = 0;
  if (v.size() == the_size)
  {
    for (int i = 0; i < the_size; i++)
      dot_product += *(the_data + i) * v[i];
    
    return dot_product;
  }
  else return -1;
}

vector vector::operator+(const vector& v) const
{
  vector output(*this);
  for (int i = 0; i < v.size(); i++)
    output[i] += v[i];
  
  return output;
}

void vector::operator+=(const vector& v)
{
  for (int i = 0; i < v.size(); i++)
    *(the_data + i) += v[i];
}

vector operator*(const vector& v, int scalar)
{
  vector output(v);
  for (int i = 0; i < v.size(); i++)
    output[i] *= scalar;
  
  return output;
}

vector operator*(int scalar, const vector& v)
{
  vector output(v);
  for (int i = 0; i < v.size(); i++)
    output[i] *= scalar;
  
  return output;
}

bool vector::operator<(const vector & v) const
{
  if (norm(*this) < norm(v))
    return true;
  else
    return false;
}

bool vector::operator>(const vector & v) const
{
  if (norm(*this) > norm(v))
    return true;
  else
    return false;
}

bool vector::operator<=(const vector & v) const
{
  if (norm(*this) <= norm(v))
    return true;
  else
    return false;
}

bool vector::operator>=(const vector & v) const
{
  if (norm(*this) >= norm(v))
    return true;
  else
    return false;
}

bool vector::operator==(const vector & v) const
{
  for (int i = 0; i < the_size; i++)
    if (*(the_data+i) != v[i])
      return false;
  
  return true;
}

bool vector::operator!=(const vector & v) const
{
  for (int i = 0; i < the_size; i++)
    if (*(the_data+i) != v[i])
      return true;
  
  return false;
}

double vector::norm(const vector& v) const
{
  return sqrt(v * v);
}

std::ostream& operator<<( std::ostream& out, const vector& v )
{
  out << "{";
  for ( size_t i = 0 ; i < v.size() ; ++i)
  {
    out << v[i];
    
    if (i != v.size()-1)
      out << ", ";
  }
  out << "}";
  
  return out;
}

void print_vector( const vector& v )
{
  if ( v.empty() )
    std::cout << "Vector is empty\n";
  else
    std::cout << "Vector (contents): " << v << '\n' ;
}

#endif /* vector_h */
