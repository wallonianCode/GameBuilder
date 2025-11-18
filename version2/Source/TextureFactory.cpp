#include "../Headers/TextureFactory.cpp"


//TODO complete this blueprint

SimpleTexture* 
TextureFactory::createSimpleTexture(const SDL_Point& pos,
																		const TextureEnum& textureKind)
{
	SimpleTexture* newTexture = nullptr;

	switch (textureKind) {
		case SimpleTextureEnum::Sand:
		{
			newTexture = new Sand(pos);
			break;
		}
		default:
			break;
	}
	return newTexture;
}


CompositeTexture*
TextureFactory::createCompositeTexture(const SDL_Point& pos,
																			 const CompositeTextureEnum& 
																			 compositeTextureKind) {
	CompositeTexture* newTexture = nullptr;

	switch (compositeTextureKind) {
		case CompositeTextureEnum::Oak:
		{
		  newTexture = new Oak(pos);	
			break;
		}
		default:
			break;
	}	
	return newTexture;
}


DeclinedTexture*
TextureFactory::createDeclinedTexture(const SDL_Point& pos,
																			const DeclinedTextureEnum& 
																			declinedTextureEnum,
																			const DeclinedTextureOrientation&
																			orientation) {
	DeclinedTexture* newTexture = nullptr;
	switch (declinedTextureEnum) {
		case DeclinedTextureEnum::RockRoad: {
			newTexture = new RockRoad(pos, orientation);
			break;
		}
		default:
			break;
	}
	return newTexture;
};
