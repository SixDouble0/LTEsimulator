#pragma once

class Cell {

public :
	Cell(int pos_x, int pos_y, int cell_id, int radius);

private :

	int x; // X coordinate of the cell
	int y; // Y coordinate of the cell
	int id; // Unique identifier for the cell
	int r; // Radius of the cell coverage area
};