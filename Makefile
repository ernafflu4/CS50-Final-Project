# A simple Makefile for compiling small SDL projects

# set the compiler
CC := clang++

# set the compiler flags
CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 --std=libstdc++ -Wall -lSDL2_image -lSDL2_ttf -lm 

# add header files here
HDRS := CText.h CPlayer.h CEntity.h CFPS.h CAnimation.h CCamera.h CTile.h CMap.h CTexture.h CEvent.h CGame.h 

# add source files here
SRCS := CGame.cpp CText.cpp CTile.cpp CMap.cpp CPlayer.cpp CEntity.cpp CEntitycol.cpp CFPS.cpp CAnimation.cpp CCamera.cpp CTexture.cpp CEvent.cpp C_Initialize.cpp C_Event.cpp C_Loop.cpp C_Render.cpp C_Cleanup.cpp

# generate names of object files
OBJS := $(SRCS:.cpp=.o)

# name of executable
EXEC := game

# default recipe
all: $(EXEC)

# recipe for building the final executable
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# recipe for building object files
#$(OBJS): $(@:.o=.cpp) $(HDRS) Makefile
#	$(CC) -o $@ $(@:.o=.cpp) -c $(CFLAGS)

# recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
