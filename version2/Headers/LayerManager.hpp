#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H


class LayerManager {
public:
    LayerManager(const int);
    void add_layer(const LayerFactory::LayerType&);
    void operator++(int); //postfix
    void operator++();    //prefix
    void operator--(int)  //postfix
    void operator--();    //prefix
    Texture* get_selected_texture();


private:
    Texture* get_texture_at_current_mouse_pos();
    std::map<LayerFactory::LayerType, Layer*> mLayers;
		LayerFactory::LayerType currentLayerType_;
    int width_;

};
#endif
