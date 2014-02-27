/*
 * DeskZen.h
 *
 *  Created on: 27/02/2014
 *      Author: ulysses
 */

#ifndef DESKZEN_DESKZEN_H_
#define DESKZEN_DESKZEN_H_

#include "Database.h"

class DeskZen {
public:
	static DeskZen& getInstance();
	const std::unique_ptr<Database>& getDatabase();
private:
	std::unique_ptr<Database> database;

	DeskZen();
	DeskZen(DeskZen const&);
	void operator=(DeskZen const&);
};

#endif /* DESKZEN_DESKZEN_H_ */
