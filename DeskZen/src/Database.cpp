/*
 * Database.cpp
 *
 *  Created on: 27/02/2014
 *      Author: ulysses
 */

#include "Database.h"

#include "soci.h"
#include "soci/sqlite3/soci-sqlite3.h"

Database& Database::getInstance()
{
	static Database instance;
	return instance;
}

Database::Database() {
	soci::session sql(soci::sqlite3, "deskzen.db");
}
