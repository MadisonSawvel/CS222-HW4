
//Madison Sawvel

#include <iostream>
#include <string>
#include <cstdlib>
#include "Tree.h"
#include "DRT.h"
#include "PG4.h"
#include "Database.h"

using namespace std;

Database* Studs;

int main(int argc, char** argv) { //reads command from user and determines what command is being asked of.
	//These commands will create or modify data within the tree and print out all the data entered
	Studs = new Tree();
	while (ProcessCommand());
	delete Studs;
	return 0;
}
bool ProcessCommand() { //determines what command was given and calls on the method associated with it
	string cmd;
	getline(cin, cmd);
	if (cmd == "EXIT") return false;
	if (cmd == "PRINT") Print();
	else if (cmd == "RPRINT") RPrint();
	else if (cmd.substr(0, 3) == "ADD") AddCommand(cmd);
	else if (cmd.substr(0, 6) == "REMOVE") RemoveCommand(cmd);
	else if (cmd.substr(0, 6) == "LOOKUP") LookupCommand(cmd);
	else if (cmd.substr(0, 4) == "EDIT") EditCommand(cmd);
	else cout << "Invalid Command" << endl;
	return true;
}
void Print() { //prints all data stored in the tree
	cout << "Printing list forwards: " << endl;
	DRT* T = Studs->search("");
	string k = T->getnext();
	while (k != "") {
		delete T;
		T = Studs->search(k);
		cout << "Name: " << k << "\t GPA: " << T->getdata() << endl;
		k = T->getnext();
	}
	delete T;
	cout << endl;
}
void RPrint() { //prints all data stored in the tree but backwards
	cout << "Printing list backwards: " << endl;
	DRT* T = Studs->search("");
	string k = T->getprev();
	while (k != "") {
		delete T;
		T = Studs->search(k);
		cout << "Name: " << k << "\t Copies: " << T->getdata() << endl;
		k = T->getprev();
	}
	delete T;
	cout << endl;
}

void AddCommand(string cmd) { //when given on command line, data is added into database if there is a string and a number and returns if it was added or if it already exists
	int q1, q2;
	for (q1 = 0; cmd[q1] != '\"'; q1++);
	for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
	string k = cmd.substr(q1 + 1, q2 - q1 - 1);
	string d = cmd.substr(q2 + 1, cmd.length());
	DRT* T = Studs->search(k);
	if (T->getdata() != "") {
		cout << "\"" << k << "\" already exists in database" << endl;
	}
	else {
		delete T;
		T = Studs->modify(k, d);
		cout << "\"" << k << "\" has been added to database" << endl;
	}
	delete T;
}

void RemoveCommand(string cmd) { //when given on command line, it removes the specific data entry provided and returns whether it was removed or unable to find
	int q1, q2;
	for (q1 = 0; cmd[q1] != '\"'; q1++);
	for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
	string k = cmd.substr(q1 + 1, q2 - q1 - 1);
	DRT* T = Studs->search(k);
	if (T->getdata() == "") {
		cout << "\"" << k << "\" does not exist in the database." << endl;
	}
	else {
		delete T;
		T = Studs->modify(k, "");
		cout << "\"" << k << "\" has been removed from the database." << endl;
	}
	delete T;
}
void LookupCommand(string cmd) { //when given on command line, it searchs the tree for the specific data entry given and returns the string and number
	int q1, q2;
	for (q1 = 0; cmd[q1] != '\"'; q1++);
	for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
	string k = cmd.substr(q1 + 1, q2 - q1 - 1);
	DRT* T = Studs->search(k);
	if (T->getdata() != "") {
		cout << "Name: " << k << "\t GPA: " << T->getdata() << endl;
	}
	else {
		cout << "Not found, but would be close to " << T->getprev() << " and " << T->getnext() << endl;
	}
}
void EditCommand(string cmd) { //makes any changes the user wants to data that is already in the tree and returns if it was edited or if there was nothing to edit
	int q1, q2;
	for (q1 = 0; cmd[q1] != '\"'; q1++);
	for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
	string k = cmd.substr(q1 + 1, q2 - q1 - 1);
	string d = cmd.substr(q2 + 1, cmd.length());
	DRT* T = Studs->search(k);
	if (T->getdata() == "") {
		cout << "\"" << k << "\" does not exist in database" << endl;
	}
	else {
		delete T;
		T = Studs->modify(k, d);
		cout << "\"" << k << "\" has been edited in database" << endl;
	}
	delete T;
}
