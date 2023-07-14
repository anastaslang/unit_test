testdb: main.cpp
	g++ -o testdb main.cpp ThatUsesDB.cpp -lgtest -lgmock -L/usr/include/mysql -lmysqlclient -I/usr/include/mysql
clean: 
	rm  testdb