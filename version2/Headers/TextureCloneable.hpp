#ifndef TEXTURECLONEABLE
#define TEXTURECLONEABLE


template <typename Base, typename Derived>
class TextureCloneable : virtual public Base {
public:
	using Base::Base;
	virtual Base* clone() const {
		return new Derived(static_cast<Derived const&>(*this));
	}
};


#endif
