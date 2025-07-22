#include <iostream>
#include "src/include/AllHeaders.hpp"
#include <thread> 
#include <chrono> 
int main() {
    NetworkManager::Init(10, 10);
    auto& manager = NetworkManager::Get();

    manager.PlaceCell(2, 2, 1, 2);
    manager.PlaceCell(7, 7, 2, 3);

    manager.AddUser(3, 2, 7);
    manager.AddUser(2, 3, 8);
    manager.AddUser(7, 8, 9);

    manager.ShowGrid();

    const auto& cells = manager.GetCells();

    std::cout << "List of cells:\n";
    for (size_t i = 0; i < cells.size(); ++i) {
        std::cout << i << ": Cell ID = " << cells[i].getId() << std::endl;
    }

    std::cout << "Select user cell ";
    size_t idx;
    std::cin >> idx;

    if (idx < cells.size()) {
        const auto& userIds = cells[idx].GetUserList();
        std::cout << "Users in cell " << idx << ":\n";
        for (int userId : userIds) {
            const User* user = manager.GetUserById(userId);
            if (user) {
                std::cout << "ID: " << user->getId()
                    << " Position: (" << user->getX() << ", " << user->getY() << ")\n";
            }
        }
    }
    else {
        std::cout << "Wrong cell number!" << std::endl;
    }

    Scheduler scheduler;
    int round = 0;
    while (true) {
        for (auto& user : manager.GetUsers()) {
            int dx = rand() % 3 - 1; // -1, 0, 1
            int dy = rand() % 3 - 1;
            user.move(dx, dy);
            manager.HandleHandover(user);
        }

        for (const auto& cell : manager.GetCells()) {
            const auto& userIds = cell.GetUserList();
            auto allocated = scheduler.AllocateResources(userIds);
            for (int userId : allocated) {
                std::cout << "Round " << round << ": packet for user " << userId
                    << " in cell " << cell.getId() << std::endl;
            }
        }
        ++round;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 1 second delay
    }
return 0;
}