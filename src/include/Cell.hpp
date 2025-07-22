#pragma once
#include <vector>

class Cell {
public:
    Cell(int pos_x, int pos_y, int cell_id, int radius, const std::vector<std::vector<int>>& grid);
    const std::vector<int>& GetUserList() const;
    int getId() const;

private:
    std::vector<int> List; // List of users connected to this cell
    int x, y, id, r;
};
