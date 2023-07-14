#pragma once
#include"MockIDBConnection.h"
#include<gtest/gtest.h>
#include<gmock/gmock.h>


class MyTestSuite : public ::testing::Test
{
protected:	
	void SetUp() {
		std::cout << "Установки теста\n" << std::endl;
		dbconnect.openDB("***", "***", "***"); //вместо звёздочек надо ввести юзера, пароль и имя БД
		dbconnect.createTable();
	}
	void TearDown() {
		std::cout << "Сброс утановок\n" << std::endl;
		dbconnect.deleteTable();
		dbconnect.closeDB();
	}
	
protected:
	ThatUsesDB dbconnect;
};

TEST_F(MyTestSuite, test2)
{
	bool b = dbconnect.insertUser("Nastia", "Anastas", "12345");
	ASSERT_EQ(b, true);
}
