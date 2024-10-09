#include <iostream>
#include <vector>
#include <string>

template <typename Collection>
concept has_c_str = requires (Collection col) {
  col.c_str();
};

void check(has_c_str auto & col) {
  std::cout << "c_str() is available." << std::endl;
}

void check(auto & col) {
  std::cout << "No access to c_str()." << std::endl;
}


int main() {
    std::vector<int> vi{1, 2, 9};
    std::cout << "vector<int>: ";
    check(vi);
    
    std::string str("Concept");
    std::cout << "string: ";
    check(str);
    return 0;
}
