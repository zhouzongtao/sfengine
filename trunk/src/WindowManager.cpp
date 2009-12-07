#include <Engine/WindowManager.hpp>

template<>
WindowManager*  Singleton<WindowManager>::myInstance = 0;

WindowManager::WindowManager()
{
    //ctor
}

WindowManager::~WindowManager()
{
    //dtor
}
