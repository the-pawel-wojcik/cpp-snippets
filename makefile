CXX_STD = --std=c++11
# CXX_STD = --std=c++14
# CXX_STD = --std=c++20
CXX_FLAGS = $(CXX_STD) -Wall -Wextra -Wpedantic

smart: smart.cpp
	g++ $(CXX_FLAGS) $^ -o $@ 
	./$@

move: move.cpp
	g++ $(CXX_FLAGS) $^ -o $@ 
	./$@
