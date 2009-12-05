#include "Scene.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

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

void    Scene::Update(const sf::Event& event)
{
    for (Objects::const_iterator it = myObjects.begin(); it != myObjects.end(); ++it)
    {
        Object* object = it->second;

        if (object)
            if (object->IsEnabled())
                object->Update(event);
    }
}

void    Scene::Render(sf::RenderTarget& target, sf::RenderQueue& queue) const
{
    for (Objects::const_iterator it = myObjects.begin(); it != myObjects.end(); ++it)
    {
        Object* object = it->second;

        if (object)
            if (object->IsVisible())
                target.Draw(*object);
    }
}
