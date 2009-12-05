#include "Scene.hpp"

Scene::Scene(const sf::String& name)
    :   myName(name)
{
    //ctor
}

Scene::~Scene()
{
    //dtor
}

bool        Scene::AddObject(Object* object)
{
    if (!object)
        return false;
    if (myObjects.find(object->GetId()) != myObjects.end())
        return false;
    myObjects[object->GetId()] = object;
    return true;
}

void    Scene::RemoveObject(Object* object)
{
    if (object)
    {
        myObjects.erase(object->GetId());
    }
}

void    Scene::RemoveObjectsByName(const sf::String& name)
{
    for (Objects::iterator it = myObjects.begin(); it != myObjects.end(); ++it)
    {
        Object* obj = it->second;
        if (obj->GetName() == name)
            myObjects.erase(it);
    }
}

const Objects&  Scene::GetObjects() const
{
    return myObjects;
}

Objects    Scene::GetObjectsByName(const sf::String& name)
{
    Objects list;
    for (Objects::iterator it = myObjects.begin(); it != myObjects.end(); ++it)
    {
        Object* obj = it->second;
        if (obj->GetName() == name)
            list[obj->GetId()] = obj;
    }
    return list;
}
