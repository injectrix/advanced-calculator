CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

SRC = src/main.cpp src/Parser.cpp src/RPN.cpp src/Context.cpp src/History.cpp

all:
	$(CXX) $(SRC) $(CXXFLAGS) -o calc
