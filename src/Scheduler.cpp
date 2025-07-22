#include "include/Scheduler.hpp"

Scheduler::Scheduler() : lastIndex(0) {}

std::vector<int> Scheduler::AllocateResources(const std::vector<int>& userIds) {
    std::vector<int> allocated;
    if (userIds.empty()) return allocated;

    allocated.push_back(userIds[lastIndex]);
    lastIndex = (lastIndex + 1) % userIds.size();
    return allocated;
}
