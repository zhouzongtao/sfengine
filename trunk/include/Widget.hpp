#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "Object.hpp"
#include <vector>

class Widget;
typedef std::vector<Widget*>    Widgets;

class Widget : public Object
{
    public:
        Widget();
        virtual ~Widget();

        void                SetSize(const sf::Vector2f& size);
        void                SetSize(float width, float height);
        const sf::Vector2f& GetSize() const;

    protected:
        virtual void        Render(sf::RenderTarget& target, sf::RenderQueue& queue) const;

    private:
        Widgets             myChildren;
        sf::Vector2f        mySize;
};

#endif // WIDGET_HPP
