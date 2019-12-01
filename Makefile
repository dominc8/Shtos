CXX := g++
CXX_FLAGS := -Wfatal-errors -Wall -Wextra -Wpedantic -Wconversion -Wshadow -DDEBUG

BUILD_DIR := ./build
INCLUDE_DIRS := Shtos/
LIBS :=
SOURCES := $(wildcard Shtos/**/*.cpp)

### DemoApplication specific settings ###

INCLUDE_DIRS += Demo/
SOURCES += $(wildcard Demo/*.cpp)
BIN = DemoApplication

#########################################

OBJ := $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)
DEP := $(OBJ:%.o=%.d)

ifeq ($(OS),Windows_NT)
    CXX_FLAGS += -DWINDOWS
    INCLUDE_DIRS += SDL/include/
    LIBS += SDL/lib/win64/SDL2.lib SDL/lib/win64/SDL2.dll SDL/lib/win64/SDL2main.lib SDL/lib/win64/SDL2_mixer.dll SDL/lib/win64/SDL2_image.dll SDL/lib/win64/libjpeg-9.dll SDL/lib/win64/zlib1.dll SDL/lib/win64/libpng16-16.dll SDL/lib/win64/libmpg123-0.dll 
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CXX_FLAGS += -DLINUX
	LD_FLAGS += -lSDL2 -lSDL2_image -lSDL2_mixer
    endif
endif

CXX_FLAGS += $(addprefix -I,$(INCLUDE_DIRS))

$(BIN) : $(BUILD_DIR)/$(BIN)

$(BUILD_DIR)/$(BIN) : $(OBJ)
	mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) $^ $(LIBS) -o $@ $(LD_FLAGS)

-include $(DEP)

$(BUILD_DIR)/%.o : %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) -MMD -c $< -o $@

.PHONY : clean run

clean :
	rm -rf $(BUILD_DIR)

run :
	./$(BUILD_DIR)/$(BIN)

