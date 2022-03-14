
//Madison Sawvel

#ifndef _PG4_
#define _PG4_
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv); //reads command from user and determines what command is being asked of 
bool ProcessCommand();  //determines what command was given and calls on the method associated with it
void Print(); //prints all data stored in the tree
void RPrint(); //prints all data stored in the tree but backwards
void AddCommand(string cmd); //when given on command line, data is added into database if there is a string and a number and returns if it was added or if it already exists
void RemoveCommand(string cmd); //when given on command line, it removes the specific data entry provided and returns whether it was removed or unable to find
void LookupCommand(string cmd); //when given on command line, it searchs the tree for the specific data entry given and returns the string and number
void EditCommand(string cmd); //makes any changes the user wants to data that is already in the tree and returns if it was edited or if there was nothing to edit

#endif