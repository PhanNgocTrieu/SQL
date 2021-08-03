#pragma once
#ifndef __ISOLATED_H__
#define __ISOLATED_H__
#include "Table.h"

static int callbackValues(void* NotUsed, int argc, char** argv, char** azColName);
static int callbackColName(void* NotUsed, int argc, char** argv, char** azColName);


class isolated : public Tables
{
private:
	static int isolatedID;
	std::vector<ISOLATED> mIsolatedInfor;
	std::string dirToDB;
	ISOLATED isolatedInformation;
public:
	isolated(const std::string& dirDB);
	~isolated();
	// Table
	void createTable();
	void droptable();

	// Values
	void insertValues();
	void insertValuesAuto();
	void deleteValues();
	void updateValues();
	void filterValues();
	void displayTable();

public:
	void takeIsolatedForm(const ISOLATED& _isoPlace);
};

#endif // !__ISOLATED_H__



