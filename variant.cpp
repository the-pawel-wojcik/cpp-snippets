#include <iostream>
#include <string>
#include <variant>
#include <vector>

class Goalie {
  std::string _name;
  int _number;

public:
  Goalie(const std::string &name, int number) : _number(number), _name(name) {}
  friend std::ostream &operator<<(std::ostream &os, const Goalie &goalie) {
    os << "[" << goalie._number << ": " << goalie._name << "]";
    return os;
  }
};

class Striker {
  std::string _name;
  int _number;

public:
  Striker(const std::string &name, int number) : _number(number), _name(name) {}
  friend std::ostream &operator<<(std::ostream &os, const Striker &striker) {
    os << "[" << striker._number << ": " << striker._name << "]";
    return os;
  }
};

void print(Striker striker) { std::cout << striker << std::endl; }

void print(Goalie goalie) { std::cout << goalie << std::endl; }

int main() {
  using player = std::variant<Goalie, Striker>;
  std::vector<player> manutd = {Striker("Garnacho", 7), Goalie("Onana", 24)};
  for (auto &baller : manutd) {
    std::visit([](auto &&arg) { print(arg); }, baller);
  }
  // The above is equivalent to this longer version
  for (auto &baller : manutd) {
    if (std::holds_alternative<Goalie>(baller)) {
      Goalie arg = std::get<Goalie>(baller);
      print(arg);
    } else if (std::holds_alternative<Striker>(baller)) {
      Striker arg = std::get<Striker>(baller);
      print(arg);
    }
  }
  return 0;
}
