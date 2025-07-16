#include "include/Utilis.hpp"
#include <queue>
#include <utility>

int FindNearestCellBFS(const std::vector<std::vector<int>>& grid, int user_x, int user_y) {
    int grid_height = grid.size();
    int grid_width = grid[0].size();
    std::vector<std::vector<bool>> visited(grid_height, std::vector<bool>(grid_width, false));
    std::queue<std::pair<int, int>> q;
    q.push({ user_x, user_y });
    visited[user_x][user_y] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Komórka: cellId > 0 i nie jest userId
        if (grid[x][y] > 0 && !(x == user_x && y == user_y)) {
            return grid[x][y];
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
    return -1; // Nie znaleziono komórki
}
