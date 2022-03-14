
//Madison Sawvel

#ifndef _TREENODE_
#define _TREENODE_
#include <iostream>
#include <string>
#include <cstdlib>
#include "Tree.h"
#include "DRT.h"

using namespace std;

class DRT;
class Tree;
class TreeNode {
private:
	string k; string d; //initializes key and data 
	TreeNode *left, *right, *parent; //creates the pointers for left, right, and parent
	Tree* t; //creates the tree pointer
public:
	TreeNode(string key, string data, TreeNode *l, TreeNode *r, TreeNode *p, Tree *T); //constructor, sets values into the private variables set in the header file
	~TreeNode(); //deconstructor, deletes left and right nodes to clean house
	DRT* add(string key, string data, string n, string p); //determines the position in the tree (left or right) the new data needs to be added and creates new treenode
	DRT* searchnode(string key, string n, string p); //searches for the node containing the data requested
	TreeNode* first(); //searches for the left most node using this as its root
	TreeNode* last(); //searches for the right most node using this as its root
	string getk(); //returns key
	string getd(); //returns data
	TreeNode *getright(); //returns what is to the right
	TreeNode *getleft(); //returns what is to the left
	string next(); //returns the key that is the last on the left
	string prev(); //returns the key that is the first on the right
	DRT* remove(string key, string n, string p); //keeps track of nsf and psf as it works its way down the tree to find the node it needs to remove
	void remove(); //physical removal, decide whether it's 0,1, or 2 children. possibly copies key and data values and physically removes the deleted node
	void setparent(TreeNode* p); //sets p to parent
	void setleft(TreeNode* l); //sets l to left
	void setright(TreeNode* r); //sets r to right

};
#endif