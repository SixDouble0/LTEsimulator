#pragma once

class User {
public:
    User(int pos_x, int pos_y, int user_id);

private:
    int x, y;
    int id;
    int connectedCellId;
};
