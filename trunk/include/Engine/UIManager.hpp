#ifndef UIMANAGER_HPP
#define UIMANAGER_HPP

#include <Engine/Singleton.hpp>
#include <Engine/Scene.hpp>
#include <Engine/Widget.hpp>

#include <map>

class UIManager : public Widget, public Singleton<UIManager>
{
    public:
        friend UIManager*   Singleton<UIManager>::Get();
        friend void         Singleton<UIManager>::Kill();

        void                AddStyle(const sf::String& name, const Style& style);
        Style&              GetStyle(const sf::String& styleName);

        virtual void        Update(const sf::Event& event);

    protected:
        UIManager();
        virtual ~UIManager();

    private:
        void                SendEvent(const sf::Event& event);
        bool                SetHoveredWidget(const sf::Vector2f& mouse, Widget* initialWidget);
        bool                IsUnderMouse(Widget *widget, const sf::Vector2f& mouse) const;

        typedef std::map<sf::String, Style> Styles;

        Styles              myStyles;
};

#endif // UIMANAGER_HPP
