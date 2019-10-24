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