
#include <Engine/Widget.hpp>
#include <Engine/UIManager.hpp>
#include <Engine/Utils.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

Widget* Widget::myFocusedWidget = 0;
Widget* Widget::myHoveredWidget = 0;

Widget::Widget()
    :   Object("Widget"),
        myParent(0),
        mySize(sf::Vector2f(20, 20)),
        myFocusable(true)
{
    //ctor
}

Widget::~Widget()
{
    //dtor
}

void    Widget::Render(sf::RenderTarget& target, sf::RenderQueue& queue) const
{
    queue.SetColor(GetColor());
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

void    Widget::SetParent(Widget* parent)
{
    myParent = parent;
}

Widget* Widget::GetParent() const
{
    return myParent;
}

const Widgets&  Widget::GetChildren() const
{
    return myChildren;
}

void    Widget::Add(Widget* widget)
{
    if (!widget)
        return;

    for (Widgets::const_iterator it = myChildren.begin(); it != myChildren.end(); ++it)
        if (*it == widget)
            return;

    myChildren.push_back(widget);
    widget->SetParent(this);
}

void    Widget::Remove(Widget* widget)
{
    if (!widget)
        return;

    for (Widgets::iterator it = myChildren.begin(); it != myChildren.end(); ++it)
        if (*it == widget)
        {
            myChildren.erase(it);
            return;
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

sf::Vector2f    Widget::GetAbsolutePosition() const
{
    sf::Vector2f absPos = GetPosition();
    Widget* p = GetParent();

    while (p)
    {
        const sf::Vector2f& pos = p->GetPosition();
        absPos.x += pos.x;
        absPos.y += pos.y;

        p = p->GetParent();
    }
    return absPos;
}

void    Widget::SetFocusable(bool focusable)
{
    myFocusable = focusable;
}

bool    Widget::IsFocusable() const
{
    return myFocusable;
}

bool    Widget::IsFocused() const
{
    return (myFocusedWidget == this);
}

bool    Widget::IsHovered() const
{
    return (myHoveredWidget == this);
}

void    Widget::LoadStyle(const sf::String& style)
{
    LoadStyle(UIManager::Get()->GetStyle(style));
}

void    Widget::LoadStyle(Style& style)
{
    Utils* utils = Utils::Get();

    SetColor(utils->GetColorFromString(style["backgroundColor"], GetColor()));
    SetEnabled(utils->GetBooleanFromString(style["enabled"], IsEnabled()));
    SetVisible(utils->GetBooleanFromString(style["visible"], IsVisible()));

    if (style["size"] != "")
        SetSize(utils->GetVectorFromString(style["size"], GetSize()));

    if (style["position"] != "")
        SetPosition(utils->GetVectorFromString(style["position"], GetPosition()));

}
