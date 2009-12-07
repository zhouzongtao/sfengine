
#include <Engine/UIManager.hpp>
#include <Engine/WindowManager.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

template<>
UIManager*  Singleton<UIManager>::myInstance = 0;

UIManager::UIManager()
    :   Widget()
{
    WindowManager* window = WindowManager::Get();

    SetSize(window->GetWidth(), window->GetHeight());
    SetColor(sf::Color(0, 0, 0, 0));
}

UIManager::~UIManager()
{
    myStyles.clear();
}

#include <iostream>

void        UIManager::Update(const sf::Event& event)
{
    if (event.Type == sf::Event::GainedFocus || event.Type == sf::Event::LostFocus ||
        event.Type == sf::Event::MouseEntered || event.Type == sf::Event::MouseLeft)
        return;

    // HoverState handle
    if (event.Type == sf::Event::MouseMoved)
    {
        SetHoveredWidget(sf::Vector2f(event.MouseMove.X, event.MouseMove.Y), this);
    }

    sf::Event newEvent = event;

    // Focus handle
    if (event.Type == sf::Event::MouseButtonPressed && Widget::myHoveredWidget &&
        Widget::myHoveredWidget != Widget::myFocusedWidget)
    {
        if (Widget::myHoveredWidget->IsFocusable())
        {
            // send LostFocus to last focused widget.
            if (Widget::myFocusedWidget)
            {
                newEvent.Type = sf::Event::LostFocus;
                myFocusedWidget->Update(newEvent);
            }

            Widget::myFocusedWidget = Widget::myHoveredWidget;

            // send GainedFocus to new focused widget.
            newEvent.Type = sf::Event::GainedFocus;
        }
    }

    if (Widget::myFocusedWidget)
        Widget::myFocusedWidget->Update(newEvent);
}

bool        UIManager::IsUnderMouse(Widget *widget, const sf::Vector2f& mouse) const
{
    const sf::Vector2f& pos = widget->GetAbsolutePosition();
    if (mouse.x >= pos.x && mouse.y >= pos.y &&
        mouse.x <= pos.x + widget->GetSize().x && mouse.y <= pos.y + widget->GetSize().y)
    {
        return true;
    }
    return false;
}

bool        UIManager::SetHoveredWidget(const sf::Vector2f& mouse, Widget* initialWidget)
{
    if (!initialWidget)
        return false;

    const Widgets& children = initialWidget->GetChildren();
    for (Widgets::const_reverse_iterator it = children.rbegin(); it != children.rend(); ++it)
    {
        Widget *widg = *it;

        if (IsUnderMouse(widg, mouse) && !SetHoveredWidget(mouse, widg))
        {
            Widget::myHoveredWidget = widg;
            return true;
        }
    }

    return false;
}

void        UIManager::AddStyle(const sf::String& name, const Style& style)
{
    myStyles[name] = style;
}

Style&    UIManager::GetStyle(const sf::String& styleName)
{
    return myStyles[styleName];
}
