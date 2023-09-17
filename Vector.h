#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector
{
 private:
  int* vec_ptr;
  int vec_size = 0;
  int vec_capacity = 4;
  
 public:
  //Dynamic Arrays
  Vector();
  Vector(const Vector &other); //This function may need to be modified
  ~Vector();
  Vector& operator=(const Vector &other);

  int size();
  int capacity();
  void push_back(int element);
  void reserve();
  void print(int n);
  int& operator[](unsigned int index);
  void deflt();
};
#endif //Vector.h
