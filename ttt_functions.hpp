#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>

void introduction();
void take_turn(char& current_player, std::vector<char>& grid);
bool check_valid_turn(char chosen_position, const std::vector<char>& grid);
void update_grid(char chosen_position, char current_player, std::vector<char>& grid);
void change_player(char& current_player);
bool is_winner(char player, const std::vector<char>& grid);
bool filled_up(const std::vector<char>& grid);
bool end_game(bool is_winner, bool filled_up, char current_player);

#endif // FUNCTIONS_HPP

