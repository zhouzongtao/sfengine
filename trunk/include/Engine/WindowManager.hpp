#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <Engine/Singleton.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

class WindowManager : public sf::RenderWindow, public Singleton<WindowManager>
{
    public:
        friend WindowManager*   Singleton<WindowManager>::Get();
        friend void             Singleton<WindowManager>::Kill();

    protected:
        WindowManager();
        virtual ~WindowManager();

    private:
};

#endif // WINDOWMANAGER_HPP
