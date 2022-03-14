
//Madison Sawvel

#ifndef _DATABASE_
#define _DATABASE_
#include <iostream>
#include <string>
#include <cstdlib>
#include "DRT.h"

using namespace std;

class DRT;
class Database {
public:
	virtual DRT* search(string key) = 0;
	virtual DRT* modify(string key, string data) = 0;
};
#endif
