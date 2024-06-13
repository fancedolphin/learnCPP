

#ifndef TEXTADV_STATE_H
#define TEXTADV_STATE_H

#include <thread>
#include "Room.h"
#include <functional>


class State {
    Room *currentRoom;
    int strength;  // �������

private:
    const  int MAX_STRENGTH = 100;  // �������
    std::list<GameObject*> inventory;
public:
    State(Room* startRoom, int initialStrength );
    ~State();  // ������������
    void goTo(Room *target);
    void inventoryObjMap(std::function<void(GameObject*)> handler); // ��ҿ��
    void announceLoc() const;
    Room* getCurrentRoom() const;
    int getStrength() const ;
    void setCurrentRoom(Room* room);

    void addStrength(int strength);
    void setStrength(int strength);

    void addObjToInventory(GameObject* OBJ);
    void removeInventoryObj(string key);   // �ӿ�����Ƴ�
    void clearInventoryObj();   // ��տ��
    bool searchInventoryObjByKey(string key, GameObject*& obj);  // �������
    bool searchInventoryObjByKey(string key);

    void decreaseStrength(int strength);  // ��������

    std::list<GameObject* > getInventory();
};


#endif //TEXTADV_STATE_H
