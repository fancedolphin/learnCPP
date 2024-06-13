
#include "GameObject.h"
#include "wordwrap.h"
GameObject::GameObject(const std::string* _name, const std::string* _desc, const std::string* _keyword, int id)
    : _name(_name), _desc(_desc), _keyword(_keyword), id(id)
{
}

int GameObject::getId()
{
    return this->id ;
}
;

