CXX := g++
CXXFLAGS := -std=c++17 -Iinc -IC:/SDL/include/SDL2
LDFLAGS := -LC:/SDL/lib
LDLIBS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer

SRC := $(wildcard src/*.cpp)
OUT := game.exe

.PHONY: all run clean

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SRC) $(LDLIBS) -o $(OUT)

run: all
	./$(OUT)

clean:
	del /Q $(OUT) 2>nul || exit 0