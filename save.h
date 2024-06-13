#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "State.h"
#include <unordered_map>
#include <sstream>

using namespace std;

vector<Room*> rooms;
vector<GameObject*> objects;
// 物品map，根据id获取物品对象
unordered_map<int, GameObject*> objectMap;

GameObject* getObjectById(int id) {
    return objectMap[id];

}

void recordRoom(Room* room) {
    rooms.push_back(room);
}

void recordObject(GameObject* obj) {
    objects.push_back(obj);
    objectMap[obj->getId()] = obj;
}

Room* getRoomById(int id) {
    for (Room* room : rooms) {
        if (room->getId() == id) {
            return room;
        }
    }

    return nullptr;
}

void recordObjects(const std::vector<GameObject*> objects) {
    for (GameObject* obj : objects) {
        recordObject(obj);
    }
}
void recordRooms(const std::vector<Room*> rooms) {
    for (const auto& room : rooms) {
        recordRoom(room);
    }
}


bool save(State* state, const std::string& filename) {
    ofstream file(filename);

    // 保存当前房间
    int currRoomId = state->getCurrentRoom()->getId();
    file << currRoomId << endl;
    // 保存体力
    int strength = state->getStrength();
    file << strength << endl;

    // 保存每个房间中的物品
    for (Room* room : rooms) {
        int roomId = room->getId();
        file << roomId << " ";

        for (GameObject* obj : room->getGameObjects()) {
            int objId = obj->getId();
            file << objId << " ";
        }
        file << endl;
    }
    file << endl;
    // 保存玩家仓库中的物品
    for (GameObject* obj : state->getInventory()) {
        int objId = obj->getId();
        file << objId << " ";
    }

    file.close();
    return true;
}

bool fileExists(const std::string& filename) {
    ifstream file(filename);
    return file.good();
}

bool load(State* state, const std::string& filename) {
    ifstream file(filename);

    // 恢复玩家所处房间
    string currRoomIdStr;
    getline(file, currRoomIdStr);
    int currRoomId = stoi(currRoomIdStr);
    Room* currRoom = getRoomById(currRoomId);
    state->setCurrentRoom(currRoom);

    int strength =0;
    string strengthStr;
    getline(file, strengthStr);
    strength = stoi(strengthStr);
    state->setStrength(strength);

    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            break;
        }

        stringstream ss(line);
        int roomId;
        ss >> roomId;

        Room* room = getRoomById(roomId);
        if (room == nullptr) {
            continue;
        }
        room->clearObjects();
        int objId;
        while (ss >> objId) {
            GameObject* obj = getObjectById(objId);
            if (obj != nullptr) {
                room->addobject(obj);
            }
        }
    }

    string objIdStr;
    getline(file, objIdStr);
    stringstream ss(objIdStr);
    state->clearInventoryObj();
    while (ss >> objIdStr) {
        int objId = stoi(objIdStr);
        GameObject* obj = getObjectById(objId);
        if (obj != nullptr) {
            state->addObjToInventory(obj);
        }
    }

    file.close();
    return true;
}