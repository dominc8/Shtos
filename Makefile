CC:=g++
CCFLAGS:=-DDEBUG

INCLUDE_DIRS:=Shtos/
LIBS:=
SOURCES = $(wildcard Shtos/**/*.cpp)

ifeq ($(OS),Windows_NT)
	CCFLAGS+=-DWINDOWS
	INCLUDE_DIRS+=SDL/include/
	LIBS+=SDL/lib/win64/SDL2.lib SDL/lib/win64/SDL2.dll SDL/lib/win64/SDL2main.lib
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CCFLAGS+=-DLINUX
		LDFLAGS+=-lSDL2
    endif
endif

CCFLAGS+=$(addprefix -I,$(INCLUDE_DIRS))

demo:
	$(CC) $(CCFLAGS) -IDemo/ $(SOURCES) Demo/DemoLayer.cpp Demo/DemoApplication.cpp $(LIBS) -o DemoApplication $(LDFLAGS) 
