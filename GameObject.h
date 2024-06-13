#ifndef TEXTADV_GameObject_H
#define TEXTADV_GameObject_H
#include <string>


class GameObject {
private:
    int id;
public:
    const std::string* _desc;  // �ϳ�������
    const std::string* _keyword;  // �ؼ���
    const std::string* _name; // ����
    GameObject(const std::string *_name, const std::string *_desc, const std::string *_keyword, int id);
    virtual ~GameObject() {}
    int getId();
};

class FoodObject : public GameObject {
private:
    int energy;

public:
    FoodObject(const std::string* _name, const std::string* _desc, const std::string* _keyword, int id, int _energy)
            : GameObject(_name, _desc, _keyword, id), energy(_energy) {
        // Limit the energy value within the range of 1-10
        if (energy < 1)
            energy = 1;
        else if (energy > 10)
            energy = 10;
    }

    int getEnergy() const {
        return energy;
    }
};
#endif //GameObject_H


