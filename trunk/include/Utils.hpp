#ifndef UTILS_HPP
#define UTILS_HPP

#include "Singleton.hpp"
#include <sstream>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

class Utils : public Singleton<Utils>
{
    public:
        friend Utils*   Singleton<Utils>::Get();
        friend void     Singleton<Utils>::Kill();


        sf::Color       GetColorFromString(const std::string& colorStr, const sf::Color& defaultValue);
        bool            GetBooleanFromString(const std::string& boolStr, bool defaultValue);
        sf::Vector2f    GetVectorFromString(const std::string& boolStr, const sf::Vector2f& defaultValue);

        template<typename T>
        T   GetFromString(const std::string& value, const T& defaultValue)
        {
            T valueBack;
            std::istringstream iss(value);

            if (iss >> valueBack)
                return valueBack;
            return defaultValue;
        }

        template<typename T>
        std::string ToString(const T& value)
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
