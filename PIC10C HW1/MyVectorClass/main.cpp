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
  v1.push_back(4);
  v1.push_back(5);
  v1.push_back(6);
  v1.push_back(7);
  v1.push_back(8);
  v1.push_back(9);
  v1.push_back(10);
  v1.push_back(0);
  
  for (int i = 0; i < v1.size(); ++i)
  {
    std::cout << v1[i] << " ";
  }
  std::cout << std::endl;
  
  return 0;
}
