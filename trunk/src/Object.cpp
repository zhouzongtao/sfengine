#include "Object.hpp"

Object::Object(const sf::Utf8& name)
    :   myName(name)
{

}

Object::~Object()
{
    //dtor
}

const sf::Utf8& Object::GetName() const
{
    return myName;
}

void    Object::Update(const sf::Event& event)
{

}
