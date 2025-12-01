#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H

#include <map>
#include "LayerFactory.hpp"


class LayerManager : public Drawable {
public:
    LayerManager(const int, const SDL_FPoint&);
    void add_layer(const LayerFactory::LayerType&);
    void operator++(int); //postfix
    void operator++();    //prefix
    void operator--(int);  //postfix
    void operator--();    //prefix
    Texture* get_texture_copy_at_coord(const SDL_FPoint&);
		void draw() override;	

private:
    Texture* get_texture_at_current_mouse_pos();
    std::map<LayerFactory::LayerType, Layer*> mLayers_;
		LayerFactory::LayerType currentLayerType_;
    int width_;
    SDL_Point upperLeftCorner_;

};
#endif
