CXX = g++
CXXFLAGS = -std=c++17 #-Wall

all: tictactoe

tictactoe: src/main.cpp #src/game.cpp
	$(CXX) $(CXXFLAGS) -o tictactoe src/main.cpp #src/game.cpp

clean:
	rm -f tictactoe
