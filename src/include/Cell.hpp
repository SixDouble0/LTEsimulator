#pragma once
#include <vector>

class Cell {
public:
    Cell(int pos_x, int pos_y, int cell_id, int radius, const std::vector<std::vector<int>>& grid);
    const std::vector<int>& GetUserList() const;
    int getId() const;
    int getX() const;
    int getY() const;
    int getRadius() const;

    // Dodaj publiczne metody do modyfikacji listy użytkowników
    void AddUser(int userId);
    void RemoveUser(int userId);

private:
    std::vector<int> List; // Lista użytkowników podłączonych do tej komórki
    int x, y, id, r;
};
