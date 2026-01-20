#include <iostream>

template <typename Base, typename Derived>
class TextureCloneable: virtual public Base {
public:
	using Base::Base;
	virtual Base* clone() const {
		return new Derived(static_cast<Derived const&>(*this));
	}
};


class Texture {
public:
	Texture() {
		vTexture = 20;
	}
	Texture(const int v) : vTexture(v) {}
	Texture(const Texture& other) : vTexture(other.vTexture) {}
	int vTexture;
};


class SimpleTexture : public Texture {
public:
	SimpleTexture() {}
	SimpleTexture(const int v) : Texture(v) {}
	SimpleTexture(const SimpleTexture& other) : Texture(other) {}
};


class DeclinedTexture : public TextureCloneable<SimpleTexture, DeclinedTexture> {
public:
	DeclinedTexture() {}
	DeclinedTexture(const int v) : SimpleTexture(v) {}
  DeclinedTexture(const DeclinedTexture& other) : SimpleTexture(other) {}
};


int main() {
	DeclinedTexture* declinedTexture = new DeclinedTexture(10);
	Texture* clone = declinedTexture->clone();
	std::cout << clone->vTexture << std::endl;	
	return 0;
}
