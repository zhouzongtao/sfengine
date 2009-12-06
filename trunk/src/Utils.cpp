#include "Utils.hpp"

#include <cctype>
#include <algorithm>

template<>
Utils*  Singleton<Utils>::myInstance = 0;

Utils::Utils()
{
    //ctor
}

Utils::~Utils()
{
    //dtor
}

struct my_tolower
{
    char operator()(char c) const
    {
        return std::tolower(static_cast<unsigned char>(c));
    }
};


sf::Color       Utils::GetColorFromString(const sf::String& colorStr, const sf::Color& defaultValue)
{
    return defaultValue;
}

bool            Utils::GetBooleanFromString(const sf::String& boolStr, bool defaultValue)
{
    std::string lowerCase = boolStr.ToAnsiString();
    std::transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(), my_tolower());

    if (lowerCase == "true" || lowerCase == "1" || lowerCase == "yes")
        return true;
    else if (lowerCase == "false" || lowerCase == "0" || lowerCase == "no")
        return false;
    return defaultValue;
}

sf::Vector2f    Utils::GetVectorFromString(const sf::String& boolStr, const sf::Vector2f& defaultValue)
{
    return defaultValue;
}
