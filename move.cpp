#include <iostream>
#include <string>
#include <utility>
#include <vector>

class C {
private:
  std::string _first;
  std::string _last;
  int _id;

public:
  C(std::string first, std::string last, int id)
      : _first(first), _last(last), _id(id) {}
  friend std::ostream & operator << (std::ostream & os, const C & c) {
    os << "[" << c._first << " " << c._last << " " << c._id << "]"; 
    return os;
  }
};


void foo(const C& c) {
  std::cout << "Calling read-only foo(const C&) on " << c << ".\n";
}

void foo(C& c) {
  std::cout << "Calling full-access foo(C&) on " << c << ".\n";
}

void foo(C&& c) {
  std::cout << "Calling move foo(C&&) on " << c << ".\n";
}


// universal reference
// aka
// forwarding reference
template <typename T> void callFoo(T &&c) 
{ 
  std::cout << "Forwarding to foo\n";
  foo(std::forward<T>(c));
}

int main() {
  std::string s("Hello move semantics");
  std::vector<std::string> vec;
  vec.push_back(std::move(s));
  std::cout << "String was moved.\n"
            << "It must be in a valid state but it does not need to be empty.\n"
            << "Although this is most likely. Let's see.\n";
  std::cout << "String size after move: " << s.size() << ".\n";
  std::cout << "String content after move: '" << s << "'.\n";

  std::cout << "\n\n";
  C paweł("Paweł", "Wójcik", 5);
  const C cr7("Cristiano", "Ronaldo", 7);
  callFoo(paweł);
  callFoo(cr7);
  callFoo(std::move(paweł));


  return 0;
}
