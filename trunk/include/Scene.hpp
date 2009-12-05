#ifndef SCENE_HPP
#define SCENE_HPP

#include <map>
#include "Object.hpp"

typedef std::map<sf::Uint32, Object*>    Objects;

class Scene : public sf::Drawable
{
    public:
        Scene(const sf::String& name);
        virtual ~Scene();

        bool            AddObject(Object *object);

        void            RemoveObject(Object* object);
        void            RemoveObjectsByName(const sf::String& name);

        const Objects&  GetObjects() const;
        Objects         GetObjectsByName(const sf::String& name);

    private:
        sf::String      myName;
        Objects         myObjects;
};

#endif // SCENE_HPP
