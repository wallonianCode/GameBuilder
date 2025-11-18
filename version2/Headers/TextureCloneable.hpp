#ifndef TEXTURECLONEABLE
#define TEXTURECLONEABLE

#include "Texture.hpp"

template <typename Base, typename Derived>
class TextureCloneable : virtual public Base {
public:
	virtual Texture* clone() const override {
		return new Derived(static_cast<Derived const&>(*this));
	}
};


#endif
