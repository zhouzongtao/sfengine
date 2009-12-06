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

int GetValueFromHex(char h)
{
    if (h >= '0' && h <= '9')
        return h - '0';
    if (h >= 'a' && h <= 'f')
        return h - 51;
    if (h >= 'A' && h <= 'F')
        return h - 55;
    return 0;
}

sf::Color       Utils::GetColorFromString(const std::string& colorStr, const sf::Color& defaultValue)
{
    if (colorStr.empty())
        return defaultValue;

    sf::Color valueBack = defaultValue;

    // hexadecimal
    if (colorStr[0] == '#')
    {
        if (colorStr.size() == 7)
        {
            valueBack.r = GetValueFromHex(colorStr[1]) * 16 + GetValueFromHex(colorStr[2]);
            valueBack.g = GetValueFromHex(colorStr[3]) * 16 + GetValueFromHex(colorStr[4]);
            valueBack.b = GetValueFromHex(colorStr[5]) * 16 + GetValueFromHex(colorStr[6]);
        }
        else if (colorStr.size() == 9)
        {
            valueBack.r = GetValueFromHex(colorStr[1]) * 16 + GetValueFromHex(colorStr[2]);
            valueBack.g = GetValueFromHex(colorStr[3]) * 16 + GetValueFromHex(colorStr[4]);
            valueBack.b = GetValueFromHex(colorStr[5]) * 16 + GetValueFromHex(colorStr[6]);
            valueBack.a = GetValueFromHex(colorStr[7]) * 16 + GetValueFromHex(colorStr[8]);
        }
    }
    return valueBack;
}

bool            Utils::GetBooleanFromString(const std::string& boolStr, bool defaultValue)
{
    std::string lowerCase = boolStr;
    std::transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(), my_tolower());

    if (lowerCase == "true" || lowerCase == "1" || lowerCase == "yes")
        return true;
    else if (lowerCase == "false" || lowerCase == "0" || lowerCase == "no")
        return false;
    return defaultValue;
}

#include <iostream>

sf::Vector2f    Utils::GetVectorFromString(const std::string& boolStr, const sf::Vector2f& defaultValue)
{
    int posSep = boolStr.find(';', 0);
    sf::Vector2f valueBack;

    valueBack.x = GetFromString(boolStr.substr(0, posSep), defaultValue.x);
    valueBack.y = GetFromString(boolStr.substr(posSep + 1, boolStr.size() - posSep - 1), defaultValue.y);

    return valueBack;
}
