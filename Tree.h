
//Madison Sawvel

#ifndef _TREE_
#define _TREE_
#include <iostream>
#include <string>
#include <cstdlib>
#include "TreeNode.h"
#include "DRT.h"
#include "Database.h"

using namespace std;

class DRT;
class TreeNode;
class Database;
class Tree : public Database {
private:
	TreeNode* root; //sets pointer to root
public:
	Tree(); //constructor, sets root to null
	~Tree(); //deconstructor, deletes the root to clean house
	DRT* add(string key, string data); //determines if the data needs to be set to root or to a leaf
	void setroot(TreeNode* r); // r is set to root
	DRT* searchnode(string key); //searches tree for given key
	string first(); //first key in the tree (left on down)
	string last(); //last key in the tree (right on down)
	DRT* remove(string key); //removes the key from the list
	DRT* search(string key); //checks to see if we're searching on the empty string, if so builds a DRT with first and last, otherwise calls searchnode
	DRT* modify(string key, string data); //modify returns the DRT that search would have returned JUST PRIOR to the modification made by modify
};
#endif