#include <Engine/ResourceManager.hpp>

template<>
ResourceManager*    Singleton<ResourceManager>::myInstance = 0;

ResourceManager::ResourceManager()
{
    //ctor
}

ResourceManager::~ResourceManager()
{
    //dtor
}


#include <SFML/Graphics/Image.hpp>
template<>
sf::Image*  ResourceManager::Load(const sf::String& filename)
{
    sf::Image* img = new sf::Image();
    if (img->LoadFromFile(filename))
        return img;
    delete img;
    return 0;
}
