#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H


#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <unordered_map>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

//const std::string tileSheetsPath = "C:/Users/z004ryjh/Desktop/GIT/Workspace_GIT_GameBuilder/GameBuilder/TileSheets";
//"/home/bogenschuetze/GamesCPP/GameBuilder/TileSheets";
const std::string relativeTileSheetPath = "TileSheets";
const std::string landTileSet = "pkmnLeafGreenTileset2";
const std::string LANDTILESET = "pkmnLeafGreenTileset2";

class TextureLoader {
public:
	static SDL_Texture* load_texture(SDL_Renderer*, const std::string&);
	static void deallocate_textures();

  static std::vector<SDL_Color>	
	get_border_pixels(const std::string&, const SDL_Rect&);
private:
	static SDL_Color get_pixel_color(SDL_Surface* surface, int x, int y);

	static std::unordered_map<std::string, SDL_Texture*> _textures;
	static std::unordered_map<std::string, SDL_Surface*> _surfaces;
};

#endif
