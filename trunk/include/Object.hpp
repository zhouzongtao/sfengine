#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/System/String.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>


class Object : public sf::Drawable
{
    public:
        Object(const sf::String& name);
        virtual ~Object();

        void                SetName(const sf::String& name);
        const sf::String&   GetName() const;

        const sf::Uint32&   GetId() const;

        //virtual void    Render(sf::RenderTarget& target, sf::RenderQueue& queue) const;
        virtual void        Update(const sf::Event& event);
//        virtual void    ReceiveMessage(Message& message);

    protected:


    private:
        sf::String          myName;
        sf::Uint32          myId;

        static sf::Uint32   myNextId;
};

#endif // OBJECT_HPP
