#include "../Headers/Database.hpp"


void Database::open(const std::string& sDbName) {
	int rc;

  rc = sqlite3_open(sDbName, &this->db);
	if (rc) {
		std::fprintf(stderr, "Cannot open db: %s\n", 
													sqlite3_errmsg(this->db));
	}
	else {
		std::fprintf(stderr, "Opened database successfully\n");	
	}
}


void Database::close() {
	sqlite3_close(this->db);
}


sqlite3* Database::get_db() {
	return db;
}


bool Database::is_open() {
	return this->db != nullptr;
}


Database::Database() {
	this->db = nullptr;
}


~Database::Database() {
	if (this->is_open()) {
		this->close();
	}
}
