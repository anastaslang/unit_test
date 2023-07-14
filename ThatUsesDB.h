#pragma once
#include"DBConnection.h"
#include<mysql/mysql.h>


class ThatUsesDB : public IDBConnection
{
private:
    MYSQL mysql;
    MYSQL_RES* res;
    MYSQL_ROW row;
    
public:
    ThatUsesDB();
    ~ThatUsesDB();

    void openDB(const char* root, const char* pass, const char* nameDB) override;
    
    void closeDB()override;

    void createTable() override;

    bool insertUser(const std::string& name, const std::string& login, const std::string& password) override;
    
    void printUsers() override;

    void deleteTable()override;
};

