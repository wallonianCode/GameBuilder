#ifndef TEXTUREACCESSOR_H
#define TEXTUREACCESSOR_H

#include <sqlite3.h>

//table structure
struct TextureTable {
public:
	std::string name; //name of the table

	std::string Tileset, //columns
 							widthOnTileset;
 							heightOnTileset,
 							xOnTileset,
 						  yOnTileset,	
							widthOnMap,
							heightOnMap,
							xOnMap,
							yOnMap;

};


// values of the independent values in each column
struct TextureTableEntry {
public:
	std::string Tileset;
	float widthOnTileset,
				heightOnTileset,
 				xOnTileset,
 			  yOnTileset,	
				widthOnMap,
				heightOnMap,
				xOnMap,
				yOnMap;
};


//insert/delete texture related information from db
class TextureAccessor {
public:
	//append entry to table
	void write(const std::string& tableName,
	const TextureTableEntry&);

	//extract the contents of line id in memory 
	TextureTableEntry* read_line(const std::string& tableName, const int id);

	void delete_line(const std::string& tableName, const int id);

	//reads the entire table
	std::vector<TextureTableEntry*> read_table(const std::string& tableName);

  //prints the contents of an entire table
	void print_table(const std::string& tableName);

	// check db existence, check if already open. If not, open it.
	TextureAccessor(sqlite3* db);

	// close db and destroy the pointer to it.
	~TextureAccessor();

private:
	bool table_exists(const std::string& tableName);
	sqlite3* db;
};


#endif 
