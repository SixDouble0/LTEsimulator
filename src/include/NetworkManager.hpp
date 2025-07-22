#pragma once
#include <vector>
#include "User.hpp"
#include "Cell.hpp"

class NetworkManager {
public:
    static void Init(int height, int width);
    static NetworkManager& Get();

    void PlaceUser(int pos_x, int pos_y, int userId);
    void AddUser(int pos_x, int pos_y, int userId);
    void PlaceCell(int pos_x, int pos_y, int cellId, int radius);
    void ShowGrid();

    const std::vector<Cell>& GetCells() const;
    std::vector<User>& GetUsers();
    const User* GetUserById(int userId) const;

    void HandleHandover(User& user);
    int FindClosestCell(int x, int y);

    void RemoveUserFromCell(int userId, int cellId);
    void AddUserToCell(int userId, int cellId);

private:
    NetworkManager(int height, int width);
    int grid_height, grid_width;
    std::vector<std::vector<int>> grid;
    std::vector<Cell> cells;
    std::vector<User> users;
    static NetworkManager* instance;
};
