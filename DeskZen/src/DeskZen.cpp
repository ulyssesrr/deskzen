//============================================================================
// Name        : DeskZen.cpp
// Author      : Ulysses
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <boost/log/trivial.hpp>

#include "Database.h"

using namespace std;

int main() {
	BOOST_LOG_TRIVIAL(info) << "Loading database...";
	try {
		Database::getInstance();
	}
	catch (exception const &e)
	{
		BOOST_LOG_TRIVIAL(error) << "Database Error: " << e.what();
	}
	BOOST_LOG_TRIVIAL(info) << "Database Loaded!";
	return 0;
}
