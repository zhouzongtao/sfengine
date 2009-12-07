#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <Engine/Singleton.hpp>
#include <Engine/Scene.hpp>

typedef std::map<sf::String, Scene*>    Scenes;

class SceneManager : public Singleton<SceneManager>
{
    public:
        friend SceneManager*    Singleton<SceneManager>::Get();
        friend void             Singleton<SceneManager>::Kill();

        bool                    AddScene(Scene* scene);
        void                    RemoveScene(Scene* scene);

        void                    Update(const sf::Event& event);
        void                    Display();

    protected:
        SceneManager();
        virtual ~SceneManager();

    private:
        Scenes                  myScenes;
};

#endif // SCENEMANAGER_HPP
