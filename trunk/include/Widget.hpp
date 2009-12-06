#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "Object.hpp"
#include <vector>
#include <map>

class Widget;

typedef std::vector<Widget*>                Widgets;
typedef std::map<sf::String, sf::String>    Style;

class Widget : public Object
{
    public:
        Widget();
        virtual ~Widget();

        void                SetSize(const sf::Vector2f& size);
        void                SetSize(float width, float height);
        const sf::Vector2f& GetSize() const;

        void                LoadStyle(const sf::String& styleName);
        void                LoadStyle(Style& style);

    protected:
        virtual void        Render(sf::RenderTarget& target, sf::RenderQueue& queue) const;

    private:
        Widgets             myChildren;
        sf::Vector2f        mySize;
};

#endif // WIDGET_HPP
