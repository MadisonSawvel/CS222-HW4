
//Madison Sawvel

#ifndef _DRT_
#define _DRT_
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class DRT {
private:
	string data; //initializes data
	string next; //initializes next
	string prev; //initializes previous
public:
	DRT(string d, string n, string p);  //constructor, sets values into variables in the header file
	string getdata(); //returns data of the node
	string getnext(); //returns the next node
	string getprev(); //returns the previous node
};
#endif

/* DRT.h is the database return type. it contains three fields:
	the data from the location in the database we're examining.
	the next key field in sequential order after the one we're examining.
	the prev field in sequentail order before the one we're examining.
	*/

