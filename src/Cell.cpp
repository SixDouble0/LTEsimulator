#include "include/Cell.hpp"
#include "include/Utilis.hpp"

Cell::Cell(int pos_x, int pos_y, int cell_id, int radius, const std::vector<std::vector<int>>& grid)
    : x(pos_x), y(pos_y), id(cell_id), r(radius)
{
    List = FindNearestUserBFS(grid, x, y, r);
}

const std::vector<int>& Cell::GetUserList() const {
    return List;
}

int Cell::getId() const {
    return id;
}
