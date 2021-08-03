#pragma once
#ifndef __MYSQL_H__
#define __MYSQL_H__
#include <vector>
#include <iostream>



typedef struct manInfor
{
	int Man_ID;
	std::string mName;
	std::string mLocation;
	std::vector<std::string> mArea;
	manInfor() : Man_ID{ 0 }, mName{ "" }, mLocation{ "" } {}
} ManInfor;

typedef struct isolatedInfor
{
	int area_ID;
	std::string namOfArea;
	isolatedInfor() : area_ID{ 0 }, namOfArea{ "" } {}
} ISOLATED;


class Tables
{
protected:
	int rc{ -1 };
	char* errMsg{ nullptr };
	std::string sqlCommand{ "" };
public:
	// Constructor and Destructor
	virtual ~Tables() {};

	// Table
	virtual void createTable() = 0;
	virtual void droptable() = 0;

	// Values
	virtual void insertValues() = 0;
	virtual void insertValuesAuto() = 0;

	virtual void deleteValues() = 0;

	virtual void updateValues() = 0;

	virtual void filterValues() = 0;

	virtual void displayTable() = 0;
};



#endif // !__MYSQL_H__


