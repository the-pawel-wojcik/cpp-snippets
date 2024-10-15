# CXX_STD = --std=c++98
# CXX_STD = --std=c++11
# CXX_STD = --std=c++14
CXX_STD = --std=c++20
CXX_FLAGS = $(CXX_STD) -Wall -Wextra -Wpedantic

# Compile file to an executable and run it
%: %.cpp
	$(CXX) $(LDFLAGS) $(CPP_FLAGS) $(CXX_FLAGS) $(LOADLIBS) $(LDLIBS) $^ -o $@ 
	./$@
