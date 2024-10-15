#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


struct Player {
    std::string name;
    int number;
    std::string position;
    Player(std::string nn, int no, std::string pos): 
      name(nn), number(no), position(pos) {}
};

int main() {
    std::vector<Player> manutd{
        Player("McGuire", 5, "defender")
        , Player("Dalot", 20, "defender")
        , Player("Shaw", 23, "defender")
        , Player("Onana", 24, "goalie")
        , Player("Evans", 35, "defender")
    };

    // c++ 11 
    /* std::partition( */
    /*     manutd.begin(), manutd.end(), */ 
    /*     [](const Player & p){ */
    /*       return p.position == "goalie"; */
    /*     } */
    /* ); */

    // c++ 20 
    auto const pos = 
      std::ranges::stable_partition(
          manutd, 
          [] (const Player & p) {
            return p.position == "goalie";
          } 
      );

    std::cout << "United by position:\n";
    for ( const auto & player: manutd ) {
      std::cout << player.position << ": [" << player.number << "] "
        << player.name << "\n";
    }

    return 0;
}
