#include <unordered_map>
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
    auto* r2 = new Room(&r2name, &r2desc);
    auto* r1 = new Room(&r1name, &r1desc);
    Room room3(&r1name, &r1desc);
    Room* r3 = &room3;
    Room room4(&r1name, &r1desc);
    Room* r4 = &room4;
    Room::addRoom(r1);
    Room::addRoom(r2);
    Room::addRoom(r3);
    Room::addRoom(r4);

    unordered_map<string, Room*> exits;  // Unordered map to store the exits

    exits["north"] = r2;  // Connect r1 to r2 in the north direction
    exits["south"] = r1;  // Connect r2 to r1 in the south direction
    exits["east"] = r3;   // Connect r2 to r3 in the east direction
    exits["west"] = r2;   // Connect r3 to r2 in the west direction
    exits["south"] = r4;  // Connect r3 to r4 in the south direction
    exits["north"] = r3;  // Connect r4 to r3 in the north direction

    // Set the exits for each room based on the unordered map
    for (const auto& exit : exits) {
        if (exit.second != nullptr) {
            if (exit.first == "north") {
                r1->setNorth(exit.second);
            } else if (exit.first == "south") {
                r1->setSouth(exit.second);
            } else if (exit.first == "east") {
                r1->setEast(exit.second);
            } else if (exit.first == "west") {
                r1->setWest(exit.second);
            }
        }
    }
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
void handleDirectionCommand(const std::string& command, const std::string& fullCommand, const std::string& direction) {
    if (command == direction || fullCommand == direction.substr(0, 1)) {
        Room* room = currentState->getCurrentRoom()->getRoomInDirection(direction);
        if (room == nullptr) {
            wrapOut(&badExit);
            wrapEndPara();
        } else {
            currentState->goTo(room);
        }
        return;
    }
}

void gameLoop() {
    bool gameOver = false;
    while (!gameOver) {
        /* Ask for a command. */
        bool commandOk = false;
        inputCommand(&commandBuffer);

        /* The first word of a command would normally be the verb. The first word is the text before the first
         * space, or if there is no space, the whole string. */
        auto endOfVerb = static_cast<uint8_t>(commandBuffer.find(' '));

        /* We could copy the verb to another string but there's no reason to, we'll just compare it in place. */

        /* Handle direction commands */
        handleDirectionCommand(commandBuffer, commandBuffer.substr(0, endOfVerb), "north");
        handleDirectionCommand(commandBuffer, commandBuffer.substr(0, endOfVerb), "east");
        handleDirectionCommand(commandBuffer, commandBuffer.substr(0, endOfVerb), "south");
        handleDirectionCommand(commandBuffer, commandBuffer.substr(0, endOfVerb), "west");

        /* Quit command */
        if (commandBuffer.compare(0, endOfVerb, "quit") == 0) {
            commandOk = true;
            gameOver = true;
        }

        /* If commandOk hasn't been set, command wasn't understood, display error message */
        if (!commandOk) {
            wrapOut(&badCommand);
            wrapEndPara();
        }
        /* Reduce strength by 1 per minute */
        if (minutes % 60 == 0) {
            gameState.setStrength(gameState.getStrength() - 1);
        }

        /* Check if strength is 0 */
        if (gameState.getStrength() <= 0) {
            cout << "Your strength has reached 0. Game over." << endl;
            gameOver = true;
        }

        /* Increment minutes */
        minutes++;
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
