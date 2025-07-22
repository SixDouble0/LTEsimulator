#include "include/User.hpp"

User::User(int pos_x, int pos_y, int user_id)
    : x(pos_x), y(pos_y), id(user_id), connectedCellId(-1) {
}

int User::getId() const { return id; }
int User::getX() const { return x; }
int User::getY() const { return y; }
int User::getConnectedCellId() const { return connectedCellId; }
void User::setConnectedCellId(int cellId) { connectedCellId = cellId; }

void User::move(int dx, int dy) {
    x += dx;
    y += dy;
}
