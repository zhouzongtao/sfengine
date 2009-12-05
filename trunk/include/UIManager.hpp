#ifndef UIMANAGER_HPP
#define UIMANAGER_HPP

#include "Singleton.hpp"
#include "Scene.hpp"

class UIManager : public Scene, public Singleton<UIManager>
{
    public:
        friend UIManager*   Singleton<UIManager>::Get();
        friend void         Singleton<UIManager>::Kill();

    protected:
        UIManager();
        virtual ~UIManager();

    private:
};

#endif // UIMANAGER_HPP
