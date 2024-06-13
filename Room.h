


#ifndef TEXTADV_ROOM_H
#define TEXTADV_ROOM_H

#include <string>
#include <forward_list>
#include <list>
#include "GameObject.h"

using std::string;

/**
 * Represents a room (accessible location in the game).
 */
class Room {

    const string* name;
    const string* description;
    Room* north;
    Room* east;
    Room* west;
    Room* south;
private:
    static std::list<Room*> rooms;
    std::list<GameObject*> gameObjects;
    int id;
    static int idGenerator;
public:
    /**
     * Constructs a new Room.
     * @param _name Name of the room.
     * @param _desc Description of the room.
     */
    Room(const string *_name, const string *_desc, int id);

    /**
     * Removes a destroyed room from the global list if it's there.
     */
    ~Room();

    /**
     * Outputs the name and description of the room
     * in standard format.
     */
    void describe() const;

    /**
     * List storing all rooms that have been registered via addRoom().
     */
   

    /**
     * Creates a new Room with the given parameters and register it with the static list.
     * @param _name Name of the room.
     * @param _desc Description of the room.
     */
    static Room* addRoom(const string* _name, const string* _desc, int id);
    static void addRoom(Room* room);
    void addobject(GameObject* OBJ);
   bool searchObjByKey(string key, GameObject *& gObj);
   void clearObjects();

   std::list<GameObject*> getGameObjects();

    Room* getNorth() const;
    void setNorth(Room* _north);

    Room* getEast() const;
    void setEast(Room* _east);

    Room* getWest() const;
    void setWest(Room* _west);

    Room* getSouth() const;
    void setSouth(Room* _south);
    static Room* getFirstRoom();

    bool findRoomItemByKey(string key, GameObject*& gameObj);
    bool removeRoomItemByKey(string key);
    int getId();
};

#endif //TEXTADV_ROOM_H
