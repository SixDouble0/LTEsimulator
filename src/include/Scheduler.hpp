#pragma once
#include <vector>

class Scheduler {
public:
    Scheduler();

    // Przydziela zasoby u�ytkownikom w kom�rce metod� round robin
    // Zwraca wektor id u�ytkownik�w, kt�rzy otrzymali zas�b w tej turze
    std::vector<int> AllocateResources(const std::vector<int>& userIds);

private:
    size_t lastIndex; // indeks ostatniego u�ytkownika, kt�ry dosta� zas�b
};
