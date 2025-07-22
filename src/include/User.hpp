#pragma once

class User {
public:
    User(int pos_x, int pos_y, int user_id);

    int getId() const;
    int getX() const;
    int getY() const;
    int getConnectedCellId() const;
    void setConnectedCellId(int cellId);

    void move(int dx, int dy);

private:
    int x, y;
    int id;
    int connectedCellId;
};
