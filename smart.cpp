#include <iostream>
#include <memory>

int main() {
  // Pointers to objects created with new
  // available since c++11
  std::unique_ptr<long> up_uc(new long);
  std::shared_ptr<unsigned char> sp_uc(new unsigned char);
  std::weak_ptr<unsigned char> wp_uc = sp_uc;

  // Pointer to objects created with new[]
  std::unique_ptr<int []> up_int_array(new int[100]);
  std::shared_ptr<double []> sp_double_array(new double[15]);
  std::weak_ptr<double []> wp_double_array = sp_double_array;

  // Helpers for creating smart pointers
  std::shared_ptr<float> sp_float = std::make_shared<float>();

  // available since c++14 
  std::unique_ptr<int> up_int = std::make_unique<int>();

  // Helpers for creater smart pointers with new[]
  std::unique_ptr<short []> uq_short_array = std::make_unique<short []>(10);

  // available since c++20
  std::shared_ptr<char[]> shared_char_array = std::make_shared<char[]>(10);

  *up_int = 8;
  std::cout << "Unique pointer points at: " << *up_int << ".\n";
  std::cout << "Shared counter: " << shared_char_array.use_count() << ".\n";
  return 0;
}
