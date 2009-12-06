#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include "Singleton.hpp"

#include <map>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>

#include <SFML/System/String.hpp>

typedef std::map<sf::String, boost::any>   Resources;

class ResourceManager : public Singleton<ResourceManager>
{
    public:
        friend ResourceManager* Singleton<ResourceManager>::Get();
        friend void             Singleton<ResourceManager>::Kill();

        template<typename T>
        boost::shared_ptr<T>    GetResource(const sf::String& name, const sf::String& filename = sf::String())
        {
            if (myResources.find(name) == myResources.end())
            {
                T* res = Load<T>(filename.IsEmpty() ? name : filename);
                if (res)
                {
                    myResources[name] = res;
                    return boost::shared_ptr<T>(boost::any_cast<T*>(res));
                }
                return boost::shared_ptr<T>();
            }
            return boost::shared_ptr<T>(boost::any_cast<T*>(myResources[name]));
        }

        const Resources&    GetResources() const;

    protected:

        template<typename T>
        T*  Load(const sf::String& filename);

        ResourceManager();
        virtual ~ResourceManager();

    private:

        Resources      myResources;
};

#endif // RESOURCEMANAGER_HPP
