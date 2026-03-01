#ifndef TEXTUREACCESSOR_H
#define TEXTUREACCESSOR_H

#include <sqlite3.h>


struct TextureTableEntry {
public:
	std::string tileset; //columns
	float widthOnTileset;
 				heightOnTileset,
				xOnTileset,
				yOnTileset,	
				widthOnMap,
				heightOnMap,
				xOnMap,
				yOnMap;

};


// values of the independent values in each column
struct TextureTable {
public:
	static const std::string TILESET = "TILESET";
													 W_ON_TILESET = "W_ON_TILESET";
													 H_ON_TILESET = "H_ON_TILESET";
													 X_ON_TILESET = "X_ON_TILESET";
													 Y_ON_TILESET = "Y_ON_TILESET";
													 W_ON_MAP = "W_ON_MAP";
													 H_ON_MAP = "H_ON_MAP";
													 X_ON_MAP = "X_ON_MAP";
													 Y_ON_MAP = "Y_ON_MAP";
};


/**
	* class for creating, reading, writing and modifying texture tables.
	* //TODO class for opening, closing and erasing databases
	*/
class TextureAccessor {
public:
	//create table
	void create_table(const std::string& sTableName);
	//append entry to table
	void write(const std::string& tableName,
	const TextureTableEntry&);

	//extract the contents of line id in memory 
	TextureTableEntry* read_line(const std::string& tableName, const int id);

	void delete_line(const std::string& tableName, const int id);

	//reads the entire table
	void read_table(const std::string& tableName);

  //prints the contents of an entire table
	void print_table(const std::string& sTableName);

	

	//get the entry last fetched by read_line() call
	TextureTableEntry* get_entry();

	//write the entries last fetched by last read_table call into 
	//user-defined vector.
	const std::vector<std::pair<SDL_FRect, SDL_FRect>>& get_entries();

	// check db existence, check if already open. If not, open it.
	TextureAccessor(sqlite3* db);

	// close db and destroy the pointer to it.
	~TextureAccessor();

private:
  TextureTableEntry* entry;
	std::vector<std::pair<SDL_FRect, SDL_FRect>> vEntries;
	bool table_exists(const std::string& tableName);
	//callbacks
	int store_tiles(void* userData, int argc, 
									char** argv, char** azColName);
	int print_results(void* userData, int argc,
										char** argv, char** azColName);
	sqlite3* db;
};


#endif 
