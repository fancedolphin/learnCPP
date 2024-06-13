

#ifndef TEXTADV_STATE_H
#define TEXTADV_STATE_H

#include <thread>
#include "Room.h"
#include <functional>


class State {
    Room *currentRoom;
    int strength;  // 玩家体力

private:
    const  int MAX_STRENGTH = 100;  // 最大体力
    std::list<GameObject*> inventory;
public:
    State(Room* startRoom, int initialStrength );
    ~State();  // 声明析构函数
    void goTo(Room *target);
    void inventoryObjMap(std::function<void(GameObject*)> handler); // 玩家库存
    void announceLoc() const;
    Room* getCurrentRoom() const;
    int getStrength() const ;
    void setCurrentRoom(Room* room);

    void addStrength(int strength);
    void setStrength(int strength);

    void addObjToInventory(GameObject* OBJ);
    void removeInventoryObj(string key);   // 从库存中移除
    void clearInventoryObj();   // 清空库存
    bool searchInventoryObjByKey(string key, GameObject*& obj);  // 搜索库存
    bool searchInventoryObjByKey(string key);

    void decreaseStrength(int strength);  // 降低体力

    std::list<GameObject* > getInventory();
};


#endif //TEXTADV_STATE_H
