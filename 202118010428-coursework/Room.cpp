
#include "Room.h"
#include "wordwrap.h"

/**
 * Stores a static list of all rooms.
 */
std::list<Room*> Room::rooms;

/**
 * Room default constructor.
 * @param _name Room's name.
 * @param _desc Room's description.
 */
Room::Room(const string* _name, const string *_desc) :
        name(_name), description(_desc), north(nullptr) {};

/**
 * Remove destroyed rooms from the static list.
 */
Room::~Room() {
    Room::rooms.remove(this);
}

/**
 * Prints the description of a room (the name and long description)
 */
void Room::describe() const {
    wrapOut(this->name);
    wrapEndPara();
    wrapOut(this->description);
    wrapEndPara();
}

/**
 * Statically creates a room and then adds it to the global list.
 * @param _name Name for the new room.
 * @param _desc Description for the new room.
 * @return A pointer to the newly created room.
 */
Room* Room::addRoom(const string* _name, const string *_desc) {
    auto *newRoom = new Room(_name, _desc);
    Room::rooms.push_back(newRoom);
    return newRoom;
}

/**
 * Adds an existing room to the static list.
 * @param room Pointer to the room to add.
 * @return
 */
void Room::addRoom(Room* room) {
    Room::rooms.push_back(room);
}
Room* (Room::*getDirectionFunction(const string& direction))() const {
    if (direction == "north") {
        return &Room::getNorth;
    }
    else if (direction == "east") {
        return &Room::getEast;
    }
    else if (direction == "south") {
        return &Room::getSouth;
    }
    else if (direction == "west") {
        return &Room::getWest;
    }
    else {
        return nullptr;
    }
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
Room* Room::getSouth() const {
    return this->south;
}

/**
 * Sets the sorth exit of a room.
 * @param _sorth Pointer to the room to be north of this one.
 */
void Room::setSouth(Room* _sorth) {
    this->north = _sorth;
}

Room* Room::getEast() const {
    return this->east;
}

/**
 * Sets the sorth exit of a room.
 * @param _sorth Pointer to the room to be north of this one.
 */
void Room::setEast(Room* _east) {
    this->east = _east;
}

Room* Room::getWest() const {
    return this->west;
}

/**
 * Sets the sorth exit of a room.
 * @param _sorth Pointer to the room to be north of this one.
 */
void Room::setWest(Room* _west) {
    this->west = _west;
}