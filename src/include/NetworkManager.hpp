#pragma once
#include <vector>

class NetworkManager {
public:
    NetworkManager(const NetworkManager&) = delete;
    static void Init(int height, int width);
    static NetworkManager& Get();
    void PlaceUser(int pos_x, int pos_y, int userId);
	void PlaceCell(int pos_x, int pos_y, int cellId, int radius);
    void ShowGrid();
    void ConnectUserToNearestCell(int userId, int pos_x, int pos_y);
private:
    NetworkManager(int height, int width);
    int grid_height, grid_width;
    std::vector<std::vector<int>> grid;
    static NetworkManager* instance;
};

