#ifndef LAYERFACTORY_H
#define LAYERFACTORY_H

class LayerFactory {
public:
    enum class LayerType {Roads, Trees, Soil, Buildings};
    static Layer* create_layer(const LayerFactory::LayerType&);
		LayerType operator++(const LayerType&, int); //postfix
		LayerType operator++(const LayerType&);
		LayerType operator--(const LayerType&, int);
		LayerType operator--(const LayerType&);
};

#endif
