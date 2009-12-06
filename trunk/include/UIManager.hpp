#ifndef UIMANAGER_HPP
#define UIMANAGER_HPP

#include "Singleton.hpp"
#include "Scene.hpp"
#include "Widget.hpp"

#include <map>

class UIManager : public Scene, public Singleton<UIManager>
{
    public:
        friend UIManager*   Singleton<UIManager>::Get();
        friend void         Singleton<UIManager>::Kill();

        Style&              GetStyle(const sf::String& styleName);

    protected:
        UIManager();
        virtual ~UIManager();

    private:
        typedef std::map<sf::String, Style> Styles;

        Styles              myStyles;
};

#endif // UIMANAGER_HPP
