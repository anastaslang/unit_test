#include"ThatUsesDB.h"

ThatUsesDB::ThatUsesDB()
{
    std::cout << "Вызов конструктора ThatUsesDB\n";   
}

ThatUsesDB::~ThatUsesDB() 
{
    std::cout << "Вызов деструктора ThatUsesDB\n";    
}

void ThatUsesDB::openDB(const char* root, const char* pass, const char* nameDB) {
    mysql_init(&mysql);
    if (&mysql == nullptr)
    {
        std::cout << "Ошибка: дескриптор соединения MySQL не создан." << std::endl;
        exit(1);
    }
    MYSQL* connect = mysql_real_connect(&mysql, "localhost", root, pass, nameDB, 0, NULL, 0);
    if (connect == nullptr)
    {
        std::cout << "Невозможно подключится к базе данных. Ошибка:  " << mysql_error(&mysql) << std::endl;
        exit(1);
    }
}

void ThatUsesDB::closeDB() {

    std::cout << "База закрыта\n";
    mysql_close(&mysql);
}

void ThatUsesDB::createTable()
{
    mysql_query(&mysql, "create table if not exists userstest (id INT AUTO_INCREMENT primary key not null, 	\
     name varchar(200) not null,	login varchar(200)  not null, user_password varchar(200))");   
}

bool ThatUsesDB::insertUser(const std::string& name, const std::string& login, const std::string& password)
{
    const std::string str = "insert into userstest (id, name, login, user_password) values \
     (default, '" + name + "', '" + login + "', '" + password + "')";

    mysql_query(&mysql, str.c_str());
    if (mysql_errno(&mysql))
    {
        cout << "Insert error" << endl;
        return false;
    }
    else
    {
        cout << "Insert OK" << endl;
        return true;
    }
}

void ThatUsesDB::printUsers() {
    mysql_query(&mysql, "SELECT * FROM userstest"); //Делаем запрос к таблице
    if (res = mysql_store_result(&mysql)) {
        while (row = mysql_fetch_row(res)) {
            for (size_t i = 0; i < mysql_num_fields(res); i++) {
                cout << row[i] << "  ";
            }
            cout << endl;
        }
        std::cout << "Печать\n";
    }
    else
        cout << "Ошибка MySql номер " << mysql_error(&mysql);
}

void ThatUsesDB::deleteTable() {
    mysql_query(&mysql, "drop table userstest");
 
    std::cout << "\nТаблица удалена\n";
}


