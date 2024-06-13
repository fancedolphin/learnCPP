#include <string>
#include "wordwrap.h"
#include "strings.h"

class Usage {
public:

    static void printDirectionUsage() {
        wrapOut(&DirectionUsage);
        wrapEndPara();
    }

    static void printSearchUsage() {
        wrapOut(&SearchUsage);
        wrapEndPara();
    }

    static void printGetUsage() {
        wrapOut(&GetUsage);
        wrapEndPara();
    }

    static void printCheckUsage() {
        wrapOut(&CheckUsage);
        wrapEndPara();
    }

    static void printEatUsage() {
        wrapOut(&EatUsage);
        wrapEndPara();
    }

    static void printDiscardUsage() {
        wrapOut(&DiscardUsage);
        wrapEndPara();
    }

    static void printInventoryUsage() {
        wrapOut(&InventoryUsage);
        wrapEndPara();
    }

    static void printSaveUsage() {
        wrapOut(&SaveUsage);
        wrapEndPara();
    }

    static void printLoadUsage() {
        wrapOut(&LoadUsage);
        wrapEndPara();
    }

    static void printQuitUsage() {
        wrapOut(&QuitUsage);
        wrapEndPara();
    }

    static void printHelpUsage() {
        wrapOut(&HelpUsage);
        wrapEndPara();
    }

    static void printALL() {
        printDirectionUsage();
        printSearchUsage();
        printGetUsage();
        printCheckUsage();
        printEatUsage();
        printDiscardUsage();
        printInventoryUsage();
        printSaveUsage();
        printLoadUsage();
        printHelpUsage();
        printQuitUsage();
    }

};