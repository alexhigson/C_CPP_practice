#include "ttt_functions.hpp"
#include <iostream> 
#include <vector> 

int main() {

    std::vector<char> grid = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    char current_player = 'X';

    int turns_played = 0;

    introduction();

    while (turns_played <= 9) {

        take_turn(current_player, grid);
        bool winner_status = is_winner(current_player, grid);
        bool is_filled = filled_up(grid);
        bool end_now = end_game(winner_status, is_filled, current_player);
        if (end_now) {
            return 0;
        } else {
            change_player(current_player);
        }

        turns_played++;

    }

    return 0;

}
 