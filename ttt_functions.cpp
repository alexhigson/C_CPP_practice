#include "ttt_functions.hpp"
#include <iostream> 
#include <vector> 

void introduction() {

        std::cout << "\nWelcome to tic-tac-toe! Player X will go first, followed by Player O.\n";

    }

void take_turn(char& current_player, std::vector<char>& grid) {

    char chosen_position;
    bool valid_turn = false;

    while (!valid_turn) {

        std::cout << "\nPlayer " << current_player << ", it's your turn. Place your " << current_player << " on the grid in the position of your choice:\n";
        std::cout << grid[0] << "   " << grid[1] << "   " << grid[2] << "\n";
        std::cout << grid[3] << "   " << grid[4] << "   " << grid[5] << "\n";
        std::cout << grid[6] << "   " << grid[7] << "   " << grid[8] << "\n";

        std::cout << "Enter position: \n";
        std::cin >> chosen_position;

        valid_turn = check_valid_turn(chosen_position, grid);

        if (valid_turn) {

            update_grid(chosen_position, current_player, grid);

        } else {

            std::cout << "\nThis position is already taken. Please choose another.\n";

        }

    }

}

bool check_valid_turn(char chosen_position, const std::vector<char>& grid) {

        int pos = chosen_position - '1';
        if (pos >= 0 && pos < grid.size() && grid[pos] != 'O' && grid[pos] != 'X') {
            return true;
        }
        return false; 
        
}

void update_grid(char chosen_position, char current_player, std::vector<char>& grid) {

    int pos = chosen_position - '1';
    grid[pos] = current_player;

}

void change_player(char& current_player) {
    current_player = (current_player == 'X') ? 'O' : 'X';
}

bool is_winner(char player, const std::vector<char>& grid) {
    return ((grid[0] == player && grid[1] == player && grid[2] == player) || 
            (grid[3] == player && grid[4] == player && grid[5] == player) || 
            (grid[6] == player && grid[7] == player && grid[8] == player) || 
            (grid[0] == player && grid[3] == player && grid[6] == player) || 
            (grid[1] == player && grid[4] == player && grid[7] == player) || 
            (grid[2] == player && grid[5] == player && grid[8] == player) || 
            (grid[0] == player && grid[4] == player && grid[8] == player) || 
            (grid[2] == player && grid[4] == player && grid[6] == player));
}

bool filled_up(const std::vector<char>& grid) {

    for (int i = 0; i < grid.size(); i++) {
        if (grid[i] != 'X' && grid[i] != 'O') {
            return false;
        }
    }
    return true;

}

bool end_game(bool is_winner, bool filled_up, char current_player) {

    if (is_winner) {

        std::cout << current_player << " is the winner! Thank you for playing.\n";
        return true;

    } else if (filled_up) {

        std::cout << "\nNobody won this time. Thank you for playing.\n";
        return true;

    } else {

        return false;

    }

}