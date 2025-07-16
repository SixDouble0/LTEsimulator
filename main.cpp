// LTEsimulator.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "src/include/AllHeaders.hpp"
#include <iostream>


int main()
{
	NetworkManager::Init(10, 10);
	User user1(2, 2, 1);
	User user2(2, 3, 2);
	User user3(3, 7, 3);
	Cell cell1(1, 2, -1, 3);
	NetworkManager::Get().ShowGrid();
	return 0;
}
