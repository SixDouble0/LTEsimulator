#include "include/Cell.hpp"
#include <algorithm>

Cell::Cell(int pos_x, int pos_y, int cell_id, int radius, const std::vector<std::vector<int>>& grid)
    : x(pos_x), y(pos_y), id(cell_id), r(radius) {
}

const std::vector<int>& Cell::GetUserList() const {
    return List;
}

int Cell::getId() const {
    return id;
}

int Cell::getX() const {
    return x;
}

int Cell::getY() const {
    return y;
}

int Cell::getRadius() const {
    return r;
}

void Cell::AddUser(int userId) {
    List.push_back(userId);
}

void Cell::RemoveUser(int userId) {
    List.erase(std::remove(List.begin(), List.end(), userId), List.end());
}
