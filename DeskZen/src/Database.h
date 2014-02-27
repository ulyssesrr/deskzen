/*
 * Database.h
 *
 *  Created on: 27/02/2014
 *      Author: ulysses
 */

#ifndef DESKZEN_DATABASE_H_
#define DESKZEN_DATABASE_H_

class Database {
public:
	static Database& getInstance();
private:
	Database();
	Database(Database const&);
	void operator=(Database const&);
};

#endif /* DESKZEN_DATABASE_H_ */
