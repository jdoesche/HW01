#ifndef VECTORED_H
#define VECTORED_H

#include <iostream>
using namespace std;

class vectored
{
 private:
  int* vec_ptr;
  int vec_size = 0;
  int vec_capacity = 4;
  
 public:
  Vector();
  Vector(const Vector &other);
  ~Vector();
  Vector& operator=(const Vector &other);

  int size();
  int capacity();
  void push_back(int element);
  void reserve();
  int& operator[](unsigned int index);
}
