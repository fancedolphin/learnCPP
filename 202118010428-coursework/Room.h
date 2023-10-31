


#ifndef TEXTADV_ROOM_H
#define TEXTADV_ROOM_H
#include <vector> 
#include <string>
#include <forward_list>
#include <list>
using namespace std;
using std::string;

/**
 * Represents a room (accessible location in the game).
 */
class GameObject {
    string name;
    string description;
    string keyword;

public:
    GameObject(const string& _name, const string& _description, const string& _keyword)
        : name(_name), description(_description), keyword(_keyword) {}

    const string& getName() const {
        return name;
    }

    const string& getDescription() const {
        return description;
    }

    const string& getKeyword() const {
        return keyword;
    }
};

class FoodObject : public GameObject {
    int energy; // Energy property (limited to a range of 1-10)

public:
    FoodObject(const string& _name, const string& _description, const string& _keyword, int _energy)
        : GameObject(_name, _description, _keyword), energy(_energy) {
        // Limit energy to the range of 1-10
        if (energy < 1) {
            energy = 1;
        } else if (energy > 10) {
            energy = 10;
        }
    }

    int getEnergy() const {
        return energy;
    }
};
using namespace std;
class Room {
    /**
     * Short name used as a header.
     */
    const string* name;
    /**
     * Full description of the room.
     */
    const string* description;
    /**
     * Pointer to room that is north of this one.
     */
    Room* north;
    Room* south;
    Room* west;
    Room* east;
    //vector<GameObject> objects;
public:
    /**
     * Constructs a new Room.
     * @param _name Name of the room.
     * @param _desc Description of the room.
     */
    Room(const string *_name, const string *_desc);

    /**
     * Removes a destroyed room from the global list if it's there.
     */
    ~Room();

    /**
     * Outputs the name and description of the room
     * in standard format.
     */
    void describe() const{
    
    cout << "Name: " << *name << endl;
    cout << "Description: " << *description << endl;

    // Check if there are any objects in the room
    if (!objects.empty()) {
        cout << "Objects in the room: ";
        for (const auto& object : objects) {
            cout << object.getName() <<endl ;
        }
        
        }
    }

    /**
     * List storing all rooms that have been registered via addRoom().
     */
    static std::list<Room*> rooms;

    /**
     * Creates a new Room with the given parameters and register it with the static list.
     * @param _name Name of the room.
     * @param _desc Description of the room.
     */
    static Room* addRoom(const string* _name, const string* _desc){
        Room* room= new Room(_name, _desc);
        rooms.push_back(room);
        return room;
    }
    static void addRoom(Room* room){
        rooms.push_back(room);
    }


    Room* getNorth() const{
        return north;
    }
    void setNorth(Room* _north){
        north=_north;
    }
    Room* getSouth() const {
        return south;
    }

    void setSouth(Room* _south) {
        south = _south;
    }

    Room* getEast() const {
        return east;
    }

    void setEast(Room* _east) {
        east = _east;
    }

    Room* getWest() const {
        return west;
    }

    void setWest(Room* _west) {
        west = _west;
    }

    void addObject(const GameObject& object) {
        objects.push_back(object);
    }

    void removeObject(const string& keyword) {
        objects.erase(
            std::remove_if(objects.begin(), objects.end(),
                           [&](const GameObject& obj) { return obj.getKeyword() == keyword; }),
            objects.end());
    }

    void listObjects() const {
        if (objects.empty()) {
            cout << "There are no objects in the room." << endl;
        } else {
            cout << "Objects in the room:" << endl;
            for (const auto& obj : objects) {
                cout << obj.getName() << " - " << obj.getDescription() << endl;
            }
        }
    }


};


#endif //TEXTADV_ROOM_H
