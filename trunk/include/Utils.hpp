#ifndef UTILS_HPP
#define UTILS_HPP

#include "Singleton.hpp"
#include <sstream>

#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

class Utils : public Singleton<Utils>
{
    public:
        friend Utils*   Singleton<Utils>::Get();
        friend void     Singleton<Utils>::Kill();


        sf::Color       GetColorFromString(const sf::String& colorStr, const sf::Color& defaultValue);
        bool            GetBooleanFromString(const sf::String& boolStr, bool defaultValue);
        sf::Vector2f    GetVectorFromString(const sf::String& boolStr, const sf::Vector2f& defaultValue);

        template<typename T>
        T   GetFromString(const sf::String& value, const T& defaultValue)
        {
            T valueBack;
            std::istringstream iss(value);

            if (iss >> valueBack)
                return valueBack;
            return defaultValue;
        }

        template<typename T>
        sf::String  ToString(const T& value)
        {
            std::ostringstream oss;
            oss << value;
            return oss.str();
        }

    protected:
        Utils();
        virtual ~Utils();
    private:
};

#endif // UTILS_HPP
