#include "include/NetworkManager.hpp"
#include "include/Utilis.hpp"
#include <iostream>
#include <ctime>

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
    std::cout << "NetworkManager initialized with grid size: " << height << "x" << width << std::endl;
    ShowGrid();
}

void NetworkManager::PlaceUser(int pos_x, int pos_y, int userId) {
    if (pos_x < 0 || pos_x >= grid_height || pos_y < 0 || pos_y >= grid_width || grid[pos_x][pos_y] != 0) {
        std::cerr << "User position out of bounds or is occupied by cell or another user." << std::endl;
        return;
    }
    grid[pos_x][pos_y] = userId;
    std::cout << "Placed user with ID " << userId << " at position (" << pos_x << ", " << pos_y << ")." << std::endl;
}

void NetworkManager::AddUser(int pos_x, int pos_y, int userId) {
    users.emplace_back(pos_x, pos_y, userId);
    PlaceUser(pos_x, pos_y, userId);
}

const User* NetworkManager::GetUserById(int userId) const {
    for (const auto& user : users) {
        if (user.getId() == userId)
            return &user;
    }
    return nullptr;
}

void NetworkManager::PlaceCell(int pos_x, int pos_y, int cellId, int radius) {
    if (pos_x < 0 || pos_x >= grid_height || pos_y < 0 || pos_y >= grid_width || grid[pos_x][pos_y] != 0) {
        std::cerr << "Cell position out of bounds or is occupied by user or another cell" << std::endl;
        return;
    }
    grid[pos_x][pos_y] = cellId;
    std::cout << "Placed cell " << cellId << " at position (" << pos_x << ", " << pos_y << ")." << std::endl;
    cells.emplace_back(pos_x, pos_y, cellId, radius, grid);
}

void NetworkManager::ShowGrid() {
    for (int i = 0; i < grid_height; ++i) {
        for (int j = 0; j < grid_width; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << " \n";
    }
}

const std::vector<Cell>& NetworkManager::GetCells() const {
    return cells;
}
