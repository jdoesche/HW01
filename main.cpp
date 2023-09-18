#include <iostream>
using namespace std;
#include <fstream>
#include "Vector.h"

void vscan(Vector& v);

int main()
{
  cout << "Welcome to the VECTORED program." << endl;
  cout << "Please select a setting " << endl
       << "  1 for Validity Test" << endl
       << "  2 for the assignment test" << endl
       << "  3 for an [albeit slightly broken] copy test" << endl
       << "  M for Manual Modification of a Single Vector" << endl;
  char var;
  cin >> var;
  cout << endl << endl;
  Vector v;
  v.deflt(); //Make a default array, {1, 2, 3, 4, E, E, E, E}
  if (var == '1') //To test the barebones basics of vector
    {
      v.print(0); //Print Test
      vscan(v);
      cout << endl << "Adding a 5 to the middle" << endl; //Insertion Test
      v.push_back(2);
      v[2] = 5;
      v.print(0);
      vscan(v);
      cout << endl;
      cout << "Oveflow test" << endl; //Overflow test
      v.push_back(1);
      v.push_back(1);
      v.push_back(1);
      v.push_back(1);
      v.print(0);
      vscan(v);
      cout << "test complete" << endl;
    }
  else if (var == '2') //To fufill the loop requirement
    {
      int t;
      cout << "Enter the number of variables you'd like to see (Must be more then 4):" << endl;
      cin >> t;
      if (t < 5)
	{
	  cout << "Less then 5 error" << endl;
	  return 1;
	}
      int i = 4;
      while (i < t)
	{
	  v.push_back(i - 1);
	  v[i] = i + 1;
	  i++;
	}
      v.print(20);
      vscan(v);
      cout << endl;
    }
  else if (var == '3')
    {
      cout << "Copy function" << endl;
      Vector t;
      t.deflt();
      v[0] = 256;
      v[4] = 5;
      v[5] = 6;
      v[6] = 7;
      v[7] = 8;
      v.push_back(5);
      v.push_back(2);
      v[2] = 100;
      v.print(0);
      vscan(v);
      t.print(0);
      vscan(t);
      cout << "V1 will now be copied to V2" << endl;
      t = v;
      v.print(0);
      vscan(v);
      t.print(0);
      vscan(t);
      cout << "task complete" << endl;
    }
  else if (var == 'M')
    {
      int iteration = 0;
      int intvar1;
      int intvar2;
      while (true)
      {
	if (iteration == 0) //Initiliazer Function
	  {
	    var = '?';
	   
	  }
	else
	  {
	    cout << "Please input an action (" << iteration << ")" << endl; //New Iteration Function
	    cin >> var;
	    cout << endl;
	  }

	
	if (var == '?') //Display
	  {
	    cout << "You can: " << endl
		 << "  (A)dd a new element to the Vector" << endl
		 << "  (D)isplay the current Size and Capacity of the Vector" << endl
		 << "  (F)ile [Copy a vector from a file]" << endl
		 << "  (M)odify an element of the Vector" << endl
		 << "  (P)rint the current Vector" << endl
		 << "  (?)  press ? to bring up this menu again" << endl
		 << "  (X)  or press X to close out the program" << endl;
	  }
	else if (var == 'X') //Exit
	  {
	    cout << "Thank you for using this Vector Program!" << endl;
	    return 0;
	  }
	else if (var == 'A') //Add new element
	  {
	    cout << "Where would you like this element to be?" << endl;
	    cin >> intvar1;
	    cout << endl << "And what would you like to add there?" << endl;
	    cin >> intvar2;
	    v.push_back(intvar1);
	    v[intvar1] = intvar2;
	    cout << "Done" << endl;
	  }
	else if (var == 'D') //Display but only the essentials
	  {
	    vscan(v);
	  }
	else if (var == 'F') //Download from a File
	  {
	    char mimicstring;
	    ifstream file;
	    int tcap = v.capacity();
	    cout << "Please enter the file ID (Noted in the README)" << endl
		 << "  T for Default File" << endl
		 << "  1 for Custom File 1" << endl
		 << "  2 for Custom File 2" << endl
		 << "  3 for Custom File 3" << endl;
	    cin >> mimicstring;
	    cout << endl;
	    if (mimicstring == 'T')
	      file.open("TestTextFile.txt");
	    else if (mimicstring == '1')
	      file.open("InFile1.txt");
	    else if (mimicstring == '2')
	      file.open("InFile2.txt");
	    else if (mimicstring == '3')
	      file.open("InFile3.txt");
	    else
	      {
		cout << "Failure to identify input" << endl;
		return 1;
	      }
	    if (!file.is_open())
	      {
		cout << "Failure to identify file" << endl;
		return 1;
	      }
	    int temporint = 0;
	    int k = 0;
	    file >> v[0];
	    while (!file.eof()) //Copy the File to the Vector
	      {
		k++;
		if (k < tcap)
		  {
		    file >> temporint;
		    if (temporint == -1)
		      break;
		    v[k] = temporint;
		  }
		else
		  {
		    file >> temporint;
		    if (temporint == -1)
		      break;
		    v.push_back(k - 1);
		    v[k] = temporint;
		  }
	      }
	    file.close();
	    cout << "Done" << endl;
	  }
	else if (var == 'M') //Modify
	  {
	    cout << "Where would you like this element to be?" << endl;
	    cin >> intvar1;
	    cout << endl << "And what would you like to replace it with?" << endl;
	    cin >> intvar2;
	    v[intvar1] = intvar2;
	    cout << "Done" << endl;
	  }
	else if (var == 'P') //Print
	  {
	    cout << "How many items do you want per row?" << endl
		 << "  (You can also enter 0 to not split the rows)" << endl;
	    cin >> intvar1;
	    v.print(intvar1);
	  }
	else
	  cout << "Error. Unidentified value" << endl;
	iteration++;
      }
    }
}

void vscan(Vector& v) //Just returns the Size and Remaining Capacity of the Vector
{
  cout << "The current vector has a size of " << v.size() << ", and "
       << v.capacity() - v.size() << " more spaces remaining" << endl;
}
