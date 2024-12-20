#include <iostream>
#include <string>

struct Nothing {
  int integer;
  int *pointer;
  std::string string;
};

std::ostream &operator<<(std::ostream &os, const Nothing &nothing) {
  os << "  Integer: '" << nothing.integer << "'\n";
  os << "  Pointer: '" << nothing.pointer << "'\n";
  os << "  string: '" << nothing.string << "'\n";
  return os;
}

struct ConstructedNothing {
  int integer;
  int *pointer;
  std::string string;
  ConstructedNothing() {};
};

std::ostream &operator<<(std::ostream &os, const ConstructedNothing &cnothing) {
  os << "  Integer: '" << cnothing.integer << "'\n";
  os << "  Pointer: '" << cnothing.pointer << "'\n";
  os << "  string: '" << cnothing.string << "'\n";
  return os;
}

int main() {
  Nothing default_init;
  std::cout << "Default-initilized object.\n";
  std::cout << default_init;

  Nothing value_init{};
  std::cout << "Value-initilized object.\n";
  std::cout << value_init;

  ConstructedNothing value_init_cn{};
  std::cout << "Value-initilized object (class with an empty constructor).\n";
  std::cout << value_init_cn;

  return 0;
}
