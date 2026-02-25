#include  "../Headers/TextureAccessor.hpp"

void 
TextureAccessor::write(const std::string& sTableName,
											 const TextureTableEntry& entry) {
	int rc;
	const char* sqlStatement;
	char* zErrMsg;

  zErrMsg = 0;
	sqlStatement = 
	"INSERT INTO " + sTableName + 
	" ("+ TextureTable::TILESET+","+TableTable::W_ON_TILESET+","+ 
	TextureTable::H_ON_TILESET + "," + TextureTable::X_ON_TILESET + "," +
	TextureTable::Y_ON_TILESET + "," + TextureTable::W_ON_MAP + ","+
	TextureTable::W_ON_MAP + "," + TextureTable::H_ON_MAP + "," +
	TextureTable::X_ON_MAP + "," + TextureTable::Y_ON_MAP + ")"\
	"VALUES ("+entry.tileset+", "+entry.widthOnTileset+", "+ 
	entry.heightOnTileset+", "+entry.xOnTileset+", "+entry.yOnTileset+
	", "+entry.widthOnMap+", "+entry.heightOnMap+", "+entry.xOnMap+", "+
	entry.yOnMap+")";
	
	rc = sqlite3_exec(this.db, sqlStatement, 0, 0, &zErrMsg);
	if ( rc != SQLITE_OK ) {
		std::fprintf(stderr, "Misuse. SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} 
	else {
		std::fprintf(stdout, "Records created successfully\n");
	}
}
	

int TextureAccessor::store_tiles(void* userData, int argc, char** argv, 
char** azColName) {
	int i;
	TextureTableEntry* entry;

	i = 0;
	while (i < argc) {
		//fill the entry
		//if (azColName[i] = 
		//entry->widthOnTileset = argv[i];


	  ++i;
	}
	//store the entry in dedicated vector.
	return 0;
}


int print_results(void* userData, int argc, char** argv, 
char** azColName) {
	int i;
	i = 0;
	while (i < argc) {
		std::fprintf(stdout, "%s = %s\n", 
		azColName[i], argv[i] ? argv[i] : NULL);
		++i;
	}
	std::printf("\n");
	return 0;
}



TextureTableEntry* 
TextureAccessor::read_line(const std::string& sTableName, 
											     const int xOnMap) {
	int rc;	
	const char* selectStatement; 
	char* zErrMsg;
	const char* data = "Callback function called";

	selectStatement = 
	"SELECT * FROM " + sTableName + " WHERE " + 
	TextureTable::X_ON_MAP + " = " + xOnMap;
	rc = sqlite3_exec(db, selectStatement, store_tiles, 
	(void*)data, &zErrMsg); 

	if (rc == SQLITE_MISUSE) {
	  std::fprintf(stderr, "Sqlite misuse!\n");
		sqlite3_free(zErrMsg);
	}
	else if (rc != SQLITE_OK) {
		std::fprintf(stderr, "%d, SQL error: %s\n", rc, zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		std::fprintf(stdout, "Selected all records successfully\n");
	}
	sqlite3_close(db);

}


void 
TextureAccessor::delete_line(const std::string& sTableName, 
														 const int xOnMap) {
	int rc;
	char* zErrMsg;
	const char* sqlStatement;

	sqlStatement = 
	"DELETE FROM " + sTableName + " WHERE "+
	TextureTable::X_ON_MAP+"="xOnMap+"; ";
	rc = sqlite3_exec(db, sqlStatement, 0, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		std::fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		std::fprintf(stdout, "Line successfully deleted\n");
	}

}

void	
TextureAccessor::read_table(const std::string& sTableName) {
	int rc;	
	const char* selectStatement; 
	char* zErrMsg;
	const char* data = "Callback function called";

	selectStatement = "SELECT * FROM " + sTableName;
	rc = sqlite3_exec(db, selectStatement, store_tiles, 
	(void*)data, &zErrMsg); 

	if (rc == SQLITE_MISUSE) {
	  std::fprintf(stderr, "Sqlite misuse!\n");
	}
	else if (rc != SQLITE_OK) {
		std::fprintf(stderr, "%d, SQL error: %s\n", rc, zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		std::fprintf(stdout, "Selected all records successfully\n");
	}
	sqlite3_close(db);
}


void 
TextureAccessor::print_table(const std::string& sTableName) {
	int rc;	
	const char* selectStatement; 
	char* zErrMsg;
	const char* data = "Callback function called";

	selectStatement = "SELECT * FROM "+sTableName;
	rc = sqlite3_exec(db, selectStatement, print_results, 
	(void*)data, &zErrMsg); 

	if (rc == SQLITE_MISUSE) {
	  std::fprintf(stderr, "Sqlite misuse!\n");
	}
	else if (rc != SQLITE_OK) {
		std::fprintf(stderr, "%d, SQL error: %s\n", rc, zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		std::fprintf(stdout, "Selected all records successfully\n");
	}
	sqlite3_close(db);


}


TextureTableEntry* get_entry() {}


void 
get_entries(
std::vector<std::pair<SDL_FRect, SDL_FRect>>::iterator,
std::vector<std::pair<SDL_FRect, SDL_FRect>>::iterator) {}


TextureAccessor::TextureAccessor(sqlite3* db) {}


~TextureAccessor::TextureAccessor() {}



/*
bool bTableExists = false;

static int print_results(void* userData, int argc, char** argv, 
char** azColName) {
	int i;
	i = 0;
	while (i < argc) {
		std::fprintf(stdout, "%s = %s\n", 
		azColName[i], argv[i] ? argv[i] : NULL);
		++i;
	}
	std::printf("\n");
	return 0;
}


static int check_tab_existence_callback(void* userData, int argc,
char** argv, char** azColname) {	
	bTableExists = argc > 0;	
	return 0;
}


void open(sqlite3** db) {
	int rc;

  rc = sqlite3_open("test.db", db);
	if (rc) {
		std::fprintf(stderr, "Cannot open db: %s\n", sqlite3_errmsg(*db));
	}
	else {
		std::fprintf(stderr, "Opened database successfully\n");	
	}
}


void close(sqlite3* db) {
	sqlite3_close(db);
}


bool table_exists(sqlite3 *db) {
	int rc;
	const char *selectStatement;	
	char* zErrMsg;
  void* data;

  zErrMsg = 0;
	data = 0;

	selectStatement = "SELECT name FROM sqlite_master WHERE type='table'" \
										"AND name='COMPANY'";
	rc = sqlite3_exec(db, selectStatement, check_tab_existence_callback, 
	data, &zErrMsg);

	if (rc == SQLITE_ABORT) {
		std::fprintf(stderr, "table_exists could not execute: %s\n", 
		zErrMsg);
		
	}
	else if (rc == SQLITE_OK) {
		std::fprintf(stderr, "table existence successfully checked\n");	
	}
	else {
		std::fprintf(stderr, "table_exists aborted: %d : %s\n", rc, zErrMsg); 
	}

	return bTableExists;
}


void create_table(sqlite3* db) {
	int rc;
	const char *createStatement;
	char* zErrMsg;
  void* data;

  zErrMsg = 0;
	data = 0;
  createStatement = "CREATE TABLE COMPANY(" \
						"ID INT PRIMARY KEY     NOT NULL," \
						"NAME           TEXT    NOT NULL," \
						"AGE            INT		  NOT NULL," \
						"ADDRESS        CHAR(50)," \
						"SALARY         REAL );";

	rc = sqlite3_exec(db, createStatement, 0, data, &zErrMsg);
	if (rc != SQLITE_OK) {
		std::fprintf(stderr, 
		"Create table statement unsuccessful: SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		std::fprintf(stdout, "Table created successfully\n");
	}
}


void insert(sqlite3* db) {
	int rc;
	const char* sqlStatement;
	char* zErrMsg;

  zErrMsg = 0;
	sqlStatement = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
						 		 "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
  				       "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         				 "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         				 "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         				 "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         				 "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         				 "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";
	rc = sqlite3_exec(db, sqlStatement, 0, 0, &zErrMsg);
	if ( rc == SQLITE_MISUSE ) {
		std::fprintf(stderr, "Misuse. SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} 
	else {
		std::fprintf(stdout, "Records created successfully\n");
	}
}


void select_all_records_from_table(sqlite3* db) {
	int rc;	
	const char* selectStatement; 
	char* zErrMsg;
	const char* data = "Callback function called";

	selectStatement = "SELECT * FROM COMPANY";
	rc = sqlite3_exec(db, selectStatement, print_results, 
	(void*)data, &zErrMsg); 

	if (rc == SQLITE_MISUSE) {
	  std::fprintf(stderr, "Sqlite misuse!\n");
	}
	else if (rc != SQLITE_OK) {
		std::fprintf(stderr, "%d, SQL error: %s\n", rc, zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		std::fprintf(stdout, "Selected all records successfully\n");
	}
	sqlite3_close(db);
}


void update(sqlite3* db) {
	int rc;
	char* zErrMsg = 0;

	const char* sqlStatement;
	
	sqlStatement = "UPDATE COMPANY set SALARY = 25000.00 " \
								 "WHERE ID=1;";
	rc = sqlite3_exec(db, sqlStatement, 0, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		std::fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		std::fprintf(stdout, "Records updated successfully\n");
	}
}


void delete_from_table(sqlite3* db) {
	int rc;
	char* zErrMsg;
	const char* sqlStatement;

	sqlStatement = "DELETE FROM COMPANY WHERE ID=2; ";
	rc = sqlite3_exec(db, sqlStatement, 0, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		std::fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		std::fprintf(stdout, "Line successfully deleted\n");
	}
}



int main(int argc, char** argv) {
	sqlite3* db;
 
  db = 0;

	open(&db);	
	if (!table_exists(db)) {
		create_table(db);
	}
	if (table_exists(db)) {
		insert(db);
		update(db);
		delete_from_table(db);
	}
	
	select_all_records_from_table(db);	
	close(db);	
	return 0;
}
*/
