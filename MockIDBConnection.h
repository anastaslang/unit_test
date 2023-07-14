#pragma once
#include"ThatUsesDB.h"
#include<gtest/gtest.h>
#include"gmock/gmock.h"

void runDB(IDBConnection* dbconnect)
{
    dbconnect->openDB("***", "***", "***"); 
    dbconnect->createTable();
    dbconnect->insertUser("Nastia", "Anastas", "12345");
    dbconnect->insertUser("Nasty", "Anastasia", "33441");
    dbconnect->printUsers();
    dbconnect->deleteTable();
    dbconnect->closeDB();
}

class MockIDBConnection : public IDBConnection
{
public:
    
    MOCK_METHOD(void, openDB, (const char* root, const char* pass, const char* nameDB), (override));
    MOCK_METHOD(void, createTable, (), (override));
   
    MOCK_METHOD(bool, insertUser, (const std::string& name, const std::string& login, const std::string& password), (override));
    MOCK_METHOD(void, printUsers, (), (override));
    MOCK_METHOD(void, deleteTable, (), (override));
    MOCK_METHOD(void, closeDB, (), (override));

};

TEST(IDBConnection, test1){
    
    ::testing::NaggyMock<MockIDBConnection> mconnect;
    EXPECT_CALL(mconnect, openDB).Times(1);
    EXPECT_CALL(mconnect, createTable).Times(1);   
    EXPECT_CALL(mconnect, insertUser).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(mconnect, printUsers).Times(::testing::AtLeast(1));
    EXPECT_CALL(mconnect, deleteTable).Times(1);
    EXPECT_CALL(mconnect, closeDB).Times(1);

    runDB(&mconnect);
}

