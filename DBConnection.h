#pragma once
#include<iostream>
#include<string>


using namespace std;

class IDBConnection {
public:
	IDBConnection() {
		std::cout << "Вызов конструктора IDBConnection\n";
	}
	virtual ~IDBConnection()
	{
		std::cout << "Вызов деструктора IDBConnection\n";
	}

	virtual void openDB(const char *root, const char* pass, const char* nameDB) = 0;

    virtual void createTable() = 0;

	virtual bool insertUser(const std::string& name, const std::string& login, const std::string& password) = 0;
    
	virtual void printUsers() = 0;	

	virtual void closeDB() = 0;

	virtual void deleteTable() = 0;

	
};











