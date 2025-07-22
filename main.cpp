#include <iostream>
#include "src/include/AllHeaders.hpp"

int main() {
    // Inicjalizacja sieci (np. 10x10)
    NetworkManager::Init(10, 10);
    auto& manager = NetworkManager::Get();

    // Dodaj przykładowe komórki
    manager.PlaceCell(2, 2, 1, 2);
    manager.PlaceCell(7, 7, 2, 3);

    // Dodaj przykładowych użytkowników
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


return 0;
}