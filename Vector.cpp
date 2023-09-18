#include <iostream>
using namespace std;
#include <fstream>
#include "Vector.h"

Vector::Vector() //Create da Vector
  :vec_ptr(NULL)
{}

Vector::Vector(const Vector &other) //"Copy Constructor"
{
  int i = 0;
  while (i < vec_size)
    {
      vec_ptr[i] = other.vec_ptr[i];
      i++;
    }
}

Vector::~Vector() //Delete da Vector
{
  delete[] vec_ptr;
  vec_capacity = 4;
  vec_size = 0;
}

Vector& Vector::operator=(const Vector &other)
{
  int i = 0;
  while (this->vec_capacity <= other.vec_size)
    this->reserve();
  while (i <= other.vec_size)
    {
      this->vec_ptr[i] = other.vec_ptr[i];
      //if (other.vec_size + 2 >= this->vec_capacity)
      //  this->reserve();
      i++;
    }
  return *this;
}

int Vector::size() //Return the Vector Size
{
  return vec_size;
}

int Vector::capacity() //Return the Vector Capacity
{
  return vec_capacity;
}

void Vector::push_back(int element) // ROLL IT BACK
{
  if (vec_size + 2 >= vec_capacity)
    reserve();
  int i = vec_size;
  while (i > element)
    {
      vec_ptr[i] = vec_ptr[i - 1];
      i--;
    }
  vec_size++;
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

  delete[] vec_ptr;
  vec_capacity = tstore * 2;
  Vector();
  vec_ptr = new int[vec_capacity];
 
  i = 0;
  while (i < vec_size)
    {
      vec_ptr[i] = tarr[i];
      i++;
    }  
}

void Vector::print(int n)
{
  int i = 0;
  while (i < vec_size)
    {
      cout << vec_ptr[i] << " ";
      i++;
      if (n != 0)	
	if (i%n == 0)
	  cout << endl;
    }
  cout << endl;
}

int& Vector::operator[](unsigned int index)
{
  return vec_ptr[index];
}

void Vector::deflt()
{
  vec_ptr = new int[8];
  vec_size = 4;
  vec_capacity = 8;
  vec_ptr[0] = 1;
  vec_ptr[1] = 2;
  vec_ptr[2] = 3;
  vec_ptr[3] = 4;
}
