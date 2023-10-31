

#ifndef TEXTADV_STATE_H
#define TEXTADV_STATE_H


#include "Room.h"

class State {
    Room* currentRoom;
    vector<GameObject> inventory;
    int strength; // Player's physical strength

public:
    explicit State(Room* startRoom) : currentRoom(startRoom), strength(100) {}

    void goTo(Room* target) {
        currentRoom = target;
    }

    void announceLoc() const {
        currentRoom->describe();
    }

    Room* getCurrentRoom() const {
        return currentRoom;
    }
    int getStrength() const {
        return strength;
    }

    void setStrength(int value) {
        strength = value;
    }


#endif //TEXTADV_STATE_H
