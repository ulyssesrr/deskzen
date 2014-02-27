/*
 * Database.cpp
 *
 *  Created on: 27/02/2014
 *      Author: ulysses
 */

#include "Database.h"

#include "soci.h"
#include "soci/sqlite3/soci-sqlite3.h"

Database::Database(std::string const& filename) {
	soci::session sql(soci::sqlite3, filename);
}
