#include "../include/user_solver.h"

#include <mach/task_special_ports.h>
#include <iostream>
using namespace std;

void UserSolver::solve(Board &board) {

    size_t start_line = 0;

    //To avoid duplicates when searching adjacently
    vector<pair<size_t, size_t>> ship_positions; //(x, y) pair

    //Prevents undefined behavior
    ship_positions.emplace_back(board.getX() + 1, board.getY() + 1);

    for (size_t y = 0; y < board.getY(); y++ ) {

        for (size_t x = start_line; x < board.getX(); x += 3) {

            ReturnType guess_type = guess(x, y, board);

            if (guess_type == hit) {
                ship_positions.emplace_back(x, y);
            }

            if (guess_type == near_miss) {
                if (guess(x + 1, y, board) == hit &&
                    make_pair(x + 1, y) != ship_positions.back()) {
                    ship_positions.emplace_back(x + 1, y);
                    }
                if (guess(x - 1, y, board) == hit &&
                    make_pair(x - 1, y) != ship_positions.back()) {
                    ship_positions.emplace_back(x - 1, y);
                    }
                if (guess(x, y + 1, board) == hit &&
                    make_pair(x, y + 1) != ship_positions.back()) {
                    ship_positions.emplace_back(x, y + 1);
                    }
                if (guess(x, y - 1, board) == hit &&
                    make_pair(x, y - 1) != ship_positions.back()) {
                    ship_positions.emplace_back(x, y - 1);
                    }
            }
            }

        //searches grid in alternating diagonal pattern, skipping every 2
        if (start_line < 2) {
            start_line += 1;
        }
        else {
            start_line = 0;
        }

        if (ship_positions.size() - 1 == board.getShipCount()) {
            break;
        }
    }
}






