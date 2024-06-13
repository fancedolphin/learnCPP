
#include "Room.h"
#include "wordwrap.h"
#include <iostream>

/**
 * Stores a static list of all rooms.
 */
std::list<Room*> Room::rooms;
Room::Room(const string* _name, const string *_desc, int id) :
        name(_name), description(_desc), id(id), north(nullptr),east(nullptr),south(nullptr),west(nullptr) {
};

Room::~Room() {
    Room::rooms.remove(this);
}

void Room::describe() const {
    wrapEndPara();
    wrapOut(this->name);
    wrapEndPara();
    wrapOut(this->description);
    wrapEndPara();
    wrapOut(new std::string("--------Room items--------- "));
    wrapEndPara();
    if (gameObjects.size() == 0) {
        wrapOut(new std::string("nothing in here!"));
        wrapEndPara();
    }
    for (auto obj : gameObjects) { // Loop through the objects
         wrapOut(new std::string("item name: "));
         wrapOut(obj->_name);
         wrapOut(new std::string("      keyword: "));
         wrapOut(obj->_keyword);
         wrapEndPara(); }
}



Room* Room::addRoom(const string* _name, const string *_desc, int id) {
    auto *newRoom = new Room(_name, _desc, id);
    rooms.push_back(newRoom);
    return newRoom;
}

/**
 * Adds an existing room to the static list.
 * @param room Pointer to the room to add.
 * @return
 */
void Room::addRoom(Room* room) {
    Room::rooms.push_back(room); /*push_back:add element to the last position of vector*/
}

void Room::addobject(GameObject *OBJ) {
    gameObjects.push_back(OBJ); /*push_back:add element to the last position of vector*/
}
bool Room::searchObjByKey(string key, GameObject*& gObj)
{
    for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
        GameObject* objq = *it;
        if (*(objq->_keyword) == key) {
            gObj = objq;
            return true;
        }
    }
    return false;
}
void Room::clearObjects()
{
    this->gameObjects.clear();
}
/**
 * Gets the north exit of a room.
 * @return The room that is north of this one, or NULL if there is no exit.
 */
Room* Room::getNorth() const {
    return this->north;
}

/**
 * Sets the north exit of a room.
 * @param _north Pointer to the room to be north of this one.
 */
void Room::setNorth(Room* _north) {
    this->north = _north;
}

Room* Room::getEast() const {
    return this->east;
}

void Room::setEast(Room* _east) {
    this->east = _east;

}

Room* Room::getWest() const {
    return this->west;
}

void Room::setWest(Room* _west) {
    this->west = _west;

}

Room *Room::getSouth() const {
    return this->south;
}

void Room::setSouth(Room* _south) {
    this->south =_south;

}

Room* Room::getFirstRoom()
{
    return rooms.front();
}

bool Room::findRoomItemByKey(string key, GameObject*& gameObj)
{
    if (gameObjects.size() == 0) {
        return false;
    }
    for (auto obj : gameObjects) {
        if (*obj->_keyword == key) {
            gameObj = obj;
            return true;
        }
    }
    return false;
}

bool Room::removeRoomItemByKey(string key)
{
    for(auto it=gameObjects.begin(); it!=gameObjects.end(); ++it) {
        GameObject* obj = *it;
        if(*obj->_keyword == key) {
            gameObjects.erase(it);
            return true;
        }
    }
    return false;
}

int Room::getId()
{
    return this->id;
}


std::list<GameObject*> Room::getGameObjects(){
    return this->gameObjects;
}
