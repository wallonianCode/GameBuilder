#include "../Headers/TextureCreator.hpp"


Texture* TextureCreator::create_texture(const std::string& type,
const std::string& subType, const SDL_Rect& rectOnScreen) {
	Texture* texture = nullptr;
	if (type == "ShallowWater") 
		texture = 
		new ShallowWater({rectOnScreen.x, rectOnScreen.y}, subType);	
	else if (type == "DeepWater") 
		texture = new DeepWater({rectOnScreen.x, rectOnScreen.y}, subType);
	else if (type == "SandRoad") 
		texture = new SandRoad({rectOnScreen.x, rectOnScreen.y}, subType);
	else if (type == "MoosRoad")
		texture = new MoosRoad({rectOnScreen.x, rectOnScreen.y}, subType);
	else if (type == "RockRoad")
		texture = new RockRoad({rectOnScreen.x, rectOnScreen.y}, subType);
	else if (type == "Grass")
		texture = new Grass({rectOnScreen.x, rectOnScreen.y}, subType);
	else if (type == "Sand")
		texture = new Grass({rectOnScreen.x, rectOnScreen.y}, subType);
	else if (type == "Character")
		texture = new Character({rectOnScreen.x, rectOnScreen.y}, subType);
	else {
		std::cout << 
		"TextureCreator::create_texture: texture unknown... " << 
		type << std::endl;
	}
	return texture;
}
