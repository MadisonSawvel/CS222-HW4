
//Madison Sawvel

#include <iostream>
#include <string>
#include <cstdlib>
#include "DRT.h"

using namespace std;

DRT::DRT(string d, string n, string p) { //constructor, sets values into variables in the header file
	data = d; next = n; prev = p;
}
string DRT::getdata() { return data; } //returns data of the node
string DRT::getnext() { return next; } //returns the next node
string DRT::getprev() { return prev; } //returns the previous node