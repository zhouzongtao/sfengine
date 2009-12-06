#include "UIManager.hpp"

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

Style&    UIManager::GetStyle(const sf::String& styleName)
{
    return myStyles[styleName];
}
