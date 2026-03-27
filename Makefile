CXX := g++
SDL_DIR := C:/SDL2
CXXFLAGS := -std=c++17 -Iinc -I$(SDL_DIR)/include/SDL2
LDFLAGS := -L$(SDL_DIR)/lib
LDLIBS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer

SRC := $(wildcard src/*.cpp)
DIST := dist
OUT := $(DIST)/game.exe
OUT_WIN := $(subst /,\,$(OUT))

.PHONY: all run clean

all: $(OUT)

$(DIST):
	if not exist $(DIST) mkdir $(DIST)

$(OUT): $(SRC) | $(DIST)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SRC) $(LDLIBS) -o $(OUT)

run: all
	.\$(OUT)

clean:
	if exist "$(OUT_WIN)" del /Q "$(OUT_WIN)"