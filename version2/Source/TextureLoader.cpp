#include "../Headers/TextureLoader.hpp"

std::unordered_map<std::string, SDL_Texture*> TextureLoader::_textures;
std::unordered_map<std::string, SDL_Surface*> TextureLoader::_surfaces;

SDL_Texture* TextureLoader::load_texture(SDL_Renderer* renderer, 
const std::string& filename) {
	SDL_Texture* texture;
	if (! renderer) throw std::runtime_error("TL::load_texture:\
	renderer is null");
	if (filename.empty())	{
		throw std::runtime_error("TL::load_texture: filename is empty");
	}
	std::unordered_map<std::string, SDL_Texture*>::iterator found = 
	_textures.find(filename);
	if (found != _textures.end()) texture = found->second;
	else {
	  std::string filepath = tileSheetsPath + "/" + filename + ".png";
		SDL_Surface* image = IMG_Load(filepath.c_str());
		// make background transparent
		SDL_Color transparentColor = filename == "npcLeafGreen" ?
		get_pixel_color(image, 12, 43) : get_pixel_color(image, 0, 0);
		std::cout << filename << std::endl;
    std::printf("Color: %d, %d, %d\n", transparentColor.r,
		transparentColor.g, transparentColor.b);
	
		SDL_SetSurfaceColorKey(image, true, SDL_MapSurfaceRGB(
		image, transparentColor.r, transparentColor.g, 
		transparentColor.b)); 
   
		//SDL_SetSurfaceBlendMode(image, SDL_BLENDMODE_BLEND);
		if (! image) throw std::runtime_error("TL::load_texture:\
		surface not loaded");
		texture = SDL_CreateTextureFromSurface(renderer, image);
		if (! texture) { 
			throw std::runtime_error("TL::load_texture: texture not loaded");
	  }
		//SDL_FreeSurface(image);
		_surfaces[filename] = image;
		_textures[filename] = texture;
	}
	return texture;
}


void TextureLoader::deallocate_textures() {
	std::unordered_map<std::string, SDL_Texture*>::iterator texturesIt = 
	_textures.begin();
	while (texturesIt != _textures.end()) {
		SDL_DestroyTexture(texturesIt->second);
		texturesIt = _textures.erase(texturesIt);
	}

	std::unordered_map<std::string, SDL_Surface*>::iterator surfacesIt = 
	_surfaces.begin();
	while (surfacesIt != _surfaces.end()) {
		SDL_DestroySurface(surfacesIt->second);
		surfacesIt = _surfaces.erase(surfacesIt);
	}
}


SDL_Color TextureLoader::get_pixel_color(SDL_Surface* surface, 
int x, int y) {
    uint8_t* pixel;
	uint8_t red, green, blue;
    const SDL_PixelFormatDetails* pixelDetails = SDL_GetPixelFormatDetails(surface->format);
	const Uint8 bpp = SDL_BYTESPERPIXEL(surface->format);

	pixel = static_cast<uint8_t*>(surface->pixels) + 
									y * surface->pitch +
									x * bpp;

	SDL_GetRGB(*reinterpret_cast<uint32_t*>(pixel), pixelDetails, NULL, &red, &green, &blue);
	return { red, green, blue };
}


/*
std::vector<SDL_Color> 
TextureLoader::get_border_pixels(const std::string& sName, const SDL_Rect& src) {
	std::vector<SDL_Color> pixels;
	SDL_Surface* surface = _surfaces.at(sName);
	int i;
	for (i = 0; i < src.w; i++) {
		pixels.push_back(get_pixel_color(surface, src.x + i, src.y));	
	}
	for (i = 0; i < src.h; i++) {
		pixels.push_back(get_pixel_color(surface, src.x + src.w, src.y + i));
	}
	for (i = src.w; i > 0; i--) {
		pixels.push_back(get_pixel_color(surface, src.x + i, src.y + src.h));
	}
	for (i = src.h; i > 0; i--) {
		pixels.push_back(get_pixel_color(surface, src.x, src.y + i));
	}
	return pixels;
}
	*/
