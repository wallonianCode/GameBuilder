#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3>

class Database {
public:
	void open(const std::string&);
	void close(const std::string&);
	sqlite3* get_db();
	bool is_open();
	Database();
	~Database();
private:
	sqlite3* db;

};

#endif
