#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H

#include "Layer.hpp"


class LayerManager : public Drawable {
public:
    LayerManager(const int, const SDL_Point&);
    void add_layer(const LayerFactory::LayerType&);
    void operator++(int); //postfix
    void operator++();    //prefix
    void operator--(int)  //postfix
    void operator--();    //prefix
    Texture* get_texture_copy_at_coord(const SDL_Point&);
		void draw() override;	

private:
    Texture* get_texture_at_current_mouse_pos();
    std::map<LayerFactory::LayerType, Layer*> mLayers_;
		LayerFactory::LayerType currentLayerType_;
    int width_;

};
#endif
