//
//  main.cpp
//  MyVectorClass
//
//  Created by Alex Ngun on 2019/02/01.
//  Copyright © 2019 Wai Yin Ngun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "vector.h"

int main()
{
  //testing big4
  vector v1;
  vector v2(v1);
  vector v3;
  v3 = v2;
  
  return 0;
}
