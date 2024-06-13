

#include "State.h"

/**
 * Current state of the game.
 */
std::list<GameObject*> inventory;
/**
 * Display the description of the room the player is in. */


void State::announceLoc() const {
    this->currentRoom->describe();
}

/**
 * Constructor.
 * @param startRoom Pointer to the room to start in.
 */
State::State(Room *startRoom,int initialStrength) :
    currentRoom(startRoom),strength(initialStrength) {
};

void State::inventoryObjMap( std::function<void(GameObject*)> handler)
{
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        GameObject* obj = *it;
        handler(obj);
    }
}
State::~State() {}

void State::decreaseStrength(int strength) {  // 降低体力
    this->strength-= strength;
}

std::list<GameObject*> State::getInventory()
{
    return this->inventory;
}

/**
 * Move to a specified room and print its description.
 * @param target Pointer to the room to move to.
 */
void State::goTo(Room *target) {
    this->currentRoom = target;
    this->announceLoc();
}


Room* State::getCurrentRoom() const {
    return this->currentRoom;
}

int State::getStrength() const  {
    return this->strength;
}

void State::setCurrentRoom(Room* room)
{
    this->currentRoom = room;
}

void State::addStrength(int strength)
{
    this->strength += strength;
    if (this->strength > State::MAX_STRENGTH) {  // 限制最大体力
        this->strength = State::MAX_STRENGTH;
    }
}

void State::setStrength(int strength)
{
    this->strength = strength;
}

void State::addObjToInventory(GameObject* obj) {
    inventory.push_back(obj);
}


void State::removeInventoryObj(std::string key) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        GameObject* obj = *it;
        if (*(obj->_keyword) == key) {
            inventory.erase(it);
            return;
        }
    }
}

void State::clearInventoryObj()
{
    this->inventory.clear();
}

bool State::searchInventoryObjByKey(string key, GameObject*& obj) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        GameObject* objq = *it;
        if (*(objq->_keyword) == key) {
            obj = objq;
            return true;
        }
    }

    return false;
}

bool State::searchInventoryObjByKey(string key)
{
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        GameObject* objq = *it;
        if (*(objq->_keyword) == key) {
            return true;
        }
    }
    return false;
}
