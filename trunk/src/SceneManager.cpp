#include <Engine/SceneManager.hpp>

#include <Engine/WindowManager.hpp>
#include <Engine/UIManager.hpp>

template<>
SceneManager*  Singleton<SceneManager>::myInstance = 0;

SceneManager::SceneManager()
{
    UIManager::Get();
}

SceneManager::~SceneManager()
{
    UIManager::Kill();
}

bool    SceneManager::AddScene(Scene* scene)
{
    if (!scene)
        return false;
    if (myScenes.find(scene->GetName()) != myScenes.end())
        return false;
    myScenes[scene->GetName()] = scene;
    return true;
}

void    SceneManager::RemoveScene(Scene* scene)
{
    if (scene)
        myScenes.erase(scene->GetName());
}

void    SceneManager::Update(const sf::Event& event)
{
    for (Scenes::const_iterator it = myScenes.begin(); it != myScenes.end(); ++it)
    {
        Scene *scene = it->second;
        scene->Update(event);
    }

    UIManager::Get()->Update(event);
}

void    SceneManager::Display()
{
    // Draws the scenes
    for (Scenes::const_iterator it = myScenes.begin(); it != myScenes.end(); ++it)
    {
        Scene *scene = it->second;
        WindowManager::Get()->Draw(*scene);
    }

    // Draws the user interface
    WindowManager::Get()->Draw(*UIManager::Get());
}
