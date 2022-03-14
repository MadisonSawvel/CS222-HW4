
//Madison Sawvel

#include <iostream>
#include <string>
#include <cstdlib>
#include "TreeNode.h"
#include "DRT.h"

using namespace std;

TreeNode::TreeNode(string key, string data, TreeNode* l, TreeNode* r, TreeNode* p, Tree* T) { //constructor, sets values into the private variables set in the header file
	k = key; d = data; left = l; right = r; parent = p; t = T;
}
TreeNode::~TreeNode() { //deconstructor, deletes left and right nodes to clean house
	delete left;
	delete right;
}
DRT* TreeNode::add(string key, string data, string n, string p) { //determines the position in the tree (left or right) the new data needs to be added and creates new treenode
	if (k == key) {
		d = data;
		return new DRT(data, n, p);
	}
	if (k < key) {
		if (right) {
			return right->add(key, data, n, k);
		}
		else {
			this->setright(new TreeNode(key, data, nullptr, nullptr, this, t));
			return new DRT(data, n, k);
		}
	}
	if (left) {
		return left->add(key, data, k, p);
	}
	else {
		this->setleft(new TreeNode(key, data, nullptr, nullptr, this, t));
		return new DRT(data, k, p);
	}
}
DRT* TreeNode::searchnode(string key, string n, string p) { //searches for the node containing the data requested
	if (k == key) {
		string next, prev;
		if (!right) next = n;
		else next = right->first()->getk();
		if (!left) prev = p;
		else prev = left->last()->getk();
		return new DRT(d, next, prev);
	}
	if (k < key) {
		if (right) return right->searchnode(key, n, k);
		return new DRT("", n, k);
	}
	if (left) return left->searchnode(key, k, p);
	return new DRT("", k, p);
}
TreeNode* TreeNode::first() { //searches for the left most node using this as its root
	if (this->getleft() != nullptr){
		return this->getleft()->first();
	}
	return this;
}
TreeNode* TreeNode::last() { //searches for the right most node using this as its root
	if (this->getright() != nullptr) {
		return this->getright()->last();
	}
	return this;
}
string TreeNode::getk() { return k; } //returns key
string TreeNode::getd() { return d; } //returns data
TreeNode* TreeNode::getright() { return right; } //returns what is right
TreeNode* TreeNode::getleft() { return left; } //returns what is left
string TreeNode::next() { return left->last()->getk(); } //returns the key that is the last on the left
string TreeNode::prev() { return right->first()->getk(); } //returns the key that is the first on the right
DRT* TreeNode::remove(string key, string n, string p) { //keeps track of nsf and psf as it works its way down the tree to find the node it needs to remove
	if (k == key) {
		this->remove();
		return new DRT("", n, p);
	}
	if (k < key) {
		if (right) {
			return right->remove(key, n, k);
			return new DRT("", n, k);
		}
	}
	if (left) {
		return left->remove(key, k, p);
	}
	return new DRT("", k, p);
}
void TreeNode::remove() { //physical removal, decide whether it's 0,1, or 2 children. possibly copies key and data values and physically removes the deleted node
	if (left && right) {
		d = left->last()->getd();
		k = left->last()->getk();
		left->last()->remove();
	}
	else if(left || right){
		if (this->parent == nullptr) {
			if (left) {
				t->setroot(left);
				left->setparent(nullptr);
				this->setleft(nullptr);
			}
			else {
				t->setroot(right);
				right->setparent(nullptr);
				this->setright(nullptr);
			}
		}
		else if (this->parent->getleft() == this) {
			if (left) {
				this->getleft()->setparent(this->parent);
				this->parent->setleft(this->getleft());
				this->setleft(nullptr);
			}
			else {
				this->getright()->setparent(this->parent);
				this->parent->setleft(this->getright());
				this->setright(nullptr);
			}
		}
		else {
			if (left) {
				this->getleft()->setparent(this->parent);
				this->parent->setright(this->getleft());
				this->setleft(nullptr);
			}
			else {
				this->getright()->setparent(this->parent);
				this->parent->setright(this->getright());
				this->setright(nullptr);
			}
		}
		this->setparent(nullptr);
		delete this;
	}
	else {
		if (this->parent == nullptr) {
			t->setroot(nullptr);
		}
		else if (this->parent->getleft() == this) {
			this->parent->setleft(nullptr);
		}
		else {
			this->parent->setright(nullptr);
		}
		this->setparent(nullptr);
		delete this;
	}
}
void TreeNode::setparent(TreeNode* p) { parent = p; } //sets p to parent
void TreeNode::setleft(TreeNode* l) { left = l; } //sets l to left
void TreeNode::setright(TreeNode* r) { right = r; } //sets r to right