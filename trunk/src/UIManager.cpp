#include "UIManager.hpp"

#include "Widget.hpp"

template<>
UIManager*  Singleton<UIManager>::myInstance = 0;

UIManager::UIManager()
    :   Scene("UI")
{
}

UIManager::~UIManager()
{
    //dtor
}
