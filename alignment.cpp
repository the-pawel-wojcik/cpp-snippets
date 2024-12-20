#include <iostream>

struct BFB {
  bool b0;
  float f;
  bool b1;
};

struct FBB {
  float f;
  bool b0;
  bool b1;
};

struct BDB {
  bool b0;
  double d;
  bool b1;
};

struct DBB {
  double d;
  bool b0;
  bool b1;
};

int main() {
  std::cout << "Size of BFB: " << sizeof(BFB) << std::endl;
  std::cout << "Size of FBB: " << sizeof(FBB) << std::endl;
  std::cout << "Size of BDB: " << sizeof(BDB) << std::endl;
  std::cout << "Size of DBB: " << sizeof(DBB) << std::endl;
  return 0; 
}
