
//Madison Sawvel

#include <iostream>
#include <string>
#include <cstdlib>
#include "Tree.h"
#include "DRT.h"
#include "TreeNode.h"

using namespace std;

Tree::Tree() { root = NULL; } //constructor, sets root to null
Tree::~Tree() { delete root; } //deconstructor, deletes the root to clean house
void Tree::setroot(TreeNode* r) { root = r; } // r is set to root
DRT* Tree::add(string key, string data) { //determines if the data needs to be set to root or to a leaf
	if (!root) {
		root = new TreeNode(key, data, NULL, NULL, NULL, this);
		return new DRT("", "", "");
	}
	return root->add(key, data, "", "");
}
DRT* Tree::searchnode(string key) { //searches tree for given key
	if (root) {
		return root->searchnode(key, "", "");
	}
	return new DRT("", "", "");
}
string Tree::first() { //first key in the tree (left on down)
	if (root) {
		return root->first()->getk();
	}
	return "";
}
string Tree::last() { //last key in the tree (right on down)
	if (root) {
		return root->last()->getk();
	}
	return "";
}
DRT* Tree::remove(string key) { //removes the key from the list
	if (!root) {
		return new DRT("", "", "");
	}
	return root->remove(key, "", "");
}
DRT* Tree::search(string key) { //checks to see if we're searching on the empty string, if so builds a DRT with first and last, otherwise calls searchnode
	if (key == "") {
		return new DRT("", first(), last());
	}
	if (root) {
		return root->searchnode(key, "", "");
	}
	return new DRT("", "", "");
}
DRT* Tree::modify(string key, string data) { //modify returns the DRT that search would have returned JUST PRIOR to the modification made by modify
	if (key == "") {
		return new DRT("", first(), last());
	}
	if (data == "") {
		return remove(key);
	}
	return add(key, data);
}

/*
To fix:
Your DRT's aren't built correctly.  The DRT's returned on modify return the information pertaining to the tree before the change was made.
The code is essentially the same as what I gave you for searchnode.
*/