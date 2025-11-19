OBJS = Source/Window.cpp Source/Renderer.cpp Source/GameState.cpp Source/GameStateMachine.cpp Source/GameManager.cpp Source/Drawable.cpp Source/Texture.cpp Source/Border.cpp Source/GreenBorder.cpp Source/GreyBorder.cpp Source/Bush.cpp Source/TextureCreator.cpp Source/TextureLoader.cpp Source/Background.cpp Source/Layer.cpp Source/Map.cpp Source/BigLand.cpp Source/BigLandName.cpp Source/BigLandLayer.cpp Source/BuilderButton.cpp Source/BuilderMap.cpp Source/BuilderState.cpp Source/Button.cpp Source/Character.cpp Source/CharacterLayer.cpp Source/CharacterName.cpp Source/CharacterSide.cpp Source/Collider.cpp Source/Color.cpp Source/DeepWater.cpp Source/ExitButton.cpp Source/ExiterState.cpp Source/FontLoader.cpp Source/Frame.cpp Source/GameMenu.cpp Source/GameMenuState.cpp Source/Grass.cpp Source/GreenBackground.cpp Source/LandLayer.cpp Source/MenuButton.cpp Source/MoosRoad.cpp Source/Moos.cpp Source/PlayerButton.cpp Source/Player.cpp Source/PlayerMap.cpp Source/PlayerState.cpp Source/Rectangle.cpp Source/Red.cpp Source/RockRoad.cpp Source/Rock.cpp Source/Sand.cpp Source/SandRoad.cpp Source/SaveButton.cpp Source/Selector.cpp Source/Separator.cpp Source/ShallowWater.cpp Source/TextButton.cpp Source/Text.cpp Source/ThreeColumnsBackground.cpp Source/TexturePositionComparator.cpp Source/TallGrass.cpp Source/SmallTree.cpp Source/Flowers.cpp Source/TextureCloneable.cpp Source/main.cpp 
CC = g++
COMPILER_FLAGS = -Wall
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = exe

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
