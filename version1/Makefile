OBJS = Source/Trainer.cpp Source/Tile.cpp Source/TextureLoader.cpp Source/Collider.cpp Source/FontLoader.cpp Source/Menu.cpp Source/Build.cpp Source/Play.cpp Source/Exit.cpp Source/State.cpp Source/MenuState.cpp Source/ExitState.cpp Source/BuildState.cpp Source/PlayState.cpp Source/Color.cpp Source/FormDrawer.cpp Source/VideoPlayer.cpp Source/StateMachine.cpp Source/Game.cpp Source/main.cpp
CC = g++
COMPILER_FLAGS = -Wall
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = exe

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
