#include <iostream>
using namespace std;
#include <fstream>
#include "Vectored.h"

vectored::Vector()
  :vec_ptr = NULL
{
  vec_size = 0;
  vec_capacity = 4;
}

vectored::Vector(const Vector &other)
{
 vec_ptr = new int[vec_capacity]
}

vectored::~Vector()
{
  delete[] vec_ptr;
  vec_size = 0;
  vec_capacity = 4;
}

vectored::Vector& operator=(const Vector &other)
{
  int i = 0;
  while (i < vec_size)
    {
      other.Vector[i] = Vector[i];
      i++;
    }
}

int vectored::size()
{
  return vec_size;
}

int vectored::capacity()
{
  return vec_capacity;
}

void vectored::push_back(int element)
{
  if (vec_size + 1 >= vec_capacity)
    reserve();
  i = vec_size - 1;
  while (i > element)
    {
      vector[i] = vec_ptr[i - 1];
      i--;
    }
}

void vectored::reserve() //aka void vectored::PANIC!!!()
{
  int tarr[vec_size];
  int tstore = vec_capacity;
  int i = 0;
  while (i < vec_size) //copy the old vector into a temporary array
    {
      tarr[i] = vec_ptr[i];
      i++;
    }

  ~Vector();
  Vector();
  int vec_capacity = tstore * 2;

  i = 0;
  while (i < vec_size)
    {
      vector[i] = tarr[i];
      i++;
    }  
}

vectored::int& operator[](unsigned int index)
{
  
}
