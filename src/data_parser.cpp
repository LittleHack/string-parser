#include "data_parser.h"

DataParser::DataParser()
{
    m_dataStr = "";
    m_validity = false;
}

bool DataParser::getValidity()
{
    return m_validity;
}

bool IntParser::startParse()
{
    const char* str = m_dataStr.c_str();
    char* tmp = NULL;
    bool ret = true;
    m_elementData = 0;

    do
    {
        long longData = strtol(str, &tmp, 10);
        if (errno != 0 || tmp != str + strlen(str) || *str == ' ')
        {
            ret = false;
            break;
        }

        if (longData > INT_MAX || longData < INT_MIN)
        {
            ret = false;
            break;
        }

        m_elementData = longData;
    }
    while (0);

    return ret;
}

bool ShortParser::startParse()
{
    const char* str = m_dataStr.c_str();
    char* tmp = NULL;
    bool ret = true;
    m_elementData = 0;

    do
    {
        long longData = strtol(str, &tmp, 10);
        if (errno != 0 || tmp != str + strlen(str) || *str == ' ')
        {
            ret = false;
            break;
        }

        if (longData > SHORT_MAX || longData < SHORT_MIN)
        {
            ret = false;
            break;
        }

        m_elementData = longData;
    }
    while (0);

    return ret;
}

bool StringParser::startParse()
{
    m_elementData = m_dataStr;
    return true;
}

bool DoubleParser::startParse()
{
    const char* str = m_dataStr.c_str();
    char* tmp = NULL;

    double doubleData = strtod(str, &tmp);
    if (errno != 0 || tmp != str + strlen(str) || *str == ' ')
    {
        m_elementData = 0;
        return false;
    }
    else
    {
        m_elementData = doubleData;
        return true;
    }
}

bool FloatParser::startParse()
{
    const char* str = m_dataStr.c_str();
    char* tmp = NULL;
    bool ret = true;
    m_elementData = 0;

    float floatData = strtof(str, &tmp);
    if (errno != 0 || tmp != str + strlen(str) || *str == ' ')
    {
        m_elementData = 0;
        return false;
    }
    else
    {
        m_elementData = floatData;
        return true;
    }
}



