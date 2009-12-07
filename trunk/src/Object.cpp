#include <Engine/Object.hpp>

sf::Uint32 Object::myNextId = 0;

Object::Object(const sf::String& name)
    :   myName(name),
        myEnabled(true),
        myVisible(true)

{
    myId = myNextId++;
}

Object::~Object()
{
    //dtor
}

void    Object::SetName(const sf::String& name)
{
    myName = name;
}

const sf::String& Object::GetName() const
{
    return myName;
}

const sf::Uint32&   Object::GetId() const
{
    return myId;
}

void    Object::Update(const sf::Event& event)
{

}

void    Object::SetEnabled(bool enabled)
{
    myEnabled = enabled;
}

bool    Object::IsEnabled() const
{
    return myEnabled;
}

void    Object::SetVisible(bool visible)
{
    myVisible = visible;
}

bool    Object::IsVisible() const
{
    return myVisible;
}
