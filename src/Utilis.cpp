#include "include/Utilis.hpp"
#include <queue>
#include <utility>
#include <vector>
#include <cmath>

std::vector<int> FindNearestUserBFS(const std::vector<std::vector<int>>& grid, int cell_x, int cell_y, int radius) {
    int grid_height = grid.size();
    int grid_width = grid[0].size();
    std::vector<std::vector<bool>> visited(grid_height, std::vector<bool>(grid_width, false));
    std::queue<std::pair<int, int>> q;
    std::vector<int> foundUsers;

    q.push({ cell_x, cell_y });
    visited[cell_x][cell_y] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        int dist = std::abs(x - cell_x) + std::abs(y - cell_y);
        if (dist > radius) continue;

        if (grid[x][y] > 0) {
            foundUsers.push_back(grid[x][y]);
        }

        const int dx[] = { 1, -1, 0, 0 };
        const int dy[] = { 0, 0, 1, -1 };
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < grid_height && ny >= 0 && ny < grid_width && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }
    return foundUsers;
}
