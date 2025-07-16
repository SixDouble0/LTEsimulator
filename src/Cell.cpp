#include "include/Cell.hpp"
#include "include/NetworkManager.hpp"

Cell::Cell(int pos_x, int pos_y, int cell_id, int radius)
    :x(pos_x), y(pos_y), id(cell_id), r(radius) {

    NetworkManager::Get().PlaceCell(pos_x, pos_y, cell_id, radius);

}
