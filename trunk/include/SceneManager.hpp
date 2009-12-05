#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include "Singleton.hpp"
#include "Scene.hpp"

typedef std::map<sf::String, Scene*>    Scenes;

class SceneManager : public Singleton<SceneManager>
{
    public:
        friend SceneManager*    Singleton<SceneManager>::Get();

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
