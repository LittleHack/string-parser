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





template<typename ArrayType>
class ArrayParser: public DataParser
{
public:
    ArrayParser(DataParser* parser, unsigned int size): \
        m_elmtParser(parser), m_arraySize(size) {}
    virtual ~ArrayParser()
    {
        if (m_elmtParser != NULL)
        {
            delete m_elmtParser;
        }
    }

    bool parse(std::string input)
    {
        m_dataStr = input;
        clean();
        m_validity = true;

        do
        {
            if (NULL == m_elmtParser)
            {
                clean();
                break;
            }

            if (false == splitData())
            {
                clean();
                break;
            }

            if (false == startParse())
            {
                clean();
                break;
            }
        }
        while (0);

        return m_validity;
    }

    bool splitData()
    {
        std::string arraySizeStr;
        std::string arrayStr;
        std::string::size_type pos1 = m_dataStr.find(":");
        if (std::string::npos == pos1)
        {
            return false;
        }

        arraySizeStr = m_dataStr.substr(0, pos1);
        arrayStr = m_dataStr.substr(pos1 + 1);

        IntParser parsedArraySize;
        if (false == parsedArraySize.parse(arraySizeStr) ||
            parsedArraySize.getData() != m_arraySize)
        {
            return false;
        }

        if (parsedArraySize.getData() != split(arrayStr, m_splitedData, ","))
        {
            return false;
        }

        return true;
    }
    bool startParse()
    {
        for (int dataIndex = 0; dataIndex < m_splitedData.size(); dataIndex++)
        {
            if (false == ((ElementParser<ArrayType>*)m_elmtParser)->parse(m_splitedData[dataIndex]))
            {
                return false;
            }

            m_arrayData.push_back(((ElementParser<ArrayType>*)m_elmtParser)->getData());
        }

        return true;
    }

    void setArraySize(unsigned int size)
    {
        m_arraySize = size;
    }

    std::string getDataStr()
    {
        int prasedArraySize = m_arrayData.size();
        if (prasedArraySize <= 0)
        {
            return "";
        }

        std::ostringstream stream;
        stream << prasedArraySize << ":";
        for (int arrayIndex = 0; arrayIndex < prasedArraySize; arrayIndex++)
        {
            stream << m_arrayData[arrayIndex] << ",";
        }

        return stream.str().substr(0, stream.str().size() - 1);
    }

protected:
    DataParser* m_elmtParser;
    std::vector<std::string> m_splitedData;
    std::vector<ArrayType> m_arrayData;
    unsigned int m_arraySize;

private:
    void clean()
    {
        m_splitedData.clear();
        m_arrayData.clear();
        m_validity = false;
    }

};

#define ARRAY_DATA_CONSTRUCTOR(className, arrayType, elementParser) \
    className(unsigned int size) \
        : ArrayParser<arrayType>(new elementParser(), size) {}

#define DEFINE_ARRAY_DATA_PARSER(className, arrayType, elementParser) \
    class className: public ArrayParser<arrayType> \
    { \
    public: \
        ARRAY_DATA_CONSTRUCTOR(className, arrayType, elementParser) \
    };

DEFINE_ARRAY_DATA_PARSER(IntArrayParser, int, IntParser)
DEFINE_ARRAY_DATA_PARSER(ShortArrayParser, short, ShortParser)
DEFINE_ARRAY_DATA_PARSER(StringArrayParser, std::string, StringParser)
DEFINE_ARRAY_DATA_PARSER(DoubleArrayParser, double, DoubleParser)
DEFINE_ARRAY_DATA_PARSER(FloatArrayParser, float, FloatParser)


#endif

