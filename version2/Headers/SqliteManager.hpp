#ifndef SQLITEMANAGER_H
#define SQLITEMANAGER_H

#include <sqlite3.h>

//table structure
struct TextureTable {
public:
	std::string name; //name of the table

	std::string Tileset; //columns
	std::string widthOnTileset;
	std::string heightOnTileset;
	std::string xOnTileset;
	std::string yOnTileset;	

};


struct TextureTableEntry {
public:
	std::string Tileset;
	int widthOnTileset;


};




class Statement {
public:
	Statement();
	//void write() = 0;
	//void deleteLine() = 0;
};


//insert/delete texture related information from db
class TextureStatement : public Statement {
public:
	//append entry to table
	void write(sqlite3* db, const TextureTableEntry&);

	//extract the contents of line id in memory 
	Texture* readLine(sqlite3* db, const TextureTable&, const int);

	void deleteLine(sqlite3* db, const TextureTable&, const int);


	TextureStatement(Texture*, TextureTable*);
private:
	// the different parts of the statement
	TextureTableEntry* entry; //created in constructor out of texture 
	TextureTable* table;
};


class Memory {
public:
	//opens a database
	void init();

	//creates a texture table out of the texture
	//creates an insert statement based on the
	void save_texture(Texture* texture);

	
private:
	//callback
	int print_results(void* userData, int argc, char** argv, 
	char** azColName);
	int check_tab_existence(void* userData, int argc,
	char** argv, char** azColname);	


	void open(sqlite3** db);

	static void close(sqlite3* db);

	// for textures, later new methods for pkmns maybe
	static void create_texture_table(sqlite3* db, const table& table);

	static void select_all_records_from_table(sqlite* db, 
	const std::string& tableName);

	static void update(sqlite3* db);
private:
	static bool table_exists(sqlite3* db);
	static sqlite3* database_;
};


#endif 
