/*
 * Database.h
 *
 *  Created on: 27/02/2014
 *      Author: ulysses
 */

#ifndef DESKZEN_DATABASE_H_
#define DESKZEN_DATABASE_H_

#include <string>

class Database {
public:
	Database(const std::string& filename);
private:
	Database(Database const&);
};

#endif /* DESKZEN_DATABASE_H_ */
