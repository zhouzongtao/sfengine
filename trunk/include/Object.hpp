#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/System/Utf.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>


class Object : public sf::Drawable
{
    public:
        Object(const sf::Utf8& name);
        virtual ~Object();

        const sf::Utf8& GetName() const;

        //virtual void    Render(sf::RenderTarget& target, sf::RenderQueue& queue) const;
        virtual void    Update(const sf::Event& event);
//        virtual void    ReceiveMessage(Message& message);

    protected:


    private:
        sf::Utf8     myName;
};

#endif // OBJECT_HPP
