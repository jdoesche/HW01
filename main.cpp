#include <iostream>
using namespace std;
#include <fstream>
#include "Vectored.h"

int main()
{
  cout << "Welcome to the VECTORED program." << endl;

  int emex = 0;
  int MX = 32 - 1;
  char func;
  Vectored v;

  cout << "Please enter an operation . . ." << endl;
  cout << "  (You can always type '?' for help, or 'x' to close the program) " << endl;
  
  while (emex < MX)
    {
      cin >> func;
      cout << endl;
      if (func == 'x')
	{
	  cout << "Ending program. Thank you for using it. " << endl;
	  break;
	}
      else if (func == '?')
	{
	  cout << "  a to create a new vector" << endl;
	  cout << "  i to insert a variable somewhere" << endl;
	  cout << "  m to return the max capacity of the vector" << endl;
	  cout << "  p to print the vector" << endl;
	  cout << "  s to return the current size of the vector" << endl;
	  cout << "  x to close the program" << endl;
	  cout << "  ? to bring up this menu again" << endl;
	}
      else if (func == 'a')
	{
	  cout << "Creating a new vector..." << endl;
	  cout << "Done" << endl;
	}
      else if (func == 'i')
	{
	  int v1, v2;
	  cout << "Please enter what number you would like to enter: ";
	  cin >> v1;
	  cout << endl << "Please enter where you want that number to be: ";
	  cin >> v2;
	  cout << "Done." << endl;
	}
      else if (func == 'm')
	{
	  cout << "The current capacity of the vector is " << "TESTNUM" << endl;
	}
      else if (func == 'p')
	{
	  cout << "Printing the vector... " << endl;
	  cout << "Done." << endl;
	}
      else if (func == 's')
	{
	  cout << "The current capacity of the vector is " << "TESTNUM2" << endl;
	}
      else
	cout << "Variable not recognized. Try again" << endl;

      if (MX - emex <= 6)
	cout << "Warning! The function is running out of free space. You have "
	     << MX - emex - 1 << " Functions remaining!" << endl;

      if (MX - emex = 0)
	cout << "Sorry, operation has been overloaded. Automatically closing" << endl;
      emex++;
    }
  
  return 0;

}
