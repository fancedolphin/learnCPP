

#ifndef TEXTADV_STRINGS_H
#define TEXTADV_STRINGS_H


#include <string>

const std::string r1name = "Room 1";
const std::string r1desc = "You are in room 1. It's really quite boring, but then, it's just for testing really. There's a passage to the north.";
const std::string r2name = "Blue Room";
const std::string r2desc = "You are the blue room. You know because it's blue. That's about all though. There's a passage to the east.";
const std::string r3name = "important room";
const std::string r3desc = "You are in important room. It's a spacious room with some interesting artifacts. There are passages to the east and north.";
const std::string r4name = "Dark Room";
const std::string r4desc = "Welcome to the dark room. It's so dark that you can't see anything. You can go back west to important room.";
const std::string r5name = "Secret Room";
const std::string r5desc = "Congratulations! You found the secret room. It's filled with treasure!";



const std::string badExit = "You can't go that way.";
const std::string badCommand = "I don't understand that.";
const std::string LoseStrength = "Your strength has reached zero. Game over.";


const std::string HelpUsage = "help - print this";
const std::string DirectionUsage = "<direction> - input north(n) or south(s) or east(e) or west(w) to move: ";
const std::string SearchUsage = "search <keyword> - search item by keyword";
const std::string GetUsage = "get <keyword> - get item from room to inventory";
const std::string CheckUsage = "examine <keyword> - check long description of item";
const std::string EatUsage = "eat <food keyword> - eat food to regain energy";
const std::string DiscardUsage = "drop <keyword> - discard item from inventory";
const std::string InventoryUsage = "inventory - check inventory";
const std::string SaveUsage = "save - save current game status";
const std::string LoadUsage = "load - load previously saved game";
const std::string QuitUsage = "quit - quit the game";


const std::string SavePrompt = "Enter the save file name: ";
const std::string FileExistsPrompt = "File already exists. Continue overwriting? (y/n): ";
const std::string SaveSuccessMessage = "Save successful.";
const std::string SaveFailureMessage = "Save failed.";
const std::string LoadWarningPrompt = "Loading will lose current progress. Continue? (y/n): ";
const std::string LoadPrompt = "Enter the file name to load: ";
const std::string LoadSuccessMessage = "Load successful.";
const std::string LoadFailureMessage = "Load failed.";
const std::string FileNotExistsMessage = "File Not Exists. Please check it.";

#endif //TEXTADV_STRINGS_H
