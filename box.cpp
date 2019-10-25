/*
   Box.cpp
   By:Jared Maltos
   Created: 10/21/2019
   CS 202: Homework 03
   Purpose: .cpp file for Box
   Details: Put Box.hpp, Box.cpp, and boxtest.cpp into a project to work
*/

#include "box.hpp"

#include "Box.hpp"
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <ostream>
using std::ostream;

int Box::boxTracker = 0;

//gets width
int Box::getWidth() const {
	return _width;
}

//sets width
void Box::setWidth(int width) {
	_width = width;
}

//gets height
int Box::getHeight() const {
	return _height;
}

//sets height
void Box::setHeight(int height) {
	_height = height;
}

//default constructor: 1 x 1 filled box
Box::Box() {
	_width = 1;

	_height = 1;

	_type = FILLED;

	boxTracker++;
}

//parameterized constructor: filled
Box::Box(int width, int height) {
	_height = height;

	_width = width;

	_type = FILLED;

	boxTracker++;
}

//parameterized constructor: hollow, filled, and checkered
Box::Box(int width, int height, Boxtype type) {
	_height = height;

	_width = width;

	_type = type;

	boxTracker++;
}

//copy constructor
Box::Box(const Box& obj) {

	_width = obj._width;

	_height = obj._height;

	_type = obj._type;

	boxTracker++;
}

//member function returns either the string Filled, Hollow, or Checkered
string Box::type() const {
	if (_type == FILLED) {
		return "Filled";
	}

	else if (_type == HOLLOW) {
		return "Hollow";
	}

	else if (_type == CHECKERED) {
		return "Checkered";
	}

}

//deconstructor
Box::~Box() {
	boxTracker = 1;
}

//prints filled / hollow / checkered boxes
ostringstream& operator<<(ostringstream& out, const Box& obj) {
	int lineCounter = 0;

	for (int borderline = 0; borderline < obj.getWidth(); borderline++) {

		if (obj.type() == "Checkered") {

			if (borderline % 2 == 0)
				out << "x";

			if (borderline % 2 != 0)
				out << " ";
		}

		else {

			if (obj.getWidth() != 1 && obj.getHeight() != 1) {
				out << "x";
			}
		}
	}

	if (obj.getWidth() != 1 && obj.getHeight() != 1) out << endl;
	for (int line = 0; line < obj.getHeight() - 2; line++) {

		for (int column = 0; column < 1; column++) {

			if (obj.type() == "Checkered") {

				out << " ";
			}

			else if (obj.type() != "Checkered") {
				out << "x";
			}

			lineCounter++;
		}

		for (int row = 0; row < obj.getWidth() - 2; row++) {
			if (obj.type() == "Filled") {
				out << "x";
			}

			else if (obj.type() == "Checkered") {

				if (row % 2 == 0)
					out << "x";

				if (row % 2 != 0)
					out << " ";
			}

			else if (obj.type() == "Hollow") {
				out << " ";
			}
		}

		for (int column = 0; column < 1; column++) {
			if (obj.type() == "Checkered")
				out << " ";

			else
				out << "x";
		}

		out << endl;
	}

	for (int borderline = 0; borderline < obj.getWidth(); borderline++) {
		if (obj.type() == "Checkered") {

			if (lineCounter % 2 == 0) {
				if (borderline % 2 == 0)
					out << " ";

				if (borderline % 2 != 0)
					out << "x";
			}
			if (lineCounter % 2 != 0) {
				if (borderline % 2 == 0)
					out << "x";

				if (borderline % 2 != 0)
					out << " ";
			}
		}

		else {
			out << "x";
		}
	}

	out << endl;

	cout << out.str();

	return out;
}
//end of file