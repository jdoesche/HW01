#include <iostream>
using namespace std;
#include <fstream>
#include "vectored_h"

vectored::Vector()
{
  vec_ptr = NULL;
  vec_size = 0;
  vec_capacity = 0;
}

vectored::Vector(const Vector &other)
{
  
}

vectored::~Vector();
{
  delete[] vec_ptr;
  vec_size = 0;
  vec_capacity = 0;
}
