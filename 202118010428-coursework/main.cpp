
#include <iostream>
#include <iomanip>
#include <memory>
#include <iterator>
#include <vector>
#include <forward_list>
#include "Room.h"
#include "wordwrap.h"
#include "State.h"
#include "strings.h"

using std::string;
using std::unique_ptr;

string commandBuffer;
State *currentState;

/**
 * Print out the command prompt then read a command into the provided string buffer.
 * @param buffer Pointer to the string buffer to use.
 */
void inputCommand(string *buffer) {
    buffer->clear();
    std::cout << "> ";
    std::getline(std::cin, *buffer);
}

/**
 * Sets up the map.
 */
void initRooms() {
    auto * r2 = new Room(&r2name, &r2desc);
    auto * r1 = new Room(&r1name, &r1desc);
    Room::addRoom(r1);
    Room::addRoom(r2);
    Room* r3 = Room::addRoom(&r3name, &r3desc);
    Room* r4 = Room::addRoom(&r4name, &r4desc);
    Room* r5 = Room::addRoom(&r5name, &r5desc);

    r1->setNorth(r2);
    r2->setEast(r3);
    r3->setEast(r4);
    r4->setWest(r3);
    r3->setSouth(r5);
}

/**
 * Sets up the game state.
 */
void initState() {
    currentState = new State(Room::rooms.front());
}


/**
 * The main game loop.
 */
 //增加代码复用性
void handleMovementCommand(const string& command, const string& direction, Room* (Room::*getExit)() const, bool status) {
    if ((command.compare(0, direction.size(), direction) == 0) || (command.compare(0, 1, direction.substr(0, 1)) == 0)) {
        Room* nextRoom = (currentState->getCurrentRoom()->*getExit)();
        if (nextRoom == nullptr) { /* there isn't */
            wrapOut(&badExit);/* Output the "can't go there" message */
            wrapEndPara();
        } else {
            currentState->goTo(nextRoom);/* Update state to that room - this will also describe it */
        }
    }
}

void gameLoop() {
    bool gameOver = false;
    while (!gameOver) {
        bool commandOk = true;
        inputCommand(&commandBuffer);

        /* The first word of a command would normally be the verb. The first word is the text before the first
         * space, or if there is no space, the whole string. */
        auto endOfVerb = static_cast<uint8_t>(commandBuffer.find(' '));

        // Command to go north
        handleMovementCommand(commandBuffer, "north", &Room::getNorth,commandOk);

        // Command to go east
        handleMovementCommand(commandBuffer, "east", &Room::getEast,commandOk);

        // Command to go south
        handleMovementCommand(commandBuffer, "south", &Room::getSouth,commandOk);

        // Command to go west
        handleMovementCommand(commandBuffer, "west", &Room::getWest,commandOk);



        /* Quit command */
        if ((commandBuffer.compare(0, endOfVerb, "quit") == 0)) {
            commandOk = true;
            gameOver = true;
        }

        /* If commandOk hasn't been set, command wasn't understood, display error message */
        if (!commandOk) {
            wrapOut(&badCommand);
            wrapEndPara();
        }
    }
}



int main() {
    initWordWrap();
    initRooms();
    initState();
    currentState->announceLoc();
    gameLoop();
    return 0;
}