#include "Widget.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

Widget::Widget()
    :   Object("Widget")
{
    //ctor
}

Widget::~Widget()
{
    //dtor
}

void    Widget::Render(sf::RenderTarget& target, sf::RenderQueue& queue) const
{
    queue.SetTexture(0);

    queue.BeginBatch();
    queue.AddVertex(0, 0);
    queue.AddVertex(0, mySize.y);
    queue.AddVertex(mySize.x, mySize.y);
    queue.AddVertex(mySize.x, 0);

    queue.AddTriangle(0, 1, 3);
    queue.AddTriangle(3, 1, 2);

    for (Widgets::const_iterator it = myChildren.begin(); it != myChildren.end(); ++it)
    {
        Widget* child = *it;
        if (child->IsVisible())
            target.Draw(*child);
    }
}

void    Widget::SetSize(const sf::Vector2f& size)
{
    mySize = size;
}

void    Widget::SetSize(float width, float height)
{
    mySize.x = width;
    mySize.y = height;
}

const sf::Vector2f& Widget::GetSize() const
{
    return mySize;
}
