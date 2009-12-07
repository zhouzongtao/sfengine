#ifndef SCENE_HPP
#define SCENE_HPP

#include <map>
#include <Engine/Object.hpp>

typedef std::map<sf::Uint32, Object*>    Objects;

class Scene : public sf::Drawable
{
    public:
        Scene(const sf::String& name);
        virtual ~Scene();

        const sf::String&   GetName() const;

        bool                AddObject(Object *object);

        void                RemoveObject(Object* object);
        void                RemoveObjectsByName(const sf::String& name);

        const Objects&      GetObjects() const;
        Objects             GetObjectsByName(const sf::String& name);

        virtual void        Update(const sf::Event& event);
        virtual void        Render(sf::RenderTarget& target, sf::RenderQueue& queue) const;

    private:
        sf::String      myName;
        Objects         myObjects;
};

#endif // SCENE_HPP
