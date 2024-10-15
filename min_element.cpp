#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


struct Player {
    std::string name;
    int born_y;
    Player(std::string nn, int yy): name(nn), born_y(yy){}
};


int main() {
    std::vector<Player> manutd{
        Player("Onana", 1996)
        , Player("Shaw", 1995)
        , Player("McGuire", 1993)
        , Player("Evans", 1988)
        , Player("Dalot", 1999)
    };

    auto const youngest = 
      std::ranges::max_element( manutd, {}, &Player::born_y );

    if (youngest != end(manutd)) {
      std::cout << "The youngest united player is: " << youngest->name << ".\n";
    }
    return 0;
}
