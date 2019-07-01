#ifndef _DATA_PARSER_H_
#define _DATA_PARSER_H_

#include "util.h"
#include "common.h"


#define INT_MAX   ((int)((~((unsigned int)0)) >> 1))
#define INT_MIN   (-(int)((~((unsigned int)0)) >> 1) - 1)
#define SHORT_MAX ((short)((~((unsigned short)0)) >> 1))
#define SHORT_MIN (-(short)((~((unsigned short)0)) >> 1) - 1)

// this class can parse one data of kind in DataType.
class DataParser
{
public:
    DataParser();
    virtual ~DataParser() {}
    bool getValidity();

protected:
    std::string m_dataStr;
    bool m_validity;

    // Following part need realization in child classes.
public:
    virtual bool parse(std::string input) = 0;
    virtual std::string getDataStr() = 0;

};

template<typename ElementType>
class ElementParser: public DataParser
{
public:
    ElementParser(): DataParser() {}

    bool parse(std::string input)
    {
        m_dataStr = input;
        clean();

        if (false == startParse())
        {
            return false;
        }

        m_validity = true;
        return true;
    }

    std::string getDataStr()
    {
        std::ostringstream stream;
        stream << m_elementData;
        return stream.str();
    }

    ElementType getData()
    {
        return m_elementData;
    }

protected:
    ElementType m_elementData;

private:
    void clean()
    {
        m_validity = false;
    }

    // Following part need realization in its child classes.
protected:
    virtual bool startParse() = 0;

};

#define ELEMENT_DATA_CONSTRUCTOR(className, elementType) \
    className() \
        : ElementParser<elementType>() {}

#define DEFINE_ELEMENT_DATA_PARSER(className, elementType) \
    class className: public ElementParser<elementType> \
    { \
    public: \
        ELEMENT_DATA_CONSTRUCTOR(className, elementType) \
    protected: \
        bool startParse(); \
    };

DEFINE_ELEMENT_DATA_PARSER(IntParser, int)
DEFINE_ELEMENT_DATA_PARSER(ShortParser, short)
DEFINE_ELEMENT_DATA_PARSER(StringParser, std::string)
DEFINE_ELEMENT_DATA_PARSER(DoubleParser, double)
DEFINE_ELEMENT_DATA_PARSER(FloatParser, float)




#endif

