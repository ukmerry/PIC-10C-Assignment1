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
  
private:
  int* the_data;
  size_t the_size;
  size_t the_capacity;
  
  static const int INIT_CAP = 10;
};


#endif /* vector_h */
