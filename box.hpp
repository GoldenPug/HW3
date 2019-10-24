/*
   Box.hpp
   By: Jared Maltos
   Created: 10/21/2019
   CS 202: Homework 03
   Purpose: .hpp file for Box
   Details: Put Box.hpp, Box.cpp, and boxtest2.cpp into a project to work
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

//class Box
class Box {
public:

	int getWidth() const; //accessor fucntion width

	void setWidth(int width); //mutator function width

	int getHeight() const; //accessor function heightaccessor fucntion width

	void setHeight(int height); //mutator function height 

	enum Boxtype { FILLED, HOLLOW, CHECKERED }; //an enumerated type with values FILLED, HOLLOW, and CHECKERED

	Box(); //default constructor: 1 x 1 box

	Box(const Box& obj); //copy constuctor

	Box(int width, int height); //parameterized constuctor: filled

	Box(int width, int height, Boxtype type); //parameterized constuctor: hollow / filled / checkered

	~Box(); //destructor

	string type() const; //returns filled, hollow, or checkered box

	static int howMany(); //static member function that gets and returns how many box objects currently exist

private:
	Boxtype _type;

	int _height;

	int _width;

	static int boxTracker;
};

/*
operator<< function which	draws the box to the ostream
print a newline at the end of every line including the last
returns ostream ouput
*/
ostringstream& operator<<(ostringstream& out, const Box& obj);

#endif 
//end of file