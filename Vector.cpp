#include <iostream>
using namespace std;
#include <fstream>
#include "Vector.h"

Vector::Vector()
  :vec_ptr(NULL)
{}

Vector::Vector(const Vector &other)
{
  vec_ptr = new int[vec_capacity];
}

Vector::~Vector()
{
  delete[] vec_ptr;
  vec_capacity = 4;
  vec_size = 0;
}

Vector::Vector& operator=(const Vector &other)
{
  int i = 0;
  while (i < vec_size)
    {
      other.vec_ptr[i] = vec_ptr[i];
      i++;
    }
}

int Vector::size()
{
  return vec_size;
}

int Vector::capacity()
{
  return vec_capacity;
}

void Vector::push_back(int element)
{
  if (vec_size + 1 >= vec_capacity)
    reserve();
  i = vec_size - 1;
  while (i > element)
    {
      vec_ptr[i] = vec_ptr[i - 1];
      i--;
    }
  vec_capacity++;
}

void Vector::reserve() //aka void vectored::PANIC!!!()
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
  int vec_capacity = tstore * 2;
  Vector();
 
  i = 0;
  while (i < vec_size)
    {
      vector[i] = tarr[i];
      i++;
    }  
}

Vector::int& operator[](unsigned int index)
{
  return vec_ptr[index];
}