#include "isolated.h"
#include "sqlite3.h"
#include <string>
#include <iomanip>

int isolated::isolatedID = 0;

isolated::isolated(const std::string& dirDB)
{
	this->dirToDB = dirDB;
	sqlite3* DB;
	this->dirToDB = dirDB;
	rc = sqlite3_open(dirToDB.c_str(), &DB);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Connect to DB failed!\n");
	}

	sqlite3_close(DB);
}

isolated::~isolated()
{
	if (errMsg)
	{
		delete errMsg;
		errMsg = nullptr;
	}
}

void isolated::createTable()
{
	sqlCommand = "CREATE TABLE IF NOT EXISTS Isolated("
		"areaID INT PRIMARY KEY NOT NULL,"
		"namOfArea VARCHAR(255) NOT NULL"
		");"
		;

	sqlite3* DB;
	rc = sqlite3_open(dirToDB.c_str(), &DB);
	rc = sqlite3_exec(DB, sqlCommand.c_str(), callbackValues, 0, &errMsg);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Error: %s\n", errMsg);
		free(errMsg);
	}
	else
	{
		fprintf(stdout, "Created Isolated Table successfull\n");
	}


	sqlite3_close(DB);
}

void isolated::droptable()
{
	sqlCommand = "DROP TABLE IF EXISTS Isolated;";

	sqlite3* DB;
	rc = sqlite3_open(dirToDB.c_str(), &DB);
	rc = sqlite3_exec(DB, sqlCommand.c_str(), callbackValues, 0, &errMsg);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Error: %s\n", errMsg);
		free(errMsg);
	}
	else
	{
		fprintf(stdout, "Drop Isolated Table successfull\n");
	}
	sqlite3_close(DB);
}

void isolated::insertValues()
{
	mIsolatedInfor.push_back(isolatedInformation);

	sqlCommand = "INSERT INTO Isolated(areaID,namOfArea) "
		"VALUES('" + std::to_string(isolatedInformation.area_ID)
		+ "', '" + isolatedInformation.namOfArea + "');"
		;

	sqlite3* DB;
	rc = sqlite3_open(dirToDB.c_str(), &DB);
	rc = sqlite3_exec(DB, sqlCommand.c_str(), callbackValues, 0, &errMsg);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Error: %s\n", errMsg);
		free(errMsg);
	}
	else
	{
		fprintf(stdout, "Insert Isolated Table successfull\n");
	}
	sqlite3_close(DB);
}

void isolated::insertValuesAuto()
{
	std::string places[] = { "Da Nang", "Hoa Khanh", "Ngu Hanh Son", "Sai Gon" };
	for (int idex = 0; idex < 4; idex++)
	{
		isolatedInfor isolatedPlaces;
		isolatedPlaces.area_ID = idex + 1;
		isolatedPlaces.namOfArea = places[idex];

		sqlCommand = "INSERT INTO Isolated(areaID,namOfArea) "
			"VALUES('" + std::to_string(isolatedPlaces.area_ID) 
			+ "', '" + isolatedPlaces.namOfArea + "');"
			;

		sqlite3* DB;
		rc = sqlite3_open(dirToDB.c_str(), &DB);
		rc = sqlite3_exec(DB, sqlCommand.c_str(), callbackValues, 0, &errMsg);

		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "Error: %s\n", errMsg);
			free(errMsg);
		}
		else
		{
			fprintf(stdout, "Insert Isolated Table successfull\n");
		}
		sqlite3_close(DB);
	}

	isolated::isolatedID = 4;
}

void isolated::deleteValues()
{
	sqlCommand = "DELETE FROM Isolated;";

	sqlite3* DB;
	rc = sqlite3_open(dirToDB.c_str(), &DB);
	rc = sqlite3_exec(DB, sqlCommand.c_str(), callbackValues, 0, &errMsg);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Error: %s\n", errMsg);
		free(errMsg);
	}
	else
	{
		fprintf(stdout, "Delete all of values Isolated Table successfull\n");
	}
	sqlite3_close(DB);
}

void isolated::updateValues()
{
}

void isolated::filterValues()
{
}

void isolated::displayTable()
{
	std::cout << "\n\n\t************************* Information of Isolated Places *************************";
	
	sqlite3* DB;
	rc = sqlite3_open(dirToDB.c_str(), &DB);
	sqlCommand = "SELECT * FROM Isolated LIMIT 1;";
	rc = sqlite3_exec(DB, sqlCommand.c_str(), callbackColName, 0, &errMsg);
	sqlCommand = "SELECT * FROM Isolated;";
	rc = sqlite3_exec(DB, sqlCommand.c_str(), callbackValues, 0, &errMsg);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Error: %s\n", errMsg);
		free(errMsg);
	}

	sqlite3_close(DB);
}

void isolated::takeIsolatedForm(const ISOLATED& _isoPlace)
{
	this->isolatedInformation = _isoPlace;
}


int callbackValues(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	std::cout << "|";
	for (i = 0; i < argc; i++) {
		std::cout << std::left << std::setw(20) << std::setfill(' ') << argv[i] << "|";
	}
	printf("\n");
	return 0;
}

int callbackColName(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	std::cout << std::endl;
	std::cout << "|";
	for (i = 0; i < argc; i++) {
		std::cout << std::left << std::setw(20) << std::setfill(' ') << azColName[i] << "|";
	}
	printf("\n");
	std::cout << "    ";
	for (int idex = 0; idex < i * 20; idex++)
	{
		std::cout << "-";
	}
	printf("\n");
	return 0;
}

