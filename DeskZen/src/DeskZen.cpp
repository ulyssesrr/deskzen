//============================================================================
// Name        : DeskZen.cpp
// Author      : Ulysses
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iterator>

#include <boost/log/trivial.hpp>
#include <boost/program_options.hpp>

#include "DeskZen.h"
#include "Database.h"

namespace po = boost::program_options;

// A helper function to simplify the main part.
template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, " "));
    return os;
}

int main(int ac, char* av[]) {
	// Declare the supported options.
	po::options_description desc("Allowed options");
	desc.add_options()
	    ("help", "produce help message")
	    ("add-file,a", po::value< std::vector<std::string> >(), "Add files to DeskZen")
	    ("origin-protocol,p", po::value<std::string>(), "Informs the protocol that received the files")
	    ("origin-application,o", po::value<std::string>(), "Informs the application that received the files")
	;

	po::positional_options_description p;
	p.add("add-file", -1);

	po::variables_map vm;
	po::store(po::command_line_parser(ac, av).options(desc).positional(p).run(), vm);
	po::notify(vm);

	if (vm.count("help")) {
		std::cout << "Usage: deskzen [options]" << std::endl;
	    std::cout << desc << "\n";
	    return 1;
	}



	BOOST_LOG_TRIVIAL(info) << "Initializing...";
	try {
		DeskZen::getInstance();
	}
	catch (std::exception const &e)
	{
		BOOST_LOG_TRIVIAL(error) << "Error: " << e.what();
	}
	BOOST_LOG_TRIVIAL(info) << "DeskZen ready!";

	if (vm.count("add-file"))
	{
		std::cout << "adding files: " << vm["add-file"].as<std::vector<std::string> >() << std::endl;

		std::vector<std::string> v = vm["add-file"].as<std::vector<std::string> >();

		for(std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) {
			int pid = fork();
			if (pid == 0) {
				execl("/usr/bin/xdg-open", "xdg-open", it->c_str(), (char *)0);
				exit(1);
			}
			BOOST_LOG_TRIVIAL(info) << "Exec done: " << *it;
		}
	}

	return 0;
}

DeskZen& DeskZen::getInstance()
{
	static DeskZen instance;
	return instance;
}

DeskZen::DeskZen() {
	database = std::unique_ptr<Database>(new Database("deskzen.db"));
}

const std::unique_ptr<Database>& DeskZen::getDatabase()
{
	return database;
}
