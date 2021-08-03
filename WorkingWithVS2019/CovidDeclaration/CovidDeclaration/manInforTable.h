#pragma once
#ifndef __MANINFORTABLE_H__
#define __MANINFORTABLE_H__

#include "Table.h"
#include <iostream>
#include <vector>

static int callbackValues(void* NotUsed, int argc, char** argv, char** azColName);
static int callbackColName(void* NotUsed, int argc, char** argv, char** azColName);


class manInforTable : public Tables
{
	static int manID;
	std::vector<ManInfor> mManInfor;
	std::string dirToDB;
	ManInfor manInformation;
public:
	manInforTable(const std::string& dirDB);
	~manInforTable();


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
	void takeManInFor(const ManInfor& _inforOfMan);

};

std::string plusPassing(std::vector<std::string> passing);

#endif // !__MANINFORTABLE_H__

