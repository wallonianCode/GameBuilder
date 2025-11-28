#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include "TextureCloneable.hpp"
#include "DeclinedTexture.hpp"

class Character : public TextureCloneable<DeclinedTexture, Character> {

};
/*
enum class Direction {North, South, East, West};


struct Constants {
	static const int X_BASE = 9;
	// height at which the sprites begin on the npcLeafGreen tileset
	static const int Y_BASE = 43;
	// vertical jump between two lines on the npcLeafGreen tileset
	static const int Y = 25;
	static const int Y_SMALL = 16;
	static const int Y_BIG = 40;
	// width of the average character on sprite sheet
	static const int WIDTH = 15;
	// height of the average character on sprite sheet
	static const int HEIGHT = 23;
};



class Character : public TextureCloneable<Texture, Character> {
public:
	// describes the character's shape
	class Side {
	public:
		enum class Shape {FrontLeftFoot, Front, FrontRightFoot, 
		BackRightFoot, Back, BackLeftFoot, LeftSideRightFoot, 
		Left, LeftSideLeftFoot, RightSideRightFoot, Right, 
		RightSideLeftFoot};

		void rotate(const Direction& dir, Character*);
		void move(const Direction& dir, Character*); // switch leg position
		// get the direction as a function of the side
		Direction get_dir();

		void save(std::ostream& os);
		Side(const Character::Side::Shape&);
	private:
		int to_int();
		std::string to_str(const Shape&);
		// update src rectangle according to current shape_
		void update_src(Character*);

		Shape shape_;
		Shape precedentFoot_;
	};

	// defines the character's type
	class Name {
	public:
		enum class Type {Red, Flora, Blue, Chen, Mama};
		Name(const Type&, Character*);
		static Name::Type to_name_type(const std::string&);
		void save(std::ostream& os) const;
	private:
		void init_src(Character*);
		std::string to_str() const;
		Type type_;
	};

	// change direction without moving
	void rotate(const Direction&);
	// change direction & carry a displacement
	void move(const Direction&);
	// carry a displacement alongside a pre-defined pattern
	void move_along_pattern();
	// move along pattern in the other direction
	void move_along_reversed_pattern();
	// move along a pattern and then invert it
	void move_back_and_forth_along_pattern();
	// define a pattern for future displacements
	void set_pattern(std::vector<Direction>::iterator,
	std::vector<Direction>::iterator);

	void update() override;
	void save(std::ostream& os) const override;

	Character(const SDL_Point& posOnScreen, const Character::Name::Type&, 
	const std::string& tileset = "npcLeafGreen.png");
	
	Character(const SDL_Point&, const std::string&);
private:		
	// for class compliance; functionality is overtaken by nested class

	// set the front src tile
	void init_src(const Character::Name::Type&);
	// update the src rect as a function of the current side	
	void update_src();
	// move the sprite without changing the src
	void increment_position(const Direction& dir);

	Character::Side side_ = Character::Side(Character::Side::Shape::Front);
	Character::Name name_ = Character::Name(Character::Name::Type::Red, 
	this);
	int speed_;

	bool isPatternReversed;
	unsigned patternIndex_ = 0;
	std::vector<Direction> pattern_; 
};
*/
#endif
