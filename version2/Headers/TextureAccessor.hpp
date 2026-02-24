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
  std::string name; //name of the table
	std::string TILESET,
	       			W_ON_TILESET,
				 			H_ON_TILESET,
 				 			X_ON_TILESET,
 			   			Y_ON_TILESET,	
				 			W_ON_MAP,
				 			H_ON_MAP,
				 			X_ON_MAP,
				 			Y_ON_MAP;
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
	void read_table(const std::string& tableName);

  //prints the contents of an entire table
	void print_table(const std::string& sTableName);

	//write the entries last fetched by last call to read_table into 
	//user-defined vector.
	void 
	get_entries(
	std::vector<std::pair<SDL_FRect, SDL_FRect>>::iterator,
	std::vector<std::pair<SDL_FRect, SDL_FRect>>::iterator);

	// check db existence, check if already open. If not, open it.
	TextureAccessor(sqlite3* db);

	// close db and destroy the pointer to it.
	~TextureAccessor();

private:
	std::vector<std::pair<SDL_FRect, SDL_FRect>> vEntries;
	bool table_exists(const std::string& tableName);
	sqlite3* db;
};


#endif 
