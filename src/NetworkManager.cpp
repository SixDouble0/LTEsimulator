#include "include/NetworkManager.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>

NetworkManager* NetworkManager::instance = nullptr;

void NetworkManager::Init(int height, int width) {
    if (!instance) {
        instance = new NetworkManager(height, width);
    }
}

NetworkManager& NetworkManager::Get() {
    if (!instance) {
        std::cerr << "NetworkManager not initialized." << std::endl;
        std::exit(1);
    }
    return *instance;
}

NetworkManager::NetworkManager(int height, int width)
    : grid_height(height), grid_width(width), grid(height, std::vector<int>(width, 0)) {
}

void NetworkManager::PlaceUser(int pos_x, int pos_y, int userId) {
    if (pos_x < 0 || pos_x >= grid_height || pos_y < 0 || pos_y >= grid_width || grid[pos_x][pos_y] != 0) {
        std::cerr << "User position out of bounds or is occupied." << std::endl;
        return;
    }
    grid[pos_x][pos_y] = userId;
}

void NetworkManager::AddUser(int pos_x, int pos_y, int userId) {
    users.emplace_back(pos_x, pos_y, userId);
    PlaceUser(pos_x, pos_y, userId);
}

void NetworkManager::PlaceCell(int pos_x, int pos_y, int cellId, int radius) {
    if (pos_x < 0 || pos_x >= grid_height || pos_y < 0 || pos_y >= grid_width || grid[pos_x][pos_y] != 0) {
        std::cerr << "Cell position out of bounds or is occupied." << std::endl;
        return;
    }
    grid[pos_x][pos_y] = cellId;
    cells.emplace_back(pos_x, pos_y, cellId, radius, grid);
}

void NetworkManager::ShowGrid() {
    for (int i = 0; i < grid_height; ++i) {
        for (int j = 0; j < grid_width; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

const std::vector<Cell>& NetworkManager::GetCells() const {
    return cells;
}

std::vector<User>& NetworkManager::GetUsers() {
    return users;
}

int NetworkManager::FindClosestCell(int x, int y) {
    int minDist = INT_MAX;
    int closestId = -1;
    for (const auto& cell : cells) {
        int dist = static_cast<int>(std::pow(cell.getX() - x, 2) + std::pow(cell.getY() - y, 2));
        if (dist < minDist) {
            minDist = dist;
            closestId = cell.getId();
        }
    }
    return closestId;
}

void NetworkManager::HandleHandover(User& user) {
    int closestCellId = FindClosestCell(user.getX(), user.getY());
    if (user.getConnectedCellId() != closestCellId) {
        RemoveUserFromCell(user.getId(), user.getConnectedCellId());
        AddUserToCell(user.getId(), closestCellId);
        user.setConnectedCellId(closestCellId);
    }
}

void NetworkManager::RemoveUserFromCell(int userId, int cellId) {
    for (auto& cell : cells) {
        if (cell.getId() == cellId) {
            cell.RemoveUser(userId);
        }
    }
}

void NetworkManager::AddUserToCell(int userId, int cellId) {
    for (auto& cell : cells) {
        if (cell.getId() == cellId) {
            cell.AddUser(userId);
        }
    }
}

const User* NetworkManager::GetUserById(int userId) const {
    for (const auto& user : users) {
        if (user.getId() == userId) {
            return &user;
        }
    }
    return nullptr; // Zwróæ nullptr, jeœli u¿ytkownik o podanym ID nie istnieje
}
