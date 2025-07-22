#pragma once
#include <vector>

class Scheduler {
public:
    Scheduler();

    // Przydziela zasoby u¿ytkownikom w komórce metod¹ round robin
    // Zwraca wektor id u¿ytkowników, którzy otrzymali zasób w tej turze
    std::vector<int> AllocateResources(const std::vector<int>& userIds);

private:
    size_t lastIndex; // indeks ostatniego u¿ytkownika, który dosta³ zasób
};
