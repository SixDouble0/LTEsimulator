#include "include/User.hpp"
#include "include/NetworkManager.hpp"

User::User(int pos_y, int pos_x, int user_id)
    : y(pos_y), x(pos_x), id(user_id) {

    NetworkManager::Get().PlaceUser(pos_x, pos_y, user_id);
 
}
