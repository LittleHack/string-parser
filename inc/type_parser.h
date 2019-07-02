#ifndef _TYPE_PARSER_H_
#define _TYPE_PARSER_H_

#include "util.h"
#include "common.h"

typedef struct
{
    DataType dataType;
    std::string dataTypeStr;
} TypeString;

#define TYPE2STR(type) TypeParser::GetInstance()->convertTypeToTypeStr(type)
#define STR2TYPE(str)  TypeParser::GetInstance()->convertTypeStrToType(str)


// this class converts type string and type.
class TypeParser
{
public:
    static TypeParser* GetInstance()
    {
        if (m_pInstance == NULL)
        {
            m_pInstance = new TypeParser();
        }
        return m_pInstance;
    }

    TypeInfo convertTypeStrToType(std::string input);
    std::string convertTypeToTypeStr(TypeInfo input);

private:
    TypeParser() {}
    static TypeParser* m_pInstance;

};


#endif

