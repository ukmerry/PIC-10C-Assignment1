//
//  main.cpp
//  MyVectorClass
//
//  Created by Alex Ngun on 2019/02/01.
//  Copyright © 2019 Wai Yin Ngun. All rights reserved.
//

#include <iostream>
#include "vector.h"

int main()
{
  vector v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  
  vector v2;
  v2.push_back(4);
  v2.push_back(5);
  v2.push_back(6);
  
  vector v3;
  
  v3 = v1 + v2;
  std::cout << "v1 + v2 = " << v3 << "\n";
  std::cout << "5 * v2 = " << 5*v2 << "\n";
  
  std::cout << "v1 < v2 = " << (v1 < v2) << "\n";
  std::cout << "v1 > v2 = " << (v1 > v2) << "\n";
  std::cout << "v1 == v2 = " << (v1 == v2) << "\n";
  std::cout << "v1 != v2 = " << (v1 != v2) << "\n";
  
  return 0;
}
